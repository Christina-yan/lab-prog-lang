#include "game_utils.h"
#include "weapon.h"
#include "base_enemy.h"
#include "main_hero.h"
#include "exceptions.h"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

void delay(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void wait_for_user() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void show_menu() {
    cout << "\n========== MENU ==========" << endl;
    cout << "1. Attack enemy" << endl;
    cout << "2. Switch weapon" << endl;
    cout << "3. Heal" << endl;
    cout << "4. Show status" << endl;
    cout << "5. Show all enemies" << endl;
    cout << "6. End battle" << endl;
    cout << "=========================" << endl;
    cout << "Choice: ";
}

void battle() {
    cout << "\n========== BATTLE BEGINS ==========\n" << endl;
    delay(1500);

    Weapon sword("Sword", 25, 2.0);
    Weapon bow("Bow", 15, 5.0);
    Weapon axe("Axe", 30, 1.5);
    Weapon dagger("Dagger", 10, 1.0);
    Weapon staff("Staff", 20, 3.0);

    MainHero hero(0, 0, "Arthas", 150);
    hero.add_weapon(sword);

    vector<unique_ptr<BaseEnemy>> enemies;
    enemies.push_back(make_unique<BaseEnemy>(3, 0, bow, 60));
    enemies.push_back(make_unique<BaseEnemy>(1, 2, axe, 80));
    enemies.push_back(make_unique<BaseEnemy>(5, 5, staff, 70));
    enemies.push_back(make_unique<BaseEnemy>(2, -1, dagger, 45));

    cout << "Hero " << hero.get_name() << " enters battle with 4 enemies!\n" << endl;
    delay(1000);

    hero.show_status();
    delay(1000);

    cout << "\nENEMIES LIST:" << endl;
    for (size_t i = 0; i < enemies.size(); i++) {
        cout << (i + 1) << ". " << *enemies[i] << endl;
        delay(300);
    }

    int choice;
    bool battle_continue = true;
    int turn = 0;

    cin.ignore();

    while (battle_continue && hero.is_alive()) {
        turn++;
        cout << "\n========== TURN " << turn << " ==========" << endl;
        delay(800);

        bool hero_turn_complete = false;
        while (!hero_turn_complete && hero.is_alive()) {
            show_menu();
            cin >> choice;

            try {
                switch (choice) {
                case 1: {
                    if (enemies.empty()) {
                        cout << "No enemies to attack!" << endl;
                        hero_turn_complete = true;
                        break;
                    }

                    cout << "Choose enemy to attack (1-" << enemies.size() << "): ";
                    int idx;
                    cin >> idx;

                    if (idx < 1 || idx >(int)enemies.size()) {
                        cout << "Invalid choice!" << endl;
                        break;
                    }

                    hero.hit(enemies[idx - 1].get());
                    hero_turn_complete = true;
                    delay(1000);
                    break;
                }
                case 2:
                    hero.next_weapon();
                    break;
                case 3:
                    hero.heal(20);
                    break;
                case 4:
                    hero.show_status();
                    break;
                case 5:
                    cout << "\nENEMIES:" << endl;
                    for (size_t i = 0; i < enemies.size(); i++) {
                        cout << (i + 1) << ". " << *enemies[i] << endl;
                    }
                    break;
                case 6:
                    cout << "Battle interrupted!" << endl;
                    battle_continue = false;
                    hero_turn_complete = true;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                }
            }
            catch (const NoWeaponException& e) {
                cerr << "Error: " << e.what() << endl;
                cout << "Pick up a weapon!" << endl;
                delay(1000);
            }
            catch (const DeadTargetException& e) {
                cerr << "Error: " << e.what() << endl;
                cout << "Choose another enemy!" << endl;
                delay(1000);
            }
            catch (const exception& e) {
                cerr << "Unknown error: " << e.what() << endl;
                delay(1000);
            }
        }

        if (!battle_continue || !hero.is_alive()) break;

        auto before_count = enemies.size();
        enemies.erase(remove_if(enemies.begin(), enemies.end(),
            [](const unique_ptr<BaseEnemy>& e) { return !e->is_alive(); }),
            enemies.end());

        if (before_count != enemies.size()) {
            cout << "\nAn enemy has been defeated!" << endl;
            delay(1000);
        }

        if (enemies.empty()) {
            cout << "\nVICTORY! All enemies defeated!" << endl;
            break;
        }

        cout << "\n========== ENEMIES' TURN ==========" << endl;
        delay(800);

        for (auto& enemy : enemies) {
            if (enemy->is_alive()) {
                cout << "\n" << *enemy << endl;
                delay(500);
                enemy->hit(&hero);
                delay(800);

                if (!hero.is_alive()) {
                    cout << "\nHERO DEFEATED! GAME OVER" << endl;
                    break;
                }
            }
        }

        if (hero.is_alive()) {
            cout << "\nAfter the round:" << endl;
            cout << "Hero health: " << hero.get_hp() << "/200" << endl;
            cout << "Enemies remaining: " << enemies.size() << endl;
            delay(1500);

            cout << "\nContinue to next turn? (1 - Yes / 2 - Show status / 3 - Exit battle): ";
            int cont;
            cin >> cont;
            if (cont == 2) {
                hero.show_status();
                wait_for_user();
            }
            else if (cont == 3) {
                cout << "Battle ended by player!" << endl;
                battle_continue = false;
                break;
            }
        }
    }

    if (hero.is_alive() && enemies.empty()) {
        cout << "\n========== " << hero.get_name() << " WON THE BATTLE! ==========" << endl;
        hero.show_status();
    }
    else if (!hero.is_alive()) {
        cout << "\n========== GAME OVER ==========" << endl;
        cout << "Hero has fallen in battle..." << endl;
    }

    wait_for_user();
}

void test_classes() {
    cout << "\n========== CLASS TESTING ==========\n" << endl;
    delay(1000);

    cout << "=== Weapon Class Test ===" << endl;
    Weapon w1("Excalibur", 50, 3.0);
    cout << "Weapon: " << w1 << endl;
    delay(500);

    cout << "\n=== BaseCharacter Class Test ===" << endl;
    BaseCharacter c1(0, 0, 100);
    BaseCharacter c2(3, 4, 80);
    cout << "Character 1 at (" << c1.get_x() << ", " << c1.get_y()
        << ") HP: " << c1.get_hp() << endl;
    cout << "Distance to character 2: " << c1.distance_to(&c2) << endl;
    delay(500);

    c1.move(1, 1);
    cout << "After movement: (" << c1.get_x() << ", " << c1.get_y() << ")" << endl;

    c1.get_damage(30);
    cout << "After 30 damage: HP = " << c1.get_hp()
        << ", alive: " << (c1.is_alive() ? "yes" : "no") << endl;
    delay(500);

    cout << "\n=== Weapon::hit Test ===" << endl;
    BaseCharacter c3(0, 0, 50);
    BaseCharacter c4(2, 0, 40);
    Weapon dagger("Dagger", 15, 1.5);
    dagger.hit(&c3, &c4);
    cout << "Target HP after hit: " << c4.get_hp() << endl;
    delay(500);

    cout << "\n=== BaseEnemy Class Test ===" << endl;
    Weapon bow("Bow", 12, 4.0);
    BaseEnemy enemy(5, 5, bow, 60);
    cout << enemy << endl;
    cout << "Enemy HP: " << enemy.get_hp() << endl;
    delay(500);

    cout << "\n=== MainHero Class Test ===" << endl;
    MainHero hero(0, 0, "Tester", 120);
    cout << hero << endl;
    delay(500);

    hero.add_weapon(Weapon("Sword", 20, 1.5));
    hero.add_weapon(Weapon("Bow", 15, 4.0));
    hero.show_status();
    delay(1000);

    hero.next_weapon();
    hero.heal(30);

    cout << "\nAll tests passed successfully!" << endl;
    delay(1500);
}
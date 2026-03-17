//Реализуйте следующую иерархию классов :
//Animal – базовый класс - интерфейс с методами breathe() и eat().
//Fish – наследник класса Animal с дополнительным методом swim().
//Bird – наследник класса Animal с дополнительным методом lay_eggs().
//FlyingBird – наследник класса Bird с дополнительным методом fly().
//
//Сами методы breathe, eat, swim, lay_eggs и fly должны только выводить текст с соответствующим действием на экран.
#include <iostream>
#include "animal.h"
#include "fish.h"
#include "bird.h"
#include "FlyingBird.h"

using namespace std;
int main()
{
    cout << "take the animal: " << endl
        << "0 - fish; 1 - bird; " << endl
        << "2 - flyiang bird " << endl;

    Animal* a = nullptr;

    int number;
    cin >> number;

    switch (number) {
    case 0:
        a = new Fish();
        break;
    case 1:
        a = new Bird();
        break;
    case 2:
        a = new FlyingBird();
        break;
    default:
        break;
    }

    cout << a->to_string() << endl;

}


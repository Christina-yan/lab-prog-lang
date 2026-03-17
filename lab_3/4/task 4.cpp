#include <iostream>
#include "summator.h"
#include "square_summator.h"
#include "cube_summator.h"

using namespace std;

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    cout << "\n=== EARLY BINDING (Static binding) ===" << endl;
    
    
    Summator basic_summator;
    SquareSummator square_summator;
    CubeSummator cube_summator;

    cout << "Summator result:       " << basic_summator.sum(N) << endl;
    cout << "SquareSummator result: " << square_summator.sum(N) << endl;
    cout << "CubeSummator result:   " << cube_summator.sum(N) << endl;


    cout << "\n=== LATE BINDING (Dynamic binding) ===" << endl;
    
    

    Summator* ptr1 = new Summator();
    Summator* ptr2 = new SquareSummator();
    Summator* ptr3 = new CubeSummator();

    cout << "Sum via pointer:       " << ptr1->sum(N) << endl;
    cout << "Square sum via pointer: " << ptr2->sum(N) << endl;
    cout << "Cube sum via pointer:   " << ptr3->sum(N) << endl;

    
    delete ptr1;
    delete ptr2;
    delete ptr3;


    cout << "\n=== VERIFICATION USING MATH FORMULAS ===" << endl;
    long long n_ll = N; 

    long long formula_sum = n_ll * (n_ll + 1) / 2;
    long long formula_square = n_ll * (n_ll + 1) * (2 * n_ll + 1) / 6;
    long long formula_cube = formula_sum * formula_sum; 

    cout << "Formula Sum:           " << formula_sum << endl;
    cout << "Formula Square Sum:    " << formula_square << endl;
    cout << "Formula Cube Sum:      " << formula_cube << endl;

    return 0;
}
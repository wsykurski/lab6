//
// Created by wojtek on 11.12.16.
//
#include "zad26.h"
using namespace std;

void zad26() {
    const int size = 6;
    cout << "Zadanie 26" << endl;
    cout << "Inicjacja trójkąta wymiarze " << size << ":" << endl;
    int ** triangle = pascal(size);
    print_pascal(triangle, size);
    usun(triangle, size);
    cout << "Trójkąt po usunięciu: " << endl << *triangle << endl;
    cout << endl;
}

int **pascal(int n) {
    n = n + 2;
    int ** result = new int*[n];
    for (int i = 1; i <= n; ++i) {
        result[i] = new int[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if(j == 0 || j == i - 1) result[i][j] = 1;
            else
            {
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
    }
    return result;
}

void usun(int **pascal, int n) {
    n = n +2;
    for (int i = 0; i < n; ++i) {
        delete[] pascal[i];
    }
    delete[] pascal;
}

void print_pascal(int **pascal, int n) {
    n = n + 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j)
                cout << pascal[i][j] << ", ";
        cout << endl;
    }
}




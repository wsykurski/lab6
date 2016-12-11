//
// Created by wojtek on 11.12.16.
//

#include "zad25.h"

int * increase_table(int *tab, int &old_size)
{
    int * result = new int [old_size * 2];
    memcpy(result, tab, old_size * sizeof(int));
    old_size = old_size * 2;
    return result;
}

int *dzielniki(int n)
{
    int _temp_size = 3;
    int count = 0;
    int *result = new int[_temp_size];
    for (int i = 1; i < n; ++i) {
        if ( n % i == 0)
        {
            if(count >= _temp_size - 1)
            {
                result = increase_table(result, _temp_size);
            }
            result[++count] = i;
        }
    }
    result[0] = count;
    return result;
}

int *parzyste(int *tab, int n)
{
    int _temp_size = 3;
    int * result = new int[_temp_size];
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if(tab[i] % 2 == 0)
        {
            if(count >= _temp_size - 1)
            {
                result = increase_table(result, _temp_size);
            }
            result[++count] = tab[i];
        }
    }
    result[0] = count;
    return result;
}

int **test(int *tab, int n) {
    int **result = new int*[2] ;
    result[0] = dzielniki(n);
    result[1] = parzyste(tab, n);
    return result;
}

void zad25() {
    int tab[] = {1, 2, 3, 5, 6, 9, 10, 12, 14};
    int **result = test(tab, 9);
    cout << "Zad25" << endl;
    cout << "Dzielniki:" << endl;
    for (int i = 0; i <= result[0][0]; ++i) {
        cout << result[0][i] << ", ";
    }
    cout << endl << "Liczby parzyste:" << endl;
    for (int i = 0; i <= result[1][0]; ++i) {
        cout << result[1][i] << ", ";
    }
}

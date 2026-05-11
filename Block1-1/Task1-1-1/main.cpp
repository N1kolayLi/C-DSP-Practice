#include <iostream>
#include <windows.h>
using namespace std;
//Требуется создать набор функций.

/*Дана последовательность вещественных чисел произвольной длины.
 * Последовательность хранится в памяти как статический массив.
 * Размер последовательности заранее неизвестен и передается в функции как параметр.*/

void func_arr(){
    int n;
    cout << "Введите количество элементов массива: ";
    scanf("%d", &n);

    double arr[n];

    for(int i = 0; i < n; i++) {
        cout << "Элемент " << i << " = ";
        scanf("%lf", &arr[i]);
    }

    cout << "\nВаш массив:" << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    func_arr();
}
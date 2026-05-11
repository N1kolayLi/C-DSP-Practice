#include <iostream>
#include <windows.h>
using namespace std;
//Требуется создать набор функций.

/*Дана последовательность вещественных чисел произвольной длины.
 * Последовательность хранится в памяти как статический массив.
 * Размер последовательности заранее неизвестен и передается в функции как параметр.*/



int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    //Массив
    int n;
    cout<<"Введите количество элементов массива"<<endl;
    scanf("%d", &n);

    double arr[n];

        for(int i = 0; i < n; i++){
            cout<<"Эллемент " << i << " = " <<endl;
            scanf("%lf", &arr[i]);
        }
        for(int i = 0; i < n; i++){
            cout<<arr[i]<<" "<<endl;
        }

}
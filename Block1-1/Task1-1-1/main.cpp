#include <iostream>
#include <windows.h>
using namespace std;
#define MAX_SIZE 100
//Требуется создать набор функций.
// привет
/*Дана последовательность вещественных чисел произвольной длины.
 * Последовательность хранится в памяти как статический массив.
 * Размер последовательности заранее неизвестен и передается в функции как параметр.*/

int size = 0;
void func_arr(){
    int n;
    cout << "Введите количество элементов массива: ";
    scanf("%d", &n);
    size = n;
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

//Функция поиска локальных экстремумов
//Найдите все локальные минимумы и максимумы в последовательности.
// Локальный экстремум — это элемент, который больше (для максимума)
// или меньше (для минимума) обоих своих соседей.
// Крайние элементы последовательности (первый и последний) экстремумами не считаются.
void find_local_extr(const double *arr, int size){
    cout<<size<<endl;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double my_array[MAX_SIZE];

    func_arr();
    if (size > 0) {
        find_local_extr(my_array, size);
    }
return 0;
}
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MAX_SIZE 100
//Требуется создать набор функций.
/*Дана последовательность вещественных чисел произвольной длины.
 * Последовательность хранится в памяти как статический массив.
 * Размер последовательности заранее неизвестен и передается в функции как параметр.*/

int size = 0;
void func_arr(double* arr){
    int n;
    cout << "Введите количество элементов массива: ";
    scanf("%d", &n);
    size = n;

    srand(time(NULL));

    for(int i = 0; i < n; i++) {
        arr[i] = (rand() % 201) - 100;
    }

    cout << "\nСгенерированный массив:" << endl;
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
    if (size < 3) {
        cout << "Массив должен содержать больше 3-х элементов"<< endl;
        return;
    }
    for (int i = 1; i < size-1; i++){
        if (arr[i] > arr[i-1] && arr[i] > arr[i+1]){
            cout<<"Локальный максимум: "<<arr[i]<<endl;
            cout<<"Соседи:"<<arr[i-1]<<", "<<arr[i+1]<<endl;
        }
    }
    for (int i = 1; i < size-1; i++){
        if (arr[i] < arr[i-1] && arr[i] < arr[i+1]){
            cout<<"Локальный минимум: "<<arr[i]<<endl;
            cout<<"Соседи:"<<arr[i-1]<<", "<<arr[i+1]<<endl;
        }
    }
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double my_array[MAX_SIZE];

    func_arr(my_array);
    if (size > 3) {
        find_local_extr(my_array, size);
    }
return 0;
}
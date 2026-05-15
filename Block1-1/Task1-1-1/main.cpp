#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MAX_SIZE 100
#define MAX_SHIFT 100
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
//Функция нормализации последовательности
//Преобразуйте последовательность таким образом,
// чтобы все ее значения оказались в диапазоне от 0 до 1.
// Для этого используйте формулу: normalized = (x - min) / (max - min),
// где min и max — минимальное и максимальное значения исходной последовательности.
// Исходная последовательность должна остаться неизменной,
// результат запишите в новый массив.

void normalize(double *arr, double *norm_arr, int size){
    if (size <= 1) {
        cout << "Недостаточно элементов" << endl;
        return;
    }

    double min_val = arr[0];
    double max_val = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) min_val = arr[i];
        if (arr[i] > max_val) max_val = arr[i];
    }

    if (max_val == min_val) {
        cout << "Все элементы одинаковые, нормализация невозможна" << endl;
        return;
    }
    for (int i = 0; i < size; i++){
        norm_arr[i] = (arr[i] - min_val) / (max_val - min_val);
    }
    cout << "\nНормализованный массив:" << endl;
    for (int i = 0; i < size; i++) {
        cout << norm_arr[i] << " ";
    }
    cout << endl;
}

//Функция циклического сдвига
//Выполните циклический переход последовательности вправо на K позиций (K задается параметром).
// При изменении элементов, выходящих за пределы массива, перемещаются в начало.
// Предложение должно изменить исходный массив, а не создавать реставрацию.
void cycle_moving(double *arr, int size, int k){
    if (size < 2 || k == 0) {
        return;
    }
    k %= size;
    double temp[MAX_SHIFT];
        if (k > MAX_SHIFT) {
            cerr << "Ошибка: k > MAX_SHIFT (" << MAX_SHIFT << ")" << endl;
            return;
        }
        for(int i = 0; i < k; i++){
            temp[i] = arr[size - k + i];
        }
        for (int i = size - 1; i >= k; i--){
            arr[i] = arr[i-k];
        }
        for (int i = 0; i < k; i++){
            arr[i] = temp[i];
        }
    cout<<"Массив, сдвинутый на "<<k<<" позиций вправо"<<endl;
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    }
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double my_array[MAX_SIZE];

    func_arr(my_array);
    if (size > 3) {
        find_local_extr(my_array, size);
    }
    double *norm_arr = new double[size];
    normalize(my_array, norm_arr, size);
    delete[] norm_arr;
    cycle_moving(my_array, size, 5);
    return 0;
}

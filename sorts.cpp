#include <iostream>
#include "sorts.h"

using namespace std;

#include <iostream>

using namespace std;

static void merge(int* ar, int total_size, int left_size)
{
    int* p_massiv_m = new int[left_size];
    int* p_massiv_n = new int[total_size - left_size];

    for (int i = 0; i < left_size; i++)
    {
        p_massiv_m[i] = ar[i];
    }

    int j = 0;
    for (int i = left_size; i < total_size; i++)
    {
        p_massiv_n[j] = ar[i];
        j++;

    }


    int i = 0;
    j = 0;
    int k = 0;

    while (i < left_size && j < total_size - left_size)
    {
        if ((i == left_size - 1) and (j == (total_size - left_size - 1)))
        {
            if (p_massiv_m[i] <= p_massiv_n[j])
            {
                ar[k] = p_massiv_m[i];
                ar[k + 1] = p_massiv_n[i];
                i++;
            }
            else
            {
                ar[k] = p_massiv_n[j];
                ar[k + 1] = p_massiv_m[j];
                j++;
            }

        }
        else
        {
            if (p_massiv_m[i] <= p_massiv_n[j])
            {
                ar[k] = p_massiv_m[i];
                i++;
            }
            else
            {
                ar[k] = p_massiv_n[j];
                j++;
            }
        }
        k++;
    }

    delete[] p_massiv_m;
    delete[] p_massiv_n;

    return;
}

void MergeSort(int* ar, int size) 
{
    if (size < 2) {
        return;
    }

    int mid = size / 2;

   
    MergeSort(ar, mid);
    MergeSort(ar + mid, size - mid);

    merge(ar, size, mid);

    return;
}

void BubbleSort(int* ar, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = 0; j < size - i - 1; ++j)
        {
            if (ar[j] > ar[j + 1])
            {
                // Обмен элементов
                int c = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = c;
            }
        }
    }

}

void  QuickSort(int* ar, int size)
{

    int i = 0;
    int j = size - 1;

    int midle_elem = ar[size / 2];


    do {

        //В левой части массива оставляем элементы, которые меньше центрального
        while (ar[i] < midle_elem)
        {
            i++;
        }
        //В правой части оставляем элементы, которые больше центрального
        while (ar[j] > midle_elem)
        {
            j--;
        }

        //Меняем элементы местами
        if (i <= j)
        {

            int tmp = ar[i];
            ar[i] = ar[j];
            ar[j] = tmp;

            i++;
            j--;
   
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0)
    {
        //"Левый кусок"

        QuickSort(ar, j + 1);
    }

    if (i < size)
    {
        //"Првый кусок"
        
        QuickSort(&ar[i], size - i);
    }
}

void InsertionSort(int* arr, int n) 
{
    int i, key, j;
    for (i = 1; i < n; ++i) 
    {
        key = arr[i];
        j = i - 1;

        //Перемещаем элементы массива , которые больше чем key, на одну позицию вперёд 
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void SelectionSort(int* arr, int n) 
{
    for (int i = 0; i < n - 1; ++i) 
    {
        // Находим индекс минимального элемента в оставшейся части массива
        int min_index = i;
        for (int j = i + 1; j < n; ++j) 
        {
            if (arr[j] < arr[min_index]) 
            {
                min_index = j;
            }
        }

        // Меняем местами текущий элемент с минимальным элементом
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}
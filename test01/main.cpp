#include <iostream>
//#include <algorithm>
//#include <string>
//#include "student.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {

    for (int i = 0; i < n; i++) {
        // 寻找[i, n)区间里的最小值
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
//      寻找元素arr[i]合适的插入位置
        T e = arr[i];
        int j;// j保存元素e应该插入的位置
        for (j = i; j > 0 && e < arr[j - 1]; j--)
            arr[j] = arr[j - 1];
        arr[j] = e;
    }
}
// 作业是：实现冒泡排序，以及了解希尔排序


// 归并排序需要多使用n的空间，是一种用空间换取时间的方法
// 使用3个索引，对数组位置进行追踪

// 递归使用归并排序，对arr[l...r)的范围进行排序

template<typename T>
void __merge(T arr[], int l, int mid, int r) {
    T aux[r - l + 1];
    for (int i = l; i <= r; i++)
        aux[i - l] = arr[i];
    int i = l, j = mid + 1;
    for (int k = l; k <= r; k++) {

        if (i > mid) {
            arr[k] = aux[j - l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i - l];
            i++;
        } else if (aux[i - l] < aux[j - l]) {
            arr[k] = aux[i - l];
            i++;
        } else {
            arr[k] = aux[j - l];
            j++;
        }
    }
}

template<typename T>
void __mergeSort(T arr[], int l, int r) {

    if (l >= r)
        return;
// 下面这一行代码具有隐含的危险，有可能发生溢出的错误
    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);
    __merge(arr, l, mid, r);

}

template<typename T>
void mergeSort(T arr[], int n) {

    __mergeSort(arr, 0, n - 1);
}


int main() {

    int n = 50000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
//    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);


    int *arr3 = SortTestHelper::generateNearlyOrderedArray(n, 10);
    int *arr4 = SortTestHelper::copyIntArray(arr3, n);
//    SortTestHelper::testSort("Selection Sort", selectionSort, arr3, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr3, n);
    SortTestHelper::testSort("Merge Sort", mergeSort, arr4, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;

    return 0;
}
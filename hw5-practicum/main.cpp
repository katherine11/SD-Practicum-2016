#include <iostream>
#include "MergeSort.cpp"
#include "HeapSort.cpp"

const int SIZE = 50;

void printArray(int *arr, int size)
{
    for (int index = 0; index < size; ++index)
    {
        std::cout << arr[index] << " ";
    }

    std::cout<< std::endl;
}


int main() {
    int size = 9;
    int array[SIZE] = {2,-4,-26,4,3,9,17,14,-3};

    int *sortedByMerge = mergeSort(array,size);
    std::cout << "Sorted using merge sort: ";
    printArray(sortedByMerge,size);

    heapSort(array, size);
    std::cout << "Sorted using heap sort: ";
    printArray(array,size);


    return 0;
}
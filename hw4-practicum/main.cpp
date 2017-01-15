#include <iostream>
#include "InsertionSort.cpp"
#include "QuickSort.cpp"

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
    int array[] = {2,-4,-6,4,3,9,17,14,-3};

    int *sortedByInsertion = insertionSort(array,size);
    std::cout << "Sorted using insertion sort: ";
    printArray(sortedByInsertion,size);

    quickSort(array,0,size-1);
    std::cout << "Sorted using quick sort: ";
    printArray(array,size);

    return 0;
}
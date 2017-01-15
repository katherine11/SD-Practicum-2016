
#include <algorithm>

template<typename T>
T partition(T arr[], int start, int end)
{
    int pivot = arr[end], pivotIndex = start;

    for (int index = start; index < end; ++index) {

        if(arr[index] <= pivot){
            std::swap(arr[pivotIndex++], arr[index]);
        }
    }

    std::swap(arr[pivotIndex], arr[end]);

    return pivotIndex;
}

template <typename  T>
void  quickSort(T *arr, int start, int end)
{
    if(start < end) {
        T pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }

}

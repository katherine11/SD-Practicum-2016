
template <typename T>
void swap(T &first, T &second)
{
    T temp = first;
    first = second;
    second = temp;
}

template <typename T>
T* insertionSort(T *arr, int size)
{
    int backIndex;

    for (int index = 0; index < size; index++){
        backIndex = index;

        while (backIndex > 0 && arr[backIndex] < arr[backIndex-1]){
            swap(arr[backIndex], arr[backIndex - 1]);
            backIndex--;
        }
    }

    return arr;
}



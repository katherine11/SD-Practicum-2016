
template <typename T>
void swap(T &first, T &second)
{
    T temp = first;
    first = second;
    second = temp;
}

template <typename T>
void shiftRight(T *arr, int low, int high) {

    int root = low;
    int leftChild;
    do
    {
        leftChild = root*2+1;
        int rightChild = leftChild +1;
        int swapIndex = root;

        if(leftChild > high)
        {
            break;
        }
        if(arr[swapIndex] < arr[leftChild])
        {
            swapIndex = leftChild;
        }
        if(rightChild <= high && arr[swapIndex] < arr[rightChild])
        {
            swapIndex = rightChild;
        }
        if(swapIndex != root)
        {
            swap(arr[root],arr[swapIndex]);
            root = swapIndex;
        }
        else
        {
            break;
        }

    }
    while(leftChild <= high);
}

template <typename T>
void heapify(T *arr, int low, int high)
{
    int midIndex = (high -low - 1)/2;

    while(midIndex >= 0)
    {
        shiftRight(arr, midIndex,high);
        --midIndex;
    }
}

template <typename T>
void heapSort(T *arr, int size)
{
    heapify(arr,0,size-1);
    int high = size - 1;
    while(high > 0)
    {
        swap(arr[high], arr[0]);
        --high;
        shiftRight(arr,0,high);
    }
    return;
}


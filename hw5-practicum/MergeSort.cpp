
template <typename T>
T* merge(T *left, T *right, int s1, int s2)
{
    int leftIndex = 0, rightIndex = 0, resultIndex = 0;
    int leftSize = s1;
    int rightSize = s2;
    T* result = new T[leftSize + rightSize];
    while(leftIndex != leftSize && rightIndex != rightSize)
    {
        if(left[leftIndex] < right[rightIndex])
        {
            result[resultIndex++] = left[leftIndex++];
        }
        else
        {
            result[resultIndex++] = right[rightIndex++];
        }

    }

    while(leftIndex != leftSize)
    {
        result[resultIndex++] = left[leftIndex++];
    }

    while(rightIndex != rightSize)
    {
        result[resultIndex++] = right[rightIndex++];
    }

    return result;

}

template <typename T>
T* mergeSort(T* array, int size)
{
    if(size < 2){
        return array;
    }

    int leftSize = size - size/2, rightSize = size/2;
    T* left = new T[leftSize];
    T* right = new T[rightSize];

    for (int index = 0; index < leftSize; ++index) {
        left[index] = array[index];
    }


    int firstRightElementIndex = leftSize;
    for (int index = 0; index < rightSize; ++index) {
        right[index] = array[firstRightElementIndex++];
    }

    T* sortedLeft = mergeSort(left,leftSize);
    T* sortedRight = mergeSort(right,rightSize);

     return merge(sortedLeft,sortedRight,leftSize,rightSize);
}




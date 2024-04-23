#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void index_deletion(int arr[], int capacity, int size, int index)
{
    if (index > capacity)
    {
        return -1;
    }

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i+ 1];
    }
}

int main()
{
    int arr[10] = {2, 4, 7, 19, 35, 57, 68};
    display(arr, 7);
    int size = 7, capacity = 10;
    int index = 2;
    index_deletion(arr,10,7,3);
    size = size -1;
    display(arr,size);

    return 0;
}
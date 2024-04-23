#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void index_insertion(int arr[], int capacity, int size, int element, int index)
{
    if (size >= capacity)
    {
        printf("insertion cant be done");
        return -1;
    }

    else
    {
        for (int i = (size - 1); i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;

        size = size + 1;
        display(arr, size);
        printf("insertion  done successfully");
    }
}

int main()
{
    int arr[10] = {7, 10, 23, 45, 67, 89};
    display(arr, 6);
    int capacity = 10, size = 6;
    int element = 50, index = 6;

    index_insertion(arr, 10, 6, 50, 7);

    return 0;
}
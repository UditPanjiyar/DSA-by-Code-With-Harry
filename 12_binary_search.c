#include <stdio.h>
int binary_search(int arr[], int size, int element)
{
    int start = 0, end = (size - 1);
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == element)
        {
            return mid;
        }

        if (arr[mid] > element)
        {
            end = mid - 1;
        }

        else if (arr[mid] < element)
        {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
    // return ("element not exist in array");
}

int main()
{
    int even[] = {2, 4, 6, 10, 12, 18, 20};
    int odd[] = {1, 3, 5, 7, 8, 9, 11};

    int size_even = sizeof(even) / sizeof(int);
    int size_odd = sizeof(odd) / sizeof(int);
    // printf("%d",size_odd);

    int index1 = binary_search(even, size_even, 12);
    int index2 = binary_search(odd, size_odd, 9);

    printf("12 is present at index %d\n", index1);
    printf("9 is present at index %d", index2);
    return 0;
}
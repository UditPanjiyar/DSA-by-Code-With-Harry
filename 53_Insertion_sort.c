#include <stdio.h>
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void insertion_sort(int A[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j>=0 && key < A[j])
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
int main()
{
    int arr[] = {4,3,76,89,12,54};
    printArray(arr, 6);
    insertion_sort(arr,6);
    printArray(arr, 6);
    return 0;
}
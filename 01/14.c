#include<stdio.h>

int main()
{
    int arr[] = {1, 25, 57, 89, 85, 93, 73, 34, 77};
    int size = 9;
    

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
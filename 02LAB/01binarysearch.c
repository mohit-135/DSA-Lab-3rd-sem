#include <stdio.h>

void binarySearch(int arr[] , int size ,int key){
    int low, high, mid;
    int found = 0;

    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            found = 1;
            printf("Element found at index %d\n", mid);
            break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (!found)
    {
        printf("Element not found.\n");
    }

}

int main()
{
    int arr[100] = {1, 12 ,13, 24, 38 ,45 , 58, 69, 72, 85, 96};
    int size = 11;
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);
    binarySearch(arr , size , key );

    return 0;
}
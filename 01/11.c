#include <stdio.h>

int main()
{
    int arr[100] = {1, 12 ,13, 24,38,45 , 58, 69, 72, 85, 96};
    int size = 11;
    int n, key;
    int low, high, mid;
    int found = 0;
    
    printf("Enter the key to search: ");
    scanf("%d", &key);

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

    return 0;
}
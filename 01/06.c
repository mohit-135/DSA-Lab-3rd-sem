#include<stdio.h>

int main()
{
    int a[10] = {1,4,7,3,8,12,9,5,8,4};
    int size = 10;
    int key;
    printf("enter number you want to find:");
    scanf("%d",&key);

    for (int i = 0; i < size; i++)
    {
        if (a[i] == key)
        {
            printf("the number is found at index %d",i);
            return 0;
        }
    }
    printf("the number is not found");

    return 0;
}
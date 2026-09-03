#include<stdio.h>

int swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a , b;
    printf("enter number one :");
    scanf("%d",&a);
    printf("enter number two :");
    scanf("%d",&b);

    printf("Before swapping: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}
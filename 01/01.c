#include<stdio.h>

int main()
{
    int n;
    printf("Enter a number :");
    scanf("%d",&n);
    if (n == 2)
        {
            printf("the number is prime number");
            return 0;
        }

    for(int i=2; i<=n/2; i++){
        if (n/i == 0)
        {
            printf("The number is a prime number");
            return 0;
        }
        
    }
    printf("The number is not a prime number");

    return 0;
}
// Print Armstrong numbers from 1 to n
#include <stdio.h>

int main()
{
    int n, temp, remainder, sum;

    printf("Enter the limit: ");
    scanf("%d", &n);

    printf("Armstrong numbers are: ");

    for (int i = 1; i <= n; i++)
    {
        temp = i;
        sum = 0;

        while (temp != 0)
        {
            remainder = temp % 10;
            sum += remainder * remainder * remainder;
            temp /= 10;
        }

        if (sum == i)
            printf("%d ", i);
    }

    return 0;
}
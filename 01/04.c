#include<stdio.h>

int main()
{
    int a[10][10],b[10][10],c[10][10],r1,c1,r2,c2;
    printf("enter row and column of first mtx :");
    scanf("%d %d ",&r1,&c1);
    printf("enter row and column of second mtx :");
    scanf("%d %d ",&r2,&c2);


    if (c1 != r2)
    {
        printf("matrices can not be multiplied");
        return 0;
    }
        printf("enter matrice 1 :");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c1; j++)
            {
                scanf("%d",&a[i][j]);
            }
            
        }
        printf("enter matrice 2 :");
        for (int i = 0; i < r2; i++)
        {
            for (int j = 0; j < c2; j++)
            {
                scanf("%d",&b[i][j]);
            }
        }
        printf("Matrice after multiplication is : \n");
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < c2; j++)
            {   
                for (int k = 0; k < c1; k++)
                    {
                        c[i][j] += a[i][k]*b[k][j];
                    }
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }
        
    

    return 0;
}
#include<stdio.h>

int main(){
    int arr[100];
    int max = 100;
    int top = -1;
    int oper ;
    printf("Enter 1 to push \nEnter 2 to pop : \n");
    scanf("%d",&oper);
    
    if (oper == 1)
{   
    //PUSH
    printf("Enter no od element you want to insert :");
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
    int element;
    printf("\nEnter element %d to insert : ",i+1);
    scanf("%d",&element);

        if(max == top){
        printf("The Stack is overflow");
    }else{
        top = top +1;
        arr[top] = element;
        printf("Element is inserted ! \n");
    }
}
    printf("Stack after element are inserted : ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ,",arr[i]);
    }

}else if(oper == 2){
    if(top == -1){
        printf("Stack Underflow");
    }else{
        top = top -1;
        printf("Poped element is : %d ",arr[top+1]);
        printf("Element is deleted ! \n");
    }
}

    
}
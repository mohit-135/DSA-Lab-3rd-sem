//structure
#include<stdio.h>

struct student
{
    char name[10];
    int rolln0;
    char dept[15];
};


int main()
{   
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct student s[n];
    for (int i = 0; i < n; i++)
    {   
        printf("Enter details of student %d:\n", i+1);
        printf("Enter name of student %d: ", i+1);
        scanf("%s", s[i].name);
        printf("Enter roll number of student %d: ", i+1);
        scanf("%d", &s[i].rolln0);
        printf("Enter department of student %d: ", i+1);
        scanf("%s", s[i].dept);
    }
    printf("\nDetails of students:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Student %d:\n", i+1);
        printf("Name: %s\n", s[i].name);
        printf("Roll Number: %d\n", s[i].rolln0);
        printf("Department: %s\n", s[i].dept);
    }
    

    return 0;
}
// List using ADT
#include<stdio.h>
#include<stdlib.h>
int n, list[25];
void create();
int insert();
int del();
void display();
void find();

void main()
{
    int ch;
    printf("\n\t\t\t\tLIST USING ARRAY");
    printf("\n\t\t\t\t**** ***** *****");

    do
    {
        printf("\n\nMAIN MENU");
        printf("\n1.Create\n2.Insert\n3.Delete\n4.Find\n5.Display\n6.Exit");
        printf("\nEnter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nenter the number of elements");
            scanf("%d", &n);
            create();
            display();
            break;

        case 2:
            n = insert();
            display();
            break;

        case 3:
            n = del();
            display();
            break;

        case 4:
            find();
            break;

        case 5:
            display();
            break;

        case 6:
        }
    } while (ch <= 6);
}

int insert()
{
    int i, ele, pos;
    printf("\nEnter the number and position");
    scanf("%d %d", &ele, &pos);

    if (n == 25)
    {
        printf("\nlist is full");
        return n;
    }
    else if (n == 0)
    {
        printf("\nlist has to be created first");
        return 0;
    }
    else if (pos == n + 1)
    {
        list[pos] = ele;
        n = n + 1;
        return n;
    }
    else if (pos > n)
    {
        printf("\nnot valid");
        return n;
    }
    else
    {
        for (i = n; i >= pos; i--)
            list[i + 1] = list[i];
        list[pos] = ele;
        n = n + 1;
        return n;
    }
}

void create()
{
    int i;
    printf("\nlist to be created:");
    for (i = 1; i <= n; i++)
        scanf("%d", &list[i]);
}

int del()
{
    int i, pos;
    printf("enter the position to be deleted:");
    scanf("%d", &pos);
    for (i = pos; i <= n; i++)
        list[i] = list[i + 1];
    n--;
    return n;
}
void find()
{
    int i, find;
    printf("\nenter the data to be searched:");
    scanf("%d", &find);
    if (n == 0)
    {
        printf("list is empty");
        return;
    }
    else
    {
        for (i = 1; i <= n; i++)
            if (list[i] == find)
            {
                printf("\nthe element %d is positioned at %d\n", find, i);
                getch();
                return;
            }
    }
    printf("\nelement is not found");
    return;
}
void display()
{
    int i;
    if (n == 0)
        printf("\nlist is empty");
    else
    {
        for (i = 1; i <= n; i++)
            printf("\t%d", list[i]);
    }
}

#include <stdio.h>
#include <stdlib.h>
int i, rear, front, item, s[10];
void insert(int item, int s[]);
void del(int s[]);
void display(int s[]);
void main()
{
	int ch;
	front = 0;
	rear = -1;
	do
	{
		printf("\n\n 1.INSERTION \n 2.DELETION \n 3.EXIT \n");
		printf("\nENTER YOUR CHOICE : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:

			printf("\n\t INSERTION \n");
			if (rear >= 9)
			{
				printf("\t\nQUEUE IS FULL\n");
			}
			else
			{
				printf("\nENTER AN ELEMENT : ");
				scanf("%d", &item);
				insert(item, s);
			}
			display(s);
			break;
		case 2:
			printf("\n\t DELETION \n");
			if (front > rear)
			{
				printf("\t\nQUEUE IS EMPTY\n");
			}
			else
			{
				del(s);
			}
			display(s);
			break;
		}
	} while (ch != 3);
}
void insert(int item, int s[])
{
	rear = rear + 1;
	s[rear] = item;
}
void del(int s[])
{
	item = s[front];
	front = front + 1;
	printf("\n DELETED ELEMENT IS %d\n\n", item);
}

void display(int s[])
{
	printf("\n");
	for (i = front; i <= rear; i++)
	{
		printf(" \t %d", s[i]);
	}
}

#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *cur, *first;

void create();
void push();
void pop();
void display();

void create()
{
	printf("\nENTER THE FIRST ELEMENT: ");
	cur = (struct node *)malloc(sizeof(struct node));
	scanf("%d", &cur->data);
	cur->link = NULL;
	first = cur;
}

void display()
{
	cur = first;
	printf("\n");
	while (cur != NULL)
	{
		printf("%d\n", cur->data);
		cur = cur->link;
	}
}
void push()
{
	printf("\nENTER THE NEXT ELEMENT: ");
	cur = (struct node *)malloc(sizeof(struct node));
	scanf("%d", &cur->data);
	cur->link = first;
	first = cur;
}

void pop()
{
	if (first == NULL)
	{
		printf("\nSTACK IS EMPTY\n");
	}
	else
	{
		cur = first;
		printf("\nDELETED ELEMENT IS %d\n", first->data);
		first = first->link;
		free(cur);
	}
}
void main()
{
	int ch;
	while (1)
	{
		printf("\n\n 1.CREATE \n 2.PUSH \n 3.POP \n 4.EXIT \n");
		printf("\n ENTER YOUR CHOICE : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			create();
			display();
			break;
		case 2:
			push();
			display();
			break;
		case 3:
			pop();
			display();
			break;
		case 4:
			exit(0);
		}
	}
}

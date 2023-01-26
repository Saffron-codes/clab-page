#include <stdio.h>
#include <stdlib.h>
void create();
void insert();
void del();
void display();
struct node
{
	int data;
	struct node *flink, *blink;
};
struct node *first = NULL, *last = NULL, *next, *prev, *cur;
void create()
{
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d", &cur->data);
	cur->flink = NULL;
	cur->blink = NULL;
	first = cur;
	last = cur;
}
void insert()
{
	int pos, c = 1;
	cur = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d", &cur->data);
	printf("Enter the position:");
	scanf("%d", &pos);
	if (pos == 1 && first != NULL)
	{
		cur->flink = first;
		cur->blink = NULL;
		first->blink = cur;
		first = cur;
	}
	else
	{
		next = first;
		while (c < pos)
		{
			prev = next;
			next = prev->flink;
			c++;
		}
		if (prev == NULL)
		{
			printf("Invalid position");
		}
		else
		{
			cur->flink = prev->flink;
			cur->blink = prev;
			prev->flink->blink = cur;
			prev->flink = cur;
		}
	}
}
void del()
{
	int pos, c = 1;
	printf("Enter the position to be deleted");
	scanf("%d", &pos);
	if (first == NULL)
	{
		printf("DLL is empty");
	}
	else if (pos == 1 && first->flink == NULL)
	{
		printf("Deleted element is %d", first->data);
		free(first);
		first = NULL;
		last = NULL;
	}
	else if (pos == 1 && first->flink != NULL)
	{
		cur = first;
		first = first->flink;
		cur->flink = NULL;
		first->blink = NULL;
	}
	else
	{
		next = first;
		while (c < pos)
		{
			cur = next;
			next = next->flink;
			c++;
		}
		if (next == NULL)
		{
			printf("Invalid position");
		}
		else
		{
			cur->flink = next->flink;
			next->flink->blink = cur;
			next->flink = NULL;
			next->blink = NULL;
			printf("Deleted element is %d", next->data);
			free(next);
		}
	}
}
void display()
{
	cur = first;
	printf("\n The elements in the list are:");
	while (cur != NULL)
	{
		printf("%d\t", cur->data);
		cur = cur->flink;
	}
}
void main()
{
	int ch;
	printf("Doubly linked list:");
	do
	{
		printf("\n 1.Create \n 2.Insert \n 3.Delete \n 4.Exit");
		printf("\n\nEnter your option");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			create();
			display();
			break;
		case 2:
			insert();
			display();
			break;
		case 3:
			del();
			display();
			break;
		case 4:
			exit(0);
		}
	} while (ch <= 3);
}

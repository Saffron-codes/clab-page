#include "stdio.h"
#include "stdlib.h"
void create();
void insert();
void delet();
void display();
struct node
{
  int data;
  struct node *link;
};
struct node *first = NULL, *last = NULL, *next, *prev, *cur;
void create()
{
  cur = (struct node *)malloc(sizeof(struct node));
  printf("\nENTER THE DATA: ");
  scanf("%d", &cur->data);
  cur->link = NULL;
  first = cur;
  last = cur;
}
void insert()
{
  int pos, c = 1;
  cur = (struct node *)malloc(sizeof(struct node));
  printf("\nENTER THE DATA: ");
  scanf("%d", &cur->data);
  printf("\nENTER THE POSITION: ");
  scanf("%d", &pos);
  if ((pos == 1) && (first != NULL))
  {
    cur->link = first;
    first = cur;
  }
  else
  {
    next = first;
    while (c < pos)
    {
      prev = next;
      next = prev->link;
      c++;
    }
    if (prev == NULL)
    {
      printf("\nINVALID POSITION\n");
    }
    else
    {
      cur->link = prev->link;
      prev->link = cur;
    }
  }
}
void delet()
{
  int pos, c = 1;
  printf("\nENTER THE POSITION : ");
  scanf("%d", &pos);
  if (first == NULL)
  {
    printf("\nLIST IS EMPTY\n");
  }
  else if (pos == 1 && first->link == NULL)
  {
    printf("\n DELETED ELEMENT IS %d\n", first->data);
    free(first);
    first = NULL;
  }
  else if (pos == 1 && first->link != NULL)
  {
    cur = first;
    first = first->link;
    cur->link = NULL;
    printf("\n DELETED ELEMENT IS %d\n", cur->data);
    free(cur);
  }
  else
  {
    next = first;
    while (c < pos)
    {
      cur = next;
      next = next->link;
      c++;
    }
    cur->link = next->link;
    next->link = NULL;
    if (next == NULL)
    {
      printf("\nINVALID POSITION\n");
    }
    else
    {
      printf("\n DELETED ELEMENT IS %d\n", next->data);
      free(next);
    }
  }
}
void display()
{
  cur = first;
  while (cur != NULL)
  {
    printf("\n %d", cur->data);
    cur = cur->link;
  }
}
void main()
{
  int ch;
  printf("\nSINGLY LINKED LIST");
  do
  {
    printf("\n\n1.CREATE\n2.INSERT\n3.DELETE\n4.EXIT");
    printf("\nENTER YOUR CHOICE : ");
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
      delet();
      display();
      break;
    case 4:
      exit(0);
    }
  } while (ch <= 3);
}

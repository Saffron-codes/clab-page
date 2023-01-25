#include<stdio.h>
#include<stdlib.h>
int i,top,item,s[10];
int max=10;
void push(int item,int s[]);
void pop(int s[]);
void display(int s[]);
void main()
{
int ch;
top=-1;
do
{
printf("\n\n 1.PUSH \n 2.POP \n 3.EXIT \n");
printf("\n ENTER YOUR CHOICE : ");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("\t PUSH \n");
	if(top>=max-1)
	{
	printf("\n STACK IS FULL\n");
	}
	else
	{
	printf("\n ENTER AN ELEMENT : ");
	scanf("%d",&item);
	push(item,s);
	}
	display(s);
	break;
case 2:printf("\t\n POP \n");
	if(top<0)
	{
	printf("\nSTACK IS EMPTY\n");
	}
	else
	{
	pop(s);
	}
	display(s);
	break;
}}while(ch!=3);
}
void push(int item,int s[])
{
top=top+1;
s[top]=item;
}
void pop(int s[])
{
item=s[top];
top=top-1;
printf("\nDELETED ELEMENT IS %d\n",item);
}
void display(int s[])
{
printf("\n");
for(i=top;i>=0;i--)
{
printf(" \n %d",s[i]);
}
}

#include<stdio.h>
#include<string.h>
#include<ctype.h>
int pop();
int i,l,top=-1,value[25],val,p,q,r;
char a[25],x;
void main()
{
printf("\nEnter the postfix expression\n");
gets(a);
l=strlen(a);
	for(i=0;i<l;i++)
	{
		if(isalpha(a[i]))
		{
		printf("\nEnter the value for %c",a[i]);
		scanf("%d",&val);
		top=top+1;
		value[top]=val;
		}
		else
		{
		x=a[i];
		p=pop();
		q=pop();
			switch(x)
			{
			case '+': r=p+q;
	 		             top=top+1;
	  		             value[top]=r;
	  		             break;
 			case '-': r=q-p;
	  		            top=top+1;
	  		            value[top]=r;
	 		            break;
			case '*': r=p*q;
	  		             top=top+1;
	  		             value[top]=r;
	 		             break;
			case '/': r=q/p;
	  		             top=top+1;
	  		            value[top]=r;
	  		            break;
			}
}
}
r=value[top];
printf("\nValue of expression is %d",r);
}
int pop()
{
int ch;
ch=value[top];
top=top-1;
return ch;
}

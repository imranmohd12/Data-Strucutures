#include<stdio.h>
int top=-1,n=0,stack[100];

int push(int val,int n)
{
    if(top == n)
        printf("stack Overflow");
    else
    {
        top++;
        stack[top] = val;
        printf("%d inserted at %d \n",val,top);
    }
}
int pop()
{
    if(top == -1)
        printf("underflow");
    else
    {
        printf("%d is popped\n",stack[top]);
        top--; 
    }
        
    
}
void display()
{
    for(int i=top;i>=0;i--)
        printf("%d ",stack[i],i);
    printf("\n");
}

void main()
{
    push(7,4);
    push(8,4);
    push(9,4);
    display();
    pop();
    pop();
    display();
}
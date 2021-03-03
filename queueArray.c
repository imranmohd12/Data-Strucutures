#include<stdio.h>

int que[100],front = -1,rear = -1;

int insert(int item)
{
    if(front == -1 || front > rear)
    {
        front++;
        rear++;
        que[rear] = item;

    }
    else
    {
        rear++;
        que[rear] = item;
    }
    
}
int delete()
{
    if(front == -1)
        printf("underflow");
    else
    {
        if(front == rear)
        {
            front--;
            rear--;
        }
        else
        {
            rear--;
        }
        
    }
    
}
void display()
{
    for(int i=front;i<rear+1;i++)
    {
        if(i==-1)
            printf("que is empty");
        else
            printf("%d ",que[i]);
    }
    printf("\n");
}

void main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();
    delete();
    display();
}
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int item;
    struct Node *next;
};
struct Node *head;
int n = 0;

int push(int item)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL)
        printf("node is NULL");
    else
    {
        ptr->item = item;
        if(head == NULL)
        {   
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            ptr->next = head;
            head = ptr;
        }
    }
}

void pop()
{
    struct Node *temp;
    if(head == NULL)
        printf("stack is underflow");
    else
    {
        temp = head;
        head = temp->next;
        free(temp);
    }
    
}

void display()
{
    struct Node *temp = head;
    
    if(head == NULL)
        printf("stack is Empty");
    else
    {
        while(temp->next != NULL)
        {
            printf("%d ",temp->item);
            temp = temp->next;
        }
        printf("%d\n",temp->item);
    }
}

void main()
{
    push(5);
    push(6);
    push(7);
    push(8);
    display();
    pop();
    pop();
    display();
}
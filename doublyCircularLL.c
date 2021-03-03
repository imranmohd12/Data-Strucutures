#include<stdio.h>
#include<stdlib.h>

struct Node{
    int item;
    struct Node *prev;
    struct Node *next;
};
struct Node *head;

int addAtBegin(int item)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL)
        printf("Overflow");
    else
    {
        ptr->item = item;
        if(head == NULL)
        {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        }
        else
        {
            struct Node *temp = head;
            while(temp->next != head)
                temp = temp->next;
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
            head = ptr;
        }
    }
}

int addAtLast(int item)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL)
        printf("Overflow");
    else
    {
        ptr->item = item;
        if(head == NULL)
        {
            ptr = head;
            ptr->next = head;
            ptr->prev = head;
        }
        else
        {
            struct Node *temp = head;
            while(temp->next != head)
                temp = temp->next;
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = head;
            head->prev = ptr;
        }
        printf("%d inserted\n",ptr->item);
    }
    
}

void deleteAtBegin()
{
    if(head == NULL)
        printf("list is empty\n");
    else
    {
        if(head->next == head)
        {
            printf("%d deleted\n",head->item);
            head = NULL;
            free(head);
        }
        else
        {
            struct Node *temp1,*temp2,*temp3;
            temp3 = head;
            temp1 = head->next;
            temp2 = head->prev;
            temp1->prev = temp2;
            temp2->next = temp1;
            head = temp1;
            printf("%d deleted\n",temp3->item);
            free(temp3);
        }   
    }
}

void deleteAtEnd()
{
    if(head == NULL)
        printf("list is empty");
    else
    {
        if(head->next == head)
        {
            printf("%d is deleted\n",head->item);
            head = NULL;
            free(head);
        }
        else
        {
            struct Node *temp1,*temp2;
            temp1 = head;
            while(temp1->next != head)
                temp1 = temp1->next;
            temp2 = temp1->prev;
            temp2->next = head;
            head->prev = temp2;
            printf("%d is delete\n",temp1->item);
            free(temp1);
        }
        
    }
    
}

void distplay()
{
    struct Node *temp;
    if(head == NULL)
        printf("List is Empty");
    else
    {
        temp = head;
        while(temp->next != head)
        {
            printf("%d ",temp->item);
            temp = temp->next;
        }
        printf("%d\n",temp->item);
    }
    
}
void main()
{
    addAtBegin(1);
    addAtBegin(2);
    addAtBegin(3);
    addAtLast(4);
    addAtLast(5);
    distplay();
    deleteAtBegin();
    deleteAtBegin();
    distplay();
    deleteAtEnd();
    deleteAtEnd();
    distplay();
}
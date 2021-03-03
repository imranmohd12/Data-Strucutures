#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int item;
    struct Node *next;
};
struct Node *head;

int addBegin(int item){
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL)
        printf("overflow");
    else
    {
        ptr->item=item;
        if(head == NULL)
        {
            head = ptr;
            ptr->next=head;
        }
        else
        {   
            struct Node *temp=head;
            while (temp->next != head)
                temp = temp->next;
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
        printf("\n%d inserted at beginning\n",ptr->item);
    }
}
int addLast(int item)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));

    if(ptr == NULL)
        printf("overflow");
    else 
    {
        ptr->item = item;
        if(head == NULL)
        {
            
            head = ptr;
            head->next=head;
        }
        else
        {
            struct Node *temp = head;
            while(temp->next != head)
                temp = temp->next;
            temp->next = ptr;
            ptr->next=head;
        }
        printf("\n%d inserted at the end\n",ptr->item);
    }
    
}
/*int addAtPos(int pos,int item)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL)
        printf("Overflow");
    else
    {
        ptr->item = item;
        if(pos == 1)
        {
            
        }
    }
    
}*/
void deleteAtBegin()
{
    if(head == NULL)
        printf("list is empty");
    else
    {
        if(head->next == head)
        {
            head = NULL;
            free(head);
            
        }
        else
        {
            struct Node *ptr;
            ptr = head;
            while(ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = head->next;
            printf("\n%d deleted\n",head->item);
            free(head);
            head = ptr->next; 
        }
        
    }
    
}
void deleteAtEnd()
{
    struct Node *ptr,*temp;
    if(head == NULL)
        printf("List is empty");
    else
    {
        if(head->next == head)
        {
            printf("\n%d deleted\n",head->item);
            head = NULL;
            free(head);
        }
        else
        {
            ptr = head;
            while(ptr->next != head)
            {
                temp = ptr;
                ptr = ptr->next; 
            }    
            temp->next = head;
            printf("\n%d deleted\n",ptr->item);
            ptr = NULL;
            free(ptr);
        }
        
    }
}
void display(){
    struct Node *temp = head;
    if(head == NULL)
        printf("\nlist is empty\n");
    else
    {
        while(temp->next != head)
        {
            printf("%d ",temp->item);
            temp = temp->next;
        }
        printf("%d",temp->item);
    }
}

void main(){
    addBegin(1);
    addBegin(2);
    addBegin(3);
    addLast(4);
    display();
    deleteAtBegin();
    deleteAtBegin();
    display();
    deleteAtEnd();
    deleteAtEnd();
    display();
}
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int item;
    struct Node *prev;
    struct Node *next;
};
struct Node *head;
int insertAtBegin(int item){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL)
        printf("Overflow");
    else
    {
        ptr->item=item;
        if(head == NULL)
        {
            head = ptr;
            head->prev=NULL;
            head->next=NULL;
            printf("inserted");
        }
        else
        {
            ptr->next=head;
            ptr->prev=NULL;
            head->prev=ptr;
            head=ptr;
            printf("inserted\n");
        }
    }
    
}
int insertAtLast(int item)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp;
    if(ptr == NULL)
        printf("Overflow");
    else
    {
        ptr->item=item;
        if(head == NULL)
        {
            ptr->next=NULL;
            ptr->prev=NULL;
            head=ptr;
        }
        else
        {
            temp=head;
            while(temp->next != NULL)
                temp = temp->next;
            ptr->next=NULL;
            temp->next=ptr;
            ptr->prev=temp;
            printf("\ninserted\n");
        }
        
    }
    
}
int 
insertAtPos(int pos,int item)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp,*temp1;
    if(ptr == NULL)
        printf("Over Flow");
    else
    {
        ptr->item = item;
        if(pos == 1)
        {
            ptr->next=head;
            ptr->prev=NULL;
            head->prev=ptr;
            head=ptr;
            printf("Node inserted\n");
        }
        else
        {
            temp=head;
            for(int i=2;i<pos;i++)
            {
                temp = temp->next;
                if(temp == NULL)
                {
                    printf("\nposition exceded\n");
                    return 0;
                }
            }
            temp1 = temp->next;
            ptr->prev = temp;
            ptr->next=temp1;
            temp->next = ptr;
            temp1->prev = ptr;
            printf("\nnode Inserted\n");
        } 
    }
}
void deleteAtBegin()
{
    struct Node *temp;
    if(head == NULL)
        printf("list is already empty");
    else
    {
        if(head->next == NULL)
        {
            free(head);
            printf("%d deleted\n",head->item);
            head = NULL;
        }
        else
        {
            temp = head;
            head = head->next;
            head->prev = NULL;
            printf("%d deleted\n",temp->item);
            free(temp);
        }      
    }  
}
int deleteAtLast()
{
    struct Node *temp,*temp1;
    if(head == NULL)
        printf("List is Empty!!");
    else
    {
        if(head->next == NULL)
        {
            free(head);
            head = NULL;
            printf("hii");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp1 = temp->prev;
            temp1->next = NULL;
            printf("\n%d deleted\n",temp->item);
            free(temp);
        }       
    }  
}
int deleteAtPos(int pos)
{
    struct Node *temp,*temp1,*temp2;
    if(head == NULL)
        printf("list is empty");
    else
    {
        if(head->next == NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            temp = head->next;
            for(int i=2;i<pos;i++)
            {
                temp = temp->next;
                if(temp == NULL)
                {
                    printf("\nposition not existed\n");
                    return 0;
                }
            }
            temp1 = temp->prev;
            temp1->next = temp->next;
            temp2 = temp->prev;
            temp2->prev = temp1;
            printf("\n%d deleted\n",temp->item);
            free(temp);
        }
        
    }
    
}
void display(){
    struct Node *temp = head;
    if(head == NULL)
        printf("list is empty\n");
    else
    {
        while (temp->next != NULL)
        {
            printf("%d ",temp->item);
            temp=temp->next;
        }
        printf("%d",temp->item);
    }
    
}
void main()
{
    display();
    insertAtBegin(2);
    insertAtLast(3);
    insertAtBegin(1);
    insertAtBegin(1);
    insertAtBegin(1);
    insertAtBegin(1);
    display();
    deleteAtLast();
    deleteAtBegin();
    display();
    insertAtPos(88,90);
    display();
    deleteAtPos(6);
    deleteAtPos(10);
    deleteAtBegin(1);
    display();
}
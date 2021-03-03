#include<stdio.h>
#include<stdlib.h>

struct Node{
    int item;
    struct Node *next;
};
struct Node *head;

int insert(int item)
{
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL)
        printf("underFlow");
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
            struct Node *temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = ptr;
            ptr->next = NULL;
        }
    }
}
void delete()
{
    if (head == NULL)
    {
        printf("queue is underFLow");
    }
    else
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);   
    }
}
void display()
{
    struct Node *temp = head;
    while(temp->next != NULL)
    {
        printf("%d ",temp->item);
        temp = temp->next;
    }
    printf("%d\n",temp->item);
}

void main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    display();
    delete();
    delete();
    display();
}
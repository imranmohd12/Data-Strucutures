#include <stdio.h>

struct Node{
    int item;
    struct Node *next;
};

struct Node *head;
int begInsert(int item){
    //creating node.inittially head will be null
    struct Node *ptr;
    //allocating memory
    ptr=(struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL)
        printf("overflow");
    else
    {
        ptr->item=item;
        ptr->next=head;
        //updating head
        head = ptr;
        
    }
    return 0;
}
int insertlast(int item){
    struct Node *ptr,*temp;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    temp = head; 
    if(ptr == NULL)
        printf("overflow");
    else
    {
        ptr->item = item;
        ptr->next = NULL;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;

    }
    
}
int certainPosition(int item,int position){
    struct Node *temp,*ptr;
    temp = head;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->item=item;
    for(int i=1;i<position-1;i++)
        temp = temp->next;
    ptr->next=temp->next;
    temp->next=ptr;
}
void deleteBegin(){
    struct Node *ptr;
    if(ptr == NULL)
        printf("List is Empty");
    else
    {
        ptr = head;
        head = ptr->next;
        printf("\nBeginning node %d deleted!!\n",ptr->item);
        free(ptr);
    }
    
}
void deleteLast(){
    if(head == NULL)
        printf("List is already empty");
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct Node *temp1 = head;
        struct Node *temp2 = head;
        while (temp1->next!=NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = NULL;
        printf("last node %d is deleted!!\n",temp1->item);
        free(temp1);
    }
}
int deletePos(int position)
{
    struct Node *current;
    if(head == NULL)
    {
        printf("list is empty");
    }
    else if (position == 1)
    {
        current = head;
        head = current->next;
        printf("\nThe position %d item : %d deleted!!\n",position,current->item);
        free(current);
    }
    else
    {
        current = head;
        struct Node *prev = head;
        for(int i=2;i<position;i++)
        {
            prev = current;
            current = current->next;
            if(current == NULL)
                printf("\nthe position is exceded");
        }
        prev->next=current->next;
        printf("\nThe position %d item : %d deleted!!\n",position,current->item);
        free(current);
        
    }
}
void display(){
    struct Node *ptr;
    ptr = head;
    while (ptr->next!=NULL)
    {
        printf("%d ",ptr->item);
        ptr = ptr->next;
    }
    printf("%d ",ptr->item);
}
void main(){
    begInsert(5);
    insertlast(6);
    insertlast(7);
    insertlast(8);
    insertlast(9);
    insertlast(10);
    insertlast(11);
    certainPosition(99,4);
    display();
    deleteBegin();
    deleteLast();
    display();
    deletePos(9);
    display();
}
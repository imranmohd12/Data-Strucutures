#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
};
struct Node *root;
void searchRoot(struct Node *temp,struct Node *ptr);
int insert(int val)
{
    struct Node *ptr = (struct Node*)malloc(1*sizeof(struct Node));
    if(root == NULL)
    {
        ptr->val = val;
        ptr->left = NULL;
        ptr->right = NULL;
        root = ptr;
        printf("success root\n");
    }
    else
    {
        ptr->val = val;
        ptr->left=ptr->right=NULL;
        //printf("%d\n",ptr->val);
        searchRoot(root,ptr);
    }
    
}
void searchRoot(struct Node *temp,struct Node *ptr)
{
            if(temp->val > ptr->val && temp->left == NULL)
            {
                printf("success left %d\n",ptr->val);
                temp->left = ptr;
            }
                
            else if(temp->val <= ptr->val && temp->right == NULL)
            {
                printf("success right %d\n",ptr->val);
                temp->right = ptr;
            }
                
            else if(temp->val > ptr->val && temp->left != NULL)
            {
                temp = temp->left;
                searchRoot(temp,ptr);
            }
            else if(temp->val <= ptr->val && temp->right != NULL)
            {
                temp = temp->right;
                searchRoot(temp,ptr);
            }
}
void inorder(struct Node *temp)
{
    
}
int main()
{
    insert(2);
    insert(3);
    insert(5);
    insert(1);
}

#include<stdio.h>
#include<stdlib.h>

int main(){
    int size=10,element;
    printf("enter the size of an array : ");
    scanf("%d",&size);
    int arr[size];
    printf("\nEnter the elements seperated by space : ");
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("\nEnter the Element to be searched : ");
    scanf("%d",&element);
    linearSearch(arr,element,size);
}
int linearSearch(int arr[],int element,int size)
{
    for(int i=0;i<size;i++)
    {
        if (arr[i] == element)
        {
            printf("\nElement %d found at position %d",arr[i],i+1);
        }
    }
           
}

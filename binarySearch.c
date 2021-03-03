#include<stdio.h>
#include<stdlib.h>

int main(){
    int size,element;
    printf("enter the size of an array : ");
    scanf("%d",&size);
    int arr[size];
    printf("\nEnter the elements in sorted order : ");
    for(int i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("\nEnter the Element to be searched : ");
    scanf("%d",&element);
    BubbleSort(arr,size);
    for (int i = 0; i < size; i++)
        printf("%d ",arr[i]);    
    BinarySearch(arr,element,size);
}
int BinarySearch(int arr[],int element,int size)
{
    int beg=0,end=(size-1),mid=0;
    while(arr[mid] != element)
    {
        mid = (beg+end)/2;
        if(element <= mid)
            end = mid;
        else
            beg = mid+1;
    }
    printf("found %d",arr[mid]);
}

int BubbleSort(int arr[],int size)
{
    int temp = 0;
    for(int i=0;i<size;i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(arr[j]<arr[i])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

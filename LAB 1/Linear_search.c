/*1. Given an array of n integers and a key element, write a C program to search the element
using linear search*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int main()
{
    int n, arr[MAX],elt,pos;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    printf("\nEnter elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nArray elements: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nEnter the element to search: ");
    scanf("%d",&elt);
    int found=0;
    for(int i=0;i<n;i++){
        if(elt==arr[i])
        {
            found=1;
            pos=i;
            break;
        }
    }
    if(found)
        printf("\n%d is found at index: %d",elt,pos);
    else
        printf("\nElement not found.");
    return 0;
}

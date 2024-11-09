#include<stdio.h>
#include<stdlib.h>
int *arr;
int s,i;

void insertion_sort(int arr[], int s)
{
for (int i=1; i<s;i++)
{
int key=arr[i];
int j=i-1;
while(j>=0 && arr[j]>key)
{
arr[j+1]=arr[j];
j--;
}
arr[j+1]=key;
}
}

void selection_sort(int arr[],int s)
{
for(i=0;i<s-1;i++)
{
int min=i;
for(int j=i+1;j<=s-1;j++)
{
if(arr[min]>arr[j])
{
  				min=j;
}
}
int temp;
if(min!=i)
{
  		temp=arr[min];
          arr[min]=arr[i];
          arr[i]=temp;
}          
}
}

void bubblesort(int arr[], int s)
{
int temp,flag;
for(int i=0;i<s;i++)
{
flag=0;
for(int j=0;j<s-i-1;j++)
{
if(arr[j]>arr[j+1])
{
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
flag=1;
}
}
if(flag==0)
break;
}
}

void main()
{
    printf("Enter the size of array: ");
    scanf("%d",&s);
    arr=malloc(sizeof(s)); //array creation
    printf("Enter array elements: ");
    for(i=0;i<s;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n1. Insertion Sort\n2. Selection Sort\n3. Bubble Sort\n");
    printf("Enter the choice: ");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
    insertion_sort(arr,s);
    break;
    
    case 2:
    selection_sort(arr,s);
    break;
    
    case 3:
    bubblesort(arr,s);
    break;
    
    default:
    printf("Invalid Choice");
    exit(0);
    }
    printf("Sorted array: \n");
    for(i=0;i<s;i++)
    {
        printf("%d \t",arr[i]);
    }    
}    

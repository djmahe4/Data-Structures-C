#include<stdio.h>

void bubblesort(int a[], int s)
{
int temp,flag;
for(int i=0;i<s-1;i++)
{
flag=0;
for(int j=0;j<s-i-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
flag=1;
}
}
if(flag==0)
break;
}
}

void binarysearch(int a[],int s, int key)
{
bubblesort(a,s);
printf("Sorted array: ");
for(int i=0;i<s;i++)
{
    printf("\n%d\n",a[i]);
}
int flag=0;
int low=0,high=s-1,mid;
while(low<=high)
{
    mid=(low+high)/2;
    if(a[mid]==key)
    {
    printf("Element found at position: %d", mid+1);
    flag=1;
    break;
    }
    else if(a[mid]>key)
    high=mid-1;
    else
    low=mid+1;
}
if(flag==0)
printf("Element not found");
}
//linear search
void linearsearch(int a[],int s,int k)
{
int flag=0;
for(int i=0;i<s;i++)
{
if(a[i]==k)
{
printf("Element found at position: %d",i+1);
flag=1;
break;
}
}
if(flag==0)
printf("Element not found");
}



int main()
{
int s,key,ch;
printf("Enter the size of array: ");
scanf("%d",&s);
int a[s];
printf("Enter the array elements: ");
for(int i=0;i<s;i++)
{
    scanf("%d",&a[i]);
}
printf("Enter the element to be searched: ");
scanf("%d",&key);
printf("1.Linear Search\n2.Binary Search\nEnter your choice: ");
scanf("%d",&ch);
switch(ch){
    case 1:
        linearsearch(a,s,key);
        break;
    case 2:
        binarysearch(a,s,key);
        break;
    default:
        printf("Invalid Choice");
        exit(0);
}
}
    #include<stdio.h>

void bubblesort(int a[], int s)
{
int temp,flag;
for(int i=0;i<s-1;i++)
{
flag=0;
for(int j=0;j<s-i-1;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
flag=1;
}
}
if(flag==0)
break;
}
}

void binarysearch(int a[],int s, int key)
{
bubblesort(a,s);
printf("Sorted array: ");
for(int i=0;i<s;i++)
{
    printf("\n%d\n",a[i]);
}
int flag=0;
int low=0,high=s-1,mid;
while(low<=high)
{
    mid=(low+high)/2;
    if(a[mid]==key)
    {
    printf("Element found at position: %d", mid+1);
    flag=1;
    break;
    }
    else if(a[mid]>key)
    high=mid-1;
    else
    low=mid+1;
}
if(flag==0)
printf("Element not found");
}
//linear search
void linearsearch(int a[],int s,int k)
{
int flag=0;
for(int i=0;i<s;i++)
{
if(a[i]==k)
{
printf("Element found at position: %d",i+1);
flag=1;
break;
}
}
if(flag==0)
printf("Element not found");
}



int main()
{
int s,key,ch;
printf("Enter the size of array: ");
scanf("%d",&s);
int a[s];
printf("Enter the array elements: ");
for(int i=0;i<s;i++)
{
    scanf("%d",&a[i]);
}
printf("Enter the element to be searched: ");
scanf("%d",&key);
printf("1.Linear Search\n2.Binary Search\nEnter your choice: ");
scanf("%d",&ch);
switch(ch){
    case 1:
        linearsearch(a,s,key);
        break;
    case 2:
        binarysearch(a,s,key);
        break;
    default:
        printf("Invalid Choice");
        exit(0);
}
}
    

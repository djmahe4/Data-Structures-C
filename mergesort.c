#include<stdio.h>
#include<stdlib.h>
int *a;
void merge(int a[],int l,int m, int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++)
    {
    L[i]=a[l+i];
    }
    for(int j=0;j<n2;j++)
    {
    R[j]=a[m+1+j];
    }
    int i=0;
    int j=0;
    int k=l;
    while (i<n1 && j<n2)
    {
        if (L[i]<=R[j])
        {
        a[k]=L[i];
        i++;
        }
        else
        {
        a[k]=R[j];
        j++;
        }
        k++;
    }
    while(i<n1)
    {
    a[k]=L[i];
    i++;
    k++;
    }
    while(j<n2)
    {
    a[k]=R[j];
    j++;
    k++;
    }
}

void mergeSort(int a[], int l, int r)
{
if (l>=r)
{
    return;
}
int m=(l+r)/2;
mergeSort(a,l,m);
mergeSort(a,m+1,r);
merge(a,l,m,r);  
}

int main()
{
int s;
printf("Enter the size of array: ");
    scanf("%d",&s);
    a=malloc(sizeof(s)); //array creation
    printf("Enter array elements: ");
    for(int i=0;i<s;i++)
    {
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,s-1);
    printf("Sorted array: \n");
    for(int i=0;i<s;i++)
    {
        printf("%d \t",a[i]);
    }    
return 0;
}

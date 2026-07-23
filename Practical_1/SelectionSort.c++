//SelectionSort
#include<stdio.h>
int main()
{
    int arr[100],n,i,j,min_idx;
    printf("Enter No of elements ");
    scanf("%d",&n);
    printf("Enter the elements for the array:");
    for(i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
}
for(i=0;i<n-1;i++){
    min_idx = i;
    for(j=i+1;j<n;j++)
    {
        if(arr[j]<arr[min_idx])
        {
            min_idx = j;
        }
    }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    
}
    printf("Selection Sorted array: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
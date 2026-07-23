//insertion sort
#include<iostream>
using namespace std;
int main()
{
    int n, temp, j;
    printf("Enter the no of elements :");
    cin>>n;

    int a[n];
    printf("Enter the elements :");
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<n;i++){
        temp = a[i];
        j = i-1;
        
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    

    cout<<"Sorted array - ";
    for(int i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }

}   
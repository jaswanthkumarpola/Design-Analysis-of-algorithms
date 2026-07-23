#include<iostream>
int BinarySearch(int n, int key, int arr[])
{
    int low =0, High =n-1;
    while(low<=High){
        int mid = (High+low)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            low = mid+1;
        }
        else
        {
            High = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[0];
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 0;
    
    printf("Enter the no of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements:");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search:");
    scanf("%d", &key);
    int binaryResult = BinarySearch(n, key, arr);
    if(binaryResult != -1)
    {
        printf("Found the key element at the index %d", binaryResult);
    }
    else
    {
        printf("Not found the key element in the given array.");
    }
}
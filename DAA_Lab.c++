//Searching algorithms
//Linear Search
#include<iostream>
using namespace std;
void LinearSearch(int arr[], int n, int key)
{
    for(int i = 0; i<n; i++)
    {
        if(arr[i] == key)
        {
            cout << "Element found at index " << i << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}
int main(){
    int arr[7], n;
    int key = 0;
    printf("Enter the no of elements for the array:");
    printf("Enter the key element to be searched:");
    cin >> key;
    for(int i =0; i<n;i++){
        scanf("%d", &arr[i]);
    }
    LinearSearch(arr, n, key);


}


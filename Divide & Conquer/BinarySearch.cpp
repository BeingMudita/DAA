#include <bits/stdc++.h>

using namespace std;
int binary_search(int arr[], int l, int r, int key){
    if(l<=r){ // to checked if array is sorted
        int mid = l +(r-l)/2;
        if(arr[mid]==key) //O(C)
        return mid;
        if(arr[mid]>key)
        return binary_search(arr, l, mid-1, key); //T(n/2)

        return binary_search(arr, mid+1, r, key); //T(n/2)
    }
    return -1;

}

int main(){
    int arr[] = {9, 12, 15, 72, 80, 90};
    int key = 80;
    int n=sizeof(arr)/sizeof(arr[0]);
    int result = binary_search(arr,0, n-1,key);
    (result==-1)
    ?cout<<"Element is not present in array"
    :cout<<"Element is present at index "<<result;
    return 0;
}
// Time Complexity: O(log n)
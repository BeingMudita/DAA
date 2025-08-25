#include <bits/stdc++.h>
using namespace std;

int ternary_search(int arr[], int l, int r, int key){
    if(l<=r){
        int mid1 = l+(r-l)/3;
        int mid2 = r-(r-l)/3;
        if(arr[mid1]== key){
            return mid1;
        }
        if(arr[mid2]== key){
            return mid2;
        }
        if(arr[mid1]>key){
            return ternary_search(arr, l, mid1-1, key); //T(n/3)
        }
        else if(arr[mid2]<key){
            return ternary_search(arr, mid2+1, r, key); //T(n/3)
        }
        else{
            return ternary_search(arr, mid1+1, mid2-1, key); //T(n/3)
        }
    }
}
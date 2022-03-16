#include <iostream>
using namespace std ;


void LRotate(int arr[] , int n) {
    int temp = arr[0];
    for(int i = 1 ; i < n ; i++) {
        arr[i -1] = arr[i];

    }
    arr[n-1] = temp ;
}

void dRoate(int arr[] , int n , int d) {
    for(int i =0 ; i < d ; i++) {
        LRotate(arr , n);
    }
}



void LRotatebyd(int arr[] , int n , int d) {
    int temp[d];
    for(int i =0 ; i < d ; i++) {
        temp[i] = arr[i];
    }
    for(int i = d ; i < n ; i++) {
        arr[i -d] = arr[i];
    }
    for(int i =0 ; i < d ; i++) {
        arr[n -d + i] = temp[i];
    }
}

void Reverse(int arr[] , int low , int high) {
    while(low < high) {
       int temp = arr[high];
       arr[high] = arr[low];
       arr[low] = temp ;
        low++ ;
        high-- ;
    }
}

void LRotatebyreverse(int arr[] , int d , int n) {
    Reverse(arr, 0 , d - 1);
    Reverse(arr , d , n-1);
    Reverse(arr , 0 , n-1);
}

int main() {
    int arr[] = {1 , 2 , 3 , 4 , 5};
    dRoate(arr , 5 , 2);
    for(int i =0 ; i < 5 ; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    int arr2[] = {1 , 2 , 3 , 4 , 5 , 6};
    LRotatebyd(arr2 , 6 , 2);
     for(int i =0 ; i < 6 ; i++) {
        cout << arr2[i] << " ";
    }
    cout << "\n";
    int arr3[] = {1 ,2 , 3 , 4,5};
    LRotatebyreverse(arr3 , 3 , 5);
     for(int i =0 ; i < 5 ; i++) {
        cout << arr3[i] << " ";
    }
}
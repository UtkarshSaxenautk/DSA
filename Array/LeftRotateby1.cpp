#include <iostream>
using namespace std ;

// 1st element of array become last and all other elements 
// take i - 1 place
void LRotate(int arr[] , int n) {
    int temp = arr[0];
    for(int i = 1 ; i < n ; i++) {
        arr[i -1] = arr[i];
        
    }
    arr[n - 1] = temp ;
}


int main() {
     int n = 6 ;
    int arr[n];
    arr[0] = 10;
    arr[1] = 0 ;
    arr[2] = 1;
    arr[3] = 0 ;
    arr[4] = 3 ;
    arr[5] = 5 ;
    LRotate(arr , n);
    for(int i =0 ; i < n ; i++) {
        cout << arr[i] << " " ;
    }
    cout << "\n";
}
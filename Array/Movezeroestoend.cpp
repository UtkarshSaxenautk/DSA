#include <iostream>
using namespace std ;

 void Swap(int x, int y) {
     int temp = x ;
     x = y ;
     y = temp ;
 }


void MOve(int arr[] , int n) {
    int count = 0 ;
    for(int i = 0 ; i < n  ; i++) {
        if(arr[i] != 0) {
            int temp = arr[i];
            arr[i] = arr[count];
            arr[count] = temp ;
            count++ ;
        }
    }
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
    MOve(arr , n);
    for(int i =0 ; i < n ; i++) {
        cout << arr[i] << " " ;
    }
    cout << "\n";
} 


#include <iostream>
using namespace std ;


void reverse(int arr[] , int n) {
    int i =0 ; 
    int j = n -1 ;
    for(i =0 , j = n -1 ; i <= j  ; i++ , j--) {
        int temp = arr[i];
        arr[i]= arr[j];
        arr[j] = temp ;
    }

}

int main() {
    int arr[] = {3 , 6 , 2 , 1 , 9} ;
    for(int i=0 ; i < 5 ; i++) {
        cout << arr[i] << " " ;
    }
    cout << "\n";
    reverse(arr , 5);
    for(int i=0 ; i < 5 ; i++) {
        cout << arr[i] << " " ;
    }
    cout << "\n";
}
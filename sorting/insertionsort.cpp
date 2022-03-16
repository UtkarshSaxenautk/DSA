#include <iostream>
using namespace std ;

void InsertionSort(int arr[] , int n) {
    int i , j, v ;
    for( i = 1 ;i <= n - 1 ; i++ ){
        v = arr[i];
        j = i ;
        while(arr[j -1] > v && j >= 1) {
            arr[j] = arr[j -1];
            j-- ;
        }
        arr[j] = v ;
    }
}

int main() {
     int arr[] = {5 , 7 , 3 , 2 , 9};
    for(int i =0 ; i < 5 ; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    InsertionSort(arr , 5);
     for(int i =0 ; i < 5 ; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
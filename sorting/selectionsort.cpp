#include <iostream>
using namespace std ;


void SelectionSort(int arr[] , int n){
    int i, j , min , temp ;
    for( i= 0 ; i< n- 1 ; i++) {
        min = i ;
        for(j = i ; j < n ; j++) {
            if(arr[j] < arr[min]) {
                min = j ;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp ;
    }
}

int main() {
    int arr[] = {5 , 7 , 3 , 2 , 9};
    for(int i =0 ; i < 5 ; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    SelectionSort(arr , 5);
     for(int i =0 ; i < 5 ; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
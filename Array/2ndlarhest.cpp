#include <iostream>
using namespace std ;


int largest(int arr[] , int n) {
    int res = 0 ;
    for(int i =0 ; i < n ; i++) {
        if(arr[i] > arr[res]) {
            res = i ;
        }
    }
    return res ;
}

int sndlargest(int arr[] , int n) {
    int res = -1 ;
    int lar = largest(arr , n);
    for(int i =0; i < n ; i++) {
        if(arr[i] != arr[lar]) {
             if(res == -1) {
                 res = i ;
             }
             else {
                 if(arr[i] > arr[res]) {
                     res = i ;
                 }
             }
        }
    }
    return res ;
}

int effsecond(int arr[] , int n) {
    int largest = 0 ;
    int res = -1 ;
    for(int i=0 ; i < n ;i++) {
        if(arr[i] > arr[largest]) {
            res = largest ;
            largest = i ;
        }
        else if(arr[i] != arr[largest]) {
            if(res == -1 || arr[i] > arr[res]) {
                res = i ;
            }
        }

    }
    return res ;
}


int main() {
    int arr[] = {3 , 6 , 8 , 2 , 9};
    cout << largest(arr , 5) << "\n";
    cout << sndlargest(arr , 5) << "\n";
    cout << effsecond(arr , 5) << "\n";

}
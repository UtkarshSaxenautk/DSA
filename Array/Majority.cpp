#include <iostream>
using namespace std;


int findmajority(int arr[] , int n){
    for(int i =0 ; i < n ; i++) {
        int count = 1 ;
        for(int j = i ; j < n ; j++) {
            if(arr[j] == arr[i]) {
                count++ ;
            }
        }
        if(count > n / 2) {
            return i ;
        }
    }
    return -1 ;
}

int findeffmajority(int arr[] , int n) {
    int res = 0 , count = 1 ;
    for(int i = 1 ; i < n ; i++){
        if(arr[res] == arr[i]){
            count++ ;
        }
        else {
            count-- ;
        }
        if(count == 0){
            res = i ; count = 1;
        }
    }
    count = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[res] == arr[i]){
            count++ ;
        }
    }
    if(count <= n / 2){
        res = -1 ;
    }
    return res ;
}

int main(){
    int arr[] = {1 , 2, 3 , 3 , 3};
    cout << arr[findmajority(arr , 5)] << "\n";
    cout << arr[findeffmajority(arr ,5)];
}

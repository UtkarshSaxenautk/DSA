#include <iostream>
using namespace std ;

int navie(int arr[] , int n) {
    int res ;
    for(int i = 0 ; i < n ; i++) {
        int count = 0 ;
        for(int j =0 ; j < n ; j++) {
            if(arr[i] == arr[j]) {
                count++ ;
            }
        }
        if(count % 2 != 0) {
            res= arr[i];
        }
    }
    return res ;
}

int Byxor(int arr[] , int n) {
    int res  = 0 ;
    for(int i =0 ; i < n ; i++){
        res = res ^ arr[i];
    }
    return res ;
}

int main() {
    int arr[] = {3 , 4 , 3 ,4 , 4 , 3 , 3 , 5 , 5 };
    cout << navie(arr , 9) << endl;
    cout << Byxor(arr , 9) << endl;
}
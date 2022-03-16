#include <iostream>
using namespace std ;

void OddApprearing(int arr[] , int n) {
    int xors =0  , res1 =0 , res2 = 0 ;
    for(int i= 0 ; i < n; i++) {
        xors = xors ^ arr[i];

    }
    int sn = xors & (~(xors -1));
    for(int i = 0 ; i < n ; i++) {
        if(arr[i] & sn != 0) {
            res1 = res1 ^ arr[i];
        }
        else {
            res2 = res2 ^ arr[i];
        }
    }

    cout << res1 << " " << res2 << "\n"; 
}

void twoOddsnaive(int arr[] , int n) {
    for(int i =0 ; i < n ; i++) {
        int count = 0 ;
        for(int j = 0 ; j < n ; j++) {
            if(arr[i] == arr[j]) {
                count++ ;
            }
        }
        if(count % 2 != 0) {
            cout << arr[i] << " ";
        }
    }
}

int main() {
    int arr[] = {2 , 2 , 4 , 2, 4 , 5 , 4 , 5 , 2 , 3};
    twoOddsnaive(arr , 10);
    OddApprearing(arr , 10);

}
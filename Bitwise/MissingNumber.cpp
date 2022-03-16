#include <iostream>
#include <bits/stdc++.h>
using namespace std ;


int Missing(int arr[] ,int n){
    int max = *max_element(arr , arr + n);
    int total = 0 ;
    for(int i = 1 ; i <= max ; i++) {
        total = total ^ i ;

    }
    int res = 0 ;
    for(int i =0 ; i < n ; i++) {
        res = (res ^ arr[i]);
    }
    return res ^ total ;
}

int main() {
    int arr[] = {1 ,3 ,4};
    cout << Missing(arr , 3);

}
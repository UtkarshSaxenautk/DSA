#include <iostream>
using namespace std ;


void Leader(int arr[] , int n ) {
    for(int i = 0 ; i < n ; i++) {
        bool vl = false ;
        for(int j = i+1 ; j < n ; j++) {
           if(arr[i] <= arr[j]) {
               vl = true ;
               false ;
           }
        }
        if(vl == false) {
            cout << arr[i] << " " ;
        }
    }
    cout << "\n";
}

void Leadereff(int arr[] , int n) {
    int curr_l = arr[n -1];
    cout << curr_l << " ";
    for(int i = n -2 ; i >= 0 ; i--) {
        if(curr_l < arr[i]) {
            curr_l = arr[i];
            cout << curr_l << " ";
        }
    }
    cout << "\n";
}

int main() {
    int arr[] = {7 , 10 , 4, 10 , 6 , 5,2 , 3};
    Leader(arr , 8);
    Leadereff(arr , 8);
}


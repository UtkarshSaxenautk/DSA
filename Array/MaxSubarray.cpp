#include <iostream>
using namespace std ;

int maxSum(int arr[] , int n){
    int res = arr[0];
    for(int i = 0 ; i < n ; i++)
    {
        int curr = 0 ;
        for(int j = i ; j < n ; j++)
        {
            curr = curr + arr[j];
            res = max(res, curr);
        }
    }
    return res ;
}

int effmaxsub(int arr[] , int n){
    int res = arr[0];
    int maxend = arr[0];
    for(int i = 1 ; i < n ; i++)
    {
        maxend = max(maxend + arr[i] , arr[i]);
        res = max(res , maxend);
    }
    return res ;
}

int main() {
    int arr[] = {1 , -2 , 3 , -1 , 2};
    cout << maxSum(arr ,5) << "\n";
    cout << effmaxsub(arr , 5)<< "\n";
}
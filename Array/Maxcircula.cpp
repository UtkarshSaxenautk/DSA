#include <iostream>
using namespace std ;


int maxcircular(int arr[] , int n){
    int res = arr[0];
    for(int i = 0 ;i < n ; i++)
    {
        int curr_max = arr[i];
        int curr_sum = arr[i];
        for(int j= 1 ; j < n ; j++)
        {
            int index = (i + j) % n ;
            curr_sum += arr[index];
            curr_max = max(curr_max , curr_sum);
        }
        res = max(res , curr_max);
    }
    return res ;
}

int maxnormal(int arr[] , int n){
    int res = arr[0] , maxend = arr[0];
    for(int i = 1; i < n ; i++){
        maxend = max(arr[i]+maxend , arr[i]);
        res = max(res , maxend);
    }
    return res ;
}

int circular_subarry(int arr[] , int n){
    int max_nor = maxnormal(arr , n);
    if(max_nor < 0){
        return max_nor ;
    }
    int arr_sum = 0 ;
    for(int i = 0  ;i < n ; i++)
    {
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int max_cir = arr_sum + maxnormal(arr , n);
    return max(max_nor , max_cir);
}

int main()
{
    int arr[] ={5 , -2 , 3 , 4};
    cout << maxcircular(arr , 4) << "\n";
    cout << circular_subarry(arr , 4);
}
#include <iostream>
using namespace std ;


int maxevenodd(int arr[] , int n) {
    int res = 1 ;
    for(int i =0 ; i < n ; i++)
    {
        int curr = 1;
        for(int j = i+1 ; j < n ; j++)
        {
            if((arr[j -1] % 2 == 0 && arr[j] % 2 != 0) || (arr[j -1] % 2 != 0 && arr[j] % 2 == 0)){
                curr++ ;
            }
            else {
                break ;
            }
            
        }
        res = max(res , curr);

    }
    return res ;
}

int effmax(int arr[] , int n){
    int res = 1; 
    int cuee = 1 ;
    for(int i = 1 ; i < n ; i++)
    {
       if((arr[i-1] % 2 == 0 && arr[i] % 2 != 0) || (arr[i -1] % 2 != 0 && arr[i] % 2 == 0)){
                cuee++ ;
                res= max(res , cuee);
        }
        else {
            cuee = 1;
        }

    }
    return res ;
}

int main() {
    int arr[] = {1 , 2, 3, 4 , 6};
    cout << maxevenodd(arr ,5) << "\n";
    cout << effmax(arr , 5) ;
}
#include <iostream>
using namespace std ;

void BubbleSort(int arr[] , int n) {
   for(int i =0 ; i < n ; i++)
   {
       for(int j = 0 ; j < n - i - 1 ; j++)
       {
           if(arr[j] > arr[j +1])
           {
               int temp = arr[j];
               arr[j] = arr[j+1];
               arr[j +1] = temp ;
           }
       }
   }
}

void BubbleSortImproved(int arr[] , int n) {
     int i ,j , temp , swapped = 1 ;
     int count =0 ;
     for(i = n- 1 ; i >= 0 ; i--) {
         swapped = 0;
         for(j = 0 ; j <= i -1 ; j++) {
             if(arr[j] > arr[j+1]) {
                 temp = arr[j];
                 arr[j] = arr[j+1];
                 arr[j+1] = temp ;
                 swapped = 1 ;
                 count++ ;
             }
         }
     }
     cout << count << "\n";
}

int main() {
    int arr[] = {5 , 7 , 3 , 2 , 9};
    for(int i =0 ; i < 5 ; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    BubbleSort(arr , 5);
     for(int i =0 ; i < 5 ; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    int  arr2[] = {3 , 6 , 2 , 4 , 9, 8};
   for(int i =0 ; i < 5 ; i++){
        cout << arr2[i] << " ";
    }
    cout << "\n";
    BubbleSortImproved(arr2 , 6);
    for(int i =0 ; i < 5 ; i++){
        cout << arr2[i] << " ";
    }
    cout << "\n";
}
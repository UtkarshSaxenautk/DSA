#include <iostream>
#include <algorithm>
using namespace std ;

// Merge two sorted array :

// void merge(int a[] , int b[] , int m , int n){
//     int c[m+n];
//     for(int i =0 ; i < m ; i++)
//     {
//         c[i] = a[i];
//     }
//     for(int j = 0 ; j < n ; j++)
//     {
//         c[m + j] = b[j];
//     }
//     sort(c , c+m+n);
//     for(int i = 0  ;i < m+n ; i++)
//     {
//         cout << c[i] << " " ;
//     }

// }


// int main()
// {
//     int a[] = {2 , 5 , 7};
//     int b[] = {1 , 3 , 8 , 9};
//     merge(a , b ,3 ,4);
// }

// void MergeEff(int a[] , int b[] , int m , int n)
// {
//     int i = 0 , j = 0 ;
//     int c[m+n];
//     int k = 0 ;
//     while(i < m && j < n){
//       if(a[i] >= b[j]){
//           c[k] = b[j];
//           j++ ;
//           k++ ;
//       }
//       else{
//           c[k] = a[i];
//           i++ ;
//           k++ ;
//       }
//     }
//     if(i != m -1){
//         while(i < m){
//             c[k] = a[i];
//             i++ ;
//             k++ ;
//         }
//     }
//     if(j != n -1){
//         while(j < n){
//             c[k] = b[j];
//             j++ ;
//             k++ ;
//         }
//     }
//     for(int h = 0 ; h < n+m ; h++)
//     {
//         cout << c[h] << " ";
//     }
// }

// int main()
// {
//     int a[] = {1 , 4 , 5};
//     int b[] = {2 , 6 , 9 , 11};
//     MergeEff(a , b , 3 , 4);
// }

// 

void merge(int a[] , int low , int mid , int high){
    int n1 = mid - low + 1 ;
    int n2 = high - mid ;
    int left[n1];
    int right[n2];
    for(int i =0 ; i < n1 ; i++){   // n1 time taken
        left[i] = a[low+i];
    }
    for(int j = 0 ; j < n2 ; j++){  // n2 time taken 
        right[j] = a[mid+j+1];
    }
    int i = 0 , j = 0 , k = low ;
    while(i < n1 && j < n2){       // min(n1,n2) time taken 
        if(left[i] <= right[j]){
            a[k++] = left[i++];
           
        }
        else {
            a[k++] = right[j++];
            
        }
    }
    while(i < n1)               // max n1 time taken 
        a[k++] = left[i++];
       
    
    while(j < n2)               // max n2 time taken 
        a[k++] = right[j++];
      
    
}


void mergesort(int arr[] , int i , int r){
    if(r > i){
        int m = i + (r -i)/2 ;
        mergesort(arr , i , m);
        mergesort(arr , m+1 , r);
        merge(arr , i , m , r);   // overall theta(n) tiem taken 
    }
}

int main() {
    int arr[] = {2 , 5 , 6 , 3 , 1};
   int l = 0 , r = 4 ;
   mergesort(arr , l , r);   // theta(n)
   for(int x : arr){
       cout << x << " " ;
   }
}







#include <iostream>
using namespace std ;

void merge(int *arr , int low , int high , int mid){
  int a , b , c , temp[100];
  a = low ;
  b = high;
  c = mid+1 ;
  while(a <= mid && b <= high){
      if(arr[a] < arrr[b])
      {
          temp[c] =  arr[a];
          c++ ;
          a++ ;
      }
      else {
          temp[c] = arr[b];
          c++ ;
          b++ ;
      }
  }
}
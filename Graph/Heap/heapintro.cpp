#include <iostream>
#include <cmath>
#include <vector>
using namespace std ;


void swap(int *a , int *b){
    int temp = *a ;
    *a= *b ;
    *b = temp ;
}

class Minheap {
  vector<int> arr ;
  //int size  ;
  int cap ;
  public:
  Minheap(int c) {
      cap = c ;
      //arr = new  int[cap];
     // size = 0;
  }
  int left(int i){
      return 2 * i +1 ;
  }
  int right(int i){
      return 2 * i + 2;
  }
  int parent(int i){
      return floor((i -1)/2);
  }

  void heapify(vector<int> arr , int n , int i){
      int minimum = i ;
      int l =  2 * i + 1 ;
      int r = 2 * i + 2 ;

      if(l < n && arr[l] < arr[minimum]){
          minimum = l ;
      }
      if(r < n && arr[r] < arr[minimum]){
         minimum = r ;
      }

      if(minimum != i){
          swap(&arr[i] , &arr[minimum]);

          heapify(arr , n , minimum);
      }
  }

  void Insert(int x){
      if(arr.size() == cap){
          return ;
      }
      arr.push_back(x);
    //   int i = arr.size() -1 ;
    //   while(i != 0 && arr[parent(i)] > arr[i]){
    //       swap(&arr[i] , &arr[parent(i)]);
    //       i = parent(i);
    //   }
       heapify(arr , arr.size() ,);
  }

  void Display(){
      for(int i =0 ; i < arr.size() ; i++){
          cout << arr[i] << " " ;
      }
  }
};


int main() {
    Minheap m(6) ;
    m.Insert(4);
    m.Insert(1);
    m.Insert(17);
    m.Insert(24);
    m.Insert(8);
    m.Display();

}


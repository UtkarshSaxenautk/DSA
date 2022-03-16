#include <iostream>
using namespace std ;

void printgroups(int arr[] , int n){
    for(int i = 1 ; i < n ; i++)
    {
        if(arr[i] != arr[i-1]){
            if(arr[i] != arr[0]){
                cout << "From " << i << " to " ;
            }
            else {
                cout << i -1 << "\n";
            }
        }
    }
    if(arr[n -1] != arr[0]){
        cout << n -1 << "\n" ;
    }
}

int main() {
    int arr[] = {0 , 0 , 1 , 0 , 0 , 0 , 1 , 1 , 0 , 1};
    printgroups(arr ,10);

}
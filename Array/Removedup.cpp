#include <iostream>
#include <algorithm>
using namespace std ;

 int remDups(int arr[], int n)
{
	int res = 1;

	for(int i = 1; i < n; i++)
	{
		if(arr[res - 1] != arr[i])
		{
			arr[res] = arr[i];
			res++;
		}
	}

	return res;
}

int remdup(int arr[] , int n) {
    int temp[n];
    temp[0] = arr[0];
    int res = 1 ;
    for(int i=0 ; i < n ; i++) {
        if(temp[res- 1] != arr[i]) {
            temp[res] = arr[i];
            res++ ;
        }
    }
    for(int i =0 ; i < res ; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {10 , 20 , 30 , 20 , 30 , 30};
    cout << "Before Removal : " << "\n";
    for(int i =0 ; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    sort(arr , arr + 6);
    int  n = remDups(arr , 6);
    cout << "After Removal : " << "\n";
     for(int i =0 ; i < n ; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";



}
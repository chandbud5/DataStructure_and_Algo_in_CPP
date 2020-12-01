#include <iostream>

using namespace std;

void bubble_rec(int arr[], int n);

int bubble_recursion(){

    int arr[10] = {2, 5, 1, 6, 7, 8, 9, 0, 10, 4};
    bubble_rec(arr, 10);

    for(int i=0; i<10; i++){
        cout << arr[i] << "\t" ;
    }

    return 0;
}

void bubble_rec(int arr[], int n){

    if(n==1)
        return;

    int t;
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            t = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = t;
        }
    }

    bubble_rec(arr, n-1);

}


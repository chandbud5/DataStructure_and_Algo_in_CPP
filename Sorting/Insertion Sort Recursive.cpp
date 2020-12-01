#include <iostream>

using namespace std;

void ins_sort_rec(int arr[], int n);

int main(){

    int ar[10] = {2, 5, 0, 1, 3, 21, -7, 8, 4, 6};
    ins_sort_rec(ar, 10);

    for(int i=0; i<10; i++){
        cout << ar[i] << "\t" ;
    }

    return 0;
}

void ins_sort_rec(int arr[], int n){

    if(n <= 1)
        return;

    ins_sort_rec(arr, n-1);

    int key = arr[n-1];
    int j = n-2;

    while(j>=0 && arr[j] > key){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}

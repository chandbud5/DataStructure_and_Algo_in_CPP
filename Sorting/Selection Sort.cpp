#include<iostream>
using namespace std;

int main(){

    int n, temp, min_index;
    cout << "Enter the capacity of array" << endl;
    cin >> n;

    int arr[n];
    cout << "Enter the values" << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<n; i++){
        min_index = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min_index])
            min_index = j;
        }
        if(min_index != i){
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }

    cout << "Sorted Array is \t";
    for(int i=0; i<n; i++)
        cout << arr[i] << "  ";

    return 0;
}

#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter the capacity of queue" << endl;
    cin >> n;

    int arr[n];
    cout << "Enter the values" << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "Sorted Array is \t";
    for(int i=0; i<n; i++)
        cout << arr[i] << "  ";

    return 0;
}

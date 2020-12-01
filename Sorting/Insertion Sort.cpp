#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {12, -8, 2, 4, 26, 32, 9, 0 -5, 1};
    int j, key;
    
    for(int i=0; i<10; i++){
        key = arr[i];
        j = i-1;
        
        // Inserting element at correct position in a sorted array
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    for(int i=0; i<10; i++){
        cout << arr[i] << "\t";
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(){

    int i, n, key;
    cin >> n;
    cout << "\n";
    int* arr = new int[n]; //dynamically allocating array

    for(i = 0; i < n; i++){ //inputting numbers into array
        cin >> arr[i];
        cout << "\n";
    }

    for(i = 1; i < n; i++){ //Insertion Sort
        key = arr[i];
        while(i >= 0 && key > arr[i-1]){
            arr[i] = arr[i-1];
            i--;
        }
        arr[i-1] = key;
    }

    for(i = 0; i < n; i ++){
        cout << arr[i] << ";";
    }
}
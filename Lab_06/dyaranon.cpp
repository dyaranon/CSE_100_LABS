#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

void print(int* arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << ";";
    }
}

int partition(int* arr, int low, int high){
    int randomPartition = low + rand() % (high - low);
    int temp = arr[high];
    arr[high] = arr[randomPartition];
    arr[randomPartition] = temp;

    int x = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] <= x){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

return i + 1;
}

void quickSort(int* arr, int low, int high){
    if(low < high){
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void input(){
    int size;
    cin >> size;
    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, size - 1);
    print(arr, size);
}

int main(){
    input();
return 0;
}
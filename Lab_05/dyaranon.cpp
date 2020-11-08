#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;

void print(int* arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << ";";
    }
}

void maxHeapify(int* arr, int i, int size){
    int leftChild = (2*i + 1);
    int rightChild = (2*i + 2);
    int largest;
    if(leftChild < size && arr[leftChild] > arr[i]){
        largest = leftChild;
    }
    else{
        largest = i;
    }
    if(rightChild < size && arr[rightChild] > arr[largest]){
        largest = rightChild;
    }
    if(largest != i){
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, largest, size);
    }
}

void buildMaxHeap(int* arr, int size){
    for(int i = trunc((size / 2)); i >= 0; i--){
        maxHeapify(arr, i, size);
    }
}

void heapSort(int* arr, int size){
    buildMaxHeap(arr, size);
    for(int i = size - 1; i >= 0; i--){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        maxHeapify(arr, 0, i);
    }
}

void input(){
    int size;
    cin >> size;
    int* arr = new int[size];

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    heapSort(arr, size);
    print(arr, size);
}

int main(){
    input();
return 0;
}
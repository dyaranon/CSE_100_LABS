#include <iostream>
#include <cmath>

using namespace std;

void print(int* arr, int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << ";";
    }
}

void merge(int* arr, int low, int mid, int high){
    int i = low; //Beginning of subarray 1
    int j = mid + 1; //Beginning of subarray 2
    while (j <= high && i <= mid){ //Ends once size of subarray < 1 
        if (arr[i] < arr[j]){ 
            i++;
        }
        else{
            int insert = arr[j];
            for (int k = j; k > i; k--){
                arr[k] = arr[k-1];
            }
            arr[i] = insert;
            mid++;
            i++;
            j++;
        }
    }
}

void mergeSort(int* arr, int low, int high){
    if(low < high){
        int mid = trunc((low+high) / 2);
        mergeSort(arr, low, mid);//left-side, mid is new high
        mergeSort(arr, mid + 1, high);//right-side
        merge(arr, low, mid, high);//combine left and right, actual sorting is done here
    }
}

int main(){

    int size;
    cin >> size;
    int* arr = new int[size];

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    mergeSort(arr, 0, size - 1);
    print(arr, size);

return 0;
}
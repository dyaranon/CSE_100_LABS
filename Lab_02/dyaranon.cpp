#include <iostream>
#include <cmath>

using namespace std;

int binarySearch(int* arr, int num, int low, int high){
    while(low <= high){ // while the size of the array > 1
        int mid = trunc(((low + high) / 2));
            if(num == arr[mid]){
                return mid;
            }
            else if (num < arr[mid]){
                high = mid - 1;
            }
            else{ //num > arr[mid]
                low = mid + 1;
            }
    }
    return -1;
}

int main(){
    int size;
    cin >> size;
    int num;
    cin >> num;

    int found = -1;
    int* arr = new int[size];

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    found = binarySearch(arr, num, 0, size);
    
    cout << found;

return 0;
}
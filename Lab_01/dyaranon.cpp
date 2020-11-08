#include <iostream>

using namespace std;

int main(){
    int size;
    int num; 
    int element;
    int found = -1;

    //cout << "Enter the sie of the array: ";
    cin >> size;
    int* arr = new int[size];

    //cout << "Enter the number we are searching for in the array: ";
    cin >> num;

    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < size; i++){
        if(num == arr[i]){
            found = i;
            break;
        }
    }

    cout << found;
return 0;
}
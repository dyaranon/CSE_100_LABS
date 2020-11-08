#include <iostream>
#include <list>
#include <vector>
#include <cmath>

using namespace std;

void print(vector<list<float>> vect, int size){
    for(int i = 0; i < size; i++){
        int size = vect[i].size();
        for(int j = 0; j < size; j++){
            cout << vect[i].front();
            vect[i].pop_front();
            cout << "" << endl;
        }
    }
}

vector<list<float>> bucketSort(float* arr, int size){

   vector<list<float> > vect;
   for(int i = 0; i < size; i++){
       list<float> empty_list;
       vect.push_back(empty_list);
   }

   for(int i = 0; i < size; i++){
       int index = trunc(size * arr[i]);
       vect[index].push_front(arr[i]);
    }

    for(int i = 0; i < size; i++){
        vect[i].sort();
    }
    
return vect;
}

void input(){
    int size;
    float elements;
    cin >> size;
    float* arr = new float[size];
    for(int i = 0; i < size; i++){
        cin >> elements;
        arr[i] = elements;
    }
    vector<list<float>> sorted_output = bucketSort(arr, size);
    print(sorted_output, size);
}

int main(){
    input();
return 0;
}
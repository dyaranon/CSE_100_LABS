#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

void print(vector<vector<int>> v){
    
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << ";";
        }
        cout << "" << endl;
    }
}

vector<vector<int>> countingSort(vector<vector<int>> v, int num_vectors, int col, int count){

    vector<vector<int>> output;
    for(int i = 0; i < num_vectors; i++){
        vector<int> new_vect;
        for(int j = 0; j < 10; j++){
            new_vect.push_back(0);
        }
        output.push_back(new_vect);
    }

    int C[10] = {0};

    //Counting how many repeated values are in column col, histogram
    for (int i = 0; i < num_vectors; i++){
        C[(v[i][col] % 10)]++;
    }

    //cumulative histogram
    for (int i = 1; i < 10; i++){
        C[i] += C[i - 1];
    }

    //Sorting
    for (int i = num_vectors - 1; i > -1; i--){
        output[ C[v[i][col] % 10] - 1 ] = v[i];
        C[(v[i][col] % 10)] --;
    }
return output;
}

void radixSort(vector<vector<int>> v, int num_vectors){
    int count = 0;
    for(int col = 9; col > -1 ; col--){
        count++;
        v = countingSort(v, num_vectors, col, count);
    }
    print(v);
}

void input(){
    int num_vectors, str_to_int;
    string input_values; //digits 0 - 9 separated by spaces

    cin >> num_vectors;
    
    vector<vector<int>> v;

    for(int i = 0; i < num_vectors; i++){
        //ws(cin); //Clears whitespace so that getline can run
        std::vector<int> newVect;
        //getline(cin, input_values, '\n');
        for(int j = 0; j < 10; j++){
            //char digit = input_values[j*2]; // "0 1 2 3 4 5 6 7 8 9"
            //str_to_int = (int)digit % 48;
            int num;
            cin >> num;
            newVect.push_back(num);
        }
        v.push_back(newVect);
    }
    
    radixSort(v, num_vectors); //v[0...n], v[0] < v[n]
}

int main(){
    input();
return 0;
}
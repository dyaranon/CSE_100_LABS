#include <iostream>
#include <list>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int hashFunction(int key, int size){
    if(key < size){
        return key;
    }
    else{
        return key % size;
    }
}

void print(vector<list<int>> hashTable, int size){
    vector<list<int>> hashCopy = hashTable;
    for(int i = 0; i < size; i++){
        cout << i << " : ";
        for(int j = 0; j < hashTable[i].size(); j++){
            if(j == hashTable[i].size() - 1){
                cout << hashCopy[i].front();
                hashCopy[i].pop_front();
            }
            else{
               cout << hashCopy[i].front() << "->";
               hashCopy[i].pop_front();
            }
        }
        cout << "" << endl;
    }
     cout << "++++++++++++++++++++" << endl;
}

vector<list<int>> Delete(vector<list<int>> hashTable, int num, int size){
   
    int index = hashFunction(num, size);
    int original_size = hashTable[index].size();

    auto it = find(hashTable[index].begin(), hashTable[index].end(), num);
    if(hashTable[index].end() != it){
        hashTable[index].erase(it);
    }

    if(original_size != hashTable[index].size()){
        cout << num << " : DELETED" << endl;
        cout << "++++++++++++++++++++" << endl;
    }
    else{
        cout << num << " : DELETE FAILED" << endl;
        cout << "++++++++++++++++++++" << endl;
    }

return hashTable;
}

vector<list<int>> Insert(vector<list<int>> hashTable, int num, int size){
    int index = hashFunction(num, size);
    hashTable[index].push_front(num);

return hashTable;
}

vector<list<int>> Search(vector<list<int>> hashTable, int num, int size){

    int index = hashFunction(num, size);

    auto it = find(hashTable[index].begin(), hashTable[index].end(), num);

    if(hashTable[index].end() == it){
        cout << num << " : NOT FOUND" << endl;
        cout << "++++++++++++++++++++" << endl;
    }
    else{
        int pos = distance(hashTable[index].begin(), it);
        cout << num << " : FOUND AT " << index << "," << pos << endl;
        cout << "++++++++++++++++++++" << endl;
    }

return hashTable;
}

vector<list<int>> hashTableOperations(vector<list<int>> hashTable, string char_input, int num, int size){

    if(char_input == "i"){
       hashTable = Insert(hashTable, num, size);
    }
    else if(char_input == "d"){
       hashTable = Delete(hashTable, num, size);
    }
    else if(char_input == "s"){
       hashTable = Search(hashTable, num, size);
    }
    else if(char_input == "o"){
        print(hashTable, size);
    }
    
return hashTable;
}

void input(){
  int size;
  cin >> size;
  cin.ignore();

  //Initializing hash table
  vector<list<int>> hashTable;
    for(int i = 0; i < size; i++){
        list<int> emptyList;
        hashTable.push_back(emptyList);
    }

  int num = 0;
  string full_input, char_input, int_input;

  getline(cin, full_input);
  if(full_input != "o"){
      char_input = full_input[0];
      int_input = full_input[2];
      for(int i = 3; i < full_input.size(); i++){
        int_input += full_input[i];
      }
    num = stoi(int_input);
  }
  else{
      char_input = "o";
  }

  while(char_input != "e"){
      hashTable = hashTableOperations(hashTable, char_input, num, size);
      getline(cin, full_input);
      if(full_input != "o"){
        char_input = full_input[0];
        int_input = full_input[2];
        for(int i = 3; i < full_input.size(); i++){
            int_input += full_input[i];
        }
      num = stoi(int_input);
      }
      else{
        char_input = "o";
      }
    }

}

int main(){
    input();
return 0;
}

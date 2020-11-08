#include <iostream>
#include <stdlib.h>

using namespace std;

void Print(int* hashTable){
    cout << "++++table printout++++"<<endl;
    for(int i = 0; i < 13; i++){
        if(hashTable[i] != -1){
            cout << hashTable[i];
        }
        cout << "" << endl;
    }
}

bool isFull(int current_size){
    return (current_size == 13);
}

int h1(int key){
    return key % 13;
}

int h2(int key){
    return 1 + (key % 11);
}

void hashFunction(int* hashTable, int key){
    int index = h1(key);
    if(hashTable[index] == -1){
        hashTable[index] = key;
    }
    else{
        int i = 1;
        while(true){
            if(hashTable[(h1(key) + i * h2(key)) % 13] == -1){
                hashTable[(h1(key) + i * h2(key)) % 13] = key;
                break;
            }
            i++;
        }
    }

}

void Search(int* hashTable){
    cout << "++++searching++++" << endl;
    int input, notFound, i;
    while(true){
        i = 1;
        notFound = 0;
        cin >> input;
        if(input == -2){
            break;
        }
        while(hashTable[h1(input) + i * h2(input) % 13] != input){
            if(i > 13){
                cout << "NOT_FOUND" << endl;
                notFound++;
                break;
            }
            i++;
        }
        if(notFound == 0){
            cout << h1(input) + i * h2(input) % 13 << endl;
        }
    }
}

void Delete(int* hashTable){
    cout << "++++deleting++++" << endl;
    int input, notFound, i;
    while(true){
        notFound = 0;
        i = 1;
        cin >> input;
        if(input == -3){
            break;
        }
        while(hashTable[h1(input) + i * h2(input) % 13] != input){
            if(i > 13){
                notFound++;
                break;
            }
            i++;
        }
        if(notFound == 0){
            hashTable[h1(input) + i * h2(input) % 13] = -1;
        }
    }
}

void input(int* hashTable){
    int input, current_size = 0;
    while(true){
        cin >> input;
        if(input == -1){
            break;
        }
        if(!isFull(current_size)){
            current_size++;
            hashFunction(hashTable, input);
        }
    }
    Print(hashTable);
    Search(hashTable);
    Delete(hashTable);
    Print(hashTable);

}

int main(){
    int* hashTable = new int[13];
    for(int i = 0; i < 13; i++){
        hashTable[i] = -1; //Initialize all values to -1
    }
    input(hashTable);
return 0;
}
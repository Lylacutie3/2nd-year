/*VILLANUEVA, LYLA JANE L.
 BSIT - 2A
 Fri, November 8 2024
 Closed Hashing
*/
#include <iostream>
#define BUCKET_SIZE 5

using namespace std;
struct Node{
    int data[BUCKET_SIZE];
    int last;
    Node():last(0){}
};

class Close {
private:
    Node hash; //declare 
    void initialized(){ //initialized the data inside node
        for(int i = 0; i < BUCKET_SIZE; i++){
            hash.data[i] = -1;
        }
    }
    bool iffull(){
        return hash.last == 5;
    }
    bool ifempty(){
        return hash.last == -1;
    }
public:
    Close(){
        initialized();
    }
    void insert(int x){
        if(iffull()){ //ask if full
            cout << "array is full";
            cin.ignore(); cin.get();
            return; //return if full
        }
        int index = x % BUCKET_SIZE;
        //linear probing

        if(hash.data[index] < 0){
            hash.data[index] = x; 
            ++hash.last;
        }else{
            if (hash.data[index] == x) {
                return; //duplicate input not allow
            }
            for(int i = index; i <= index + hash.last; i++){ //circ
                if(hash.data[i%BUCKET_SIZE] == -1){//making sure that probing will not be in deleted slot
                    hash.data[i%BUCKET_SIZE] = x;
                    ++hash.last;
                    return;
                }
            }
        }
    }

    int search(int x){
        if (ifempty()) {// ask if empty
            return -1;
        }
        int index =  x % BUCKET_SIZE; ;
        for(int i = index; i <= index + hash.last; i++){
            if(hash.data[index] == x){
                return index;
        }} //proccessed on searching 
        return -1;
    }

    void remove(int x){
        if (ifempty()) {
            cout << "array is empty";
            cin.ignore(); cin.get();
            return;
        }
        if(search(x) > -1){
            hash.data[search(x)] = -2; //-2 deleted
        }else{
            cout << "data not found\n";
            cin.ignore();cin.get();
        }
    }

    void display(){
        if (ifempty()) {
            cout << "array is empty";
            return;
        }
        cout << "Index   Elements\n";
        for(int i = 0; i < BUCKET_SIZE; i++){
                cout << "  "<< i << "\t  " << hash.data[i] << "\n";
    }
    }

};

int menu(){
    int choice;
    system("clear");
    cout << "CLOSED HASHING\n";
    cout << "1. Insert\n";
    cout << "2. Remove\n";
    cout << "3. Search\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";
    cin >> choice;
    return choice;
}
int main(){
    Close c;
    int x;
    while (true) {
        switch (menu()) {
            case 1: system("clear");cout << "Input data to insert: "; cin >> x; c.insert(x); break;
            case 2: system("clear");cout << "Input data to remove: "; cin >> x; c.remove(x); break;
            case 3: system("clear");cout << "Input data to search: "; cin >> x; 
                    (c.search(x) < 0)? cout << "data not found": cout << "Index: " << c.search(x);
                    cin.ignore(); cin.get();break;
            case 4: system("clear");c.display();cin.ignore(); cin.get(); break; 
            case 5: return 0;break;
            default: cout << "Invalid choice\n"; cin.ignore(); cin.get();break;
        }
    }
    return 0;
}
/*VILLANUEVA, LYLA JANE L.
 BSIT - 2A
 Fri, November 8 2024
 Open Hashing
*/
#include <cstddef>
#include <iostream>
#define BUCKET_SIZE 10

using namespace std;

struct Node{ 
    int data;
    Node* next;
    Node(int x):data(x),next(NULL){} //initialized
};

class Open {
private:
    Node *bucket[BUCKET_SIZE]; //declare an node array 
public:
    Open(){ //initialized node array to NULL
        for(int i=0;i<BUCKET_SIZE;i++){
            bucket[i]=NULL;
        }
    }
    void insert(int x){
        Node *newNode = new Node(x);
        if(bucket[x%BUCKET_SIZE] == NULL){ // if the head is empty
            bucket[x%BUCKET_SIZE] = newNode; //add to head
        }else{
            Node *p = bucket[x%BUCKET_SIZE];
                while(p->next != NULL && p->data != x ){ //look for the data and avoid duplicates
                    p = p->next;
                }
                if (p->next == NULL  && p->data != x) { //if the data is not found
                    p->next = newNode;
                    return;
                }
        }
    }

    void remove(int x){
        int index = x % BUCKET_SIZE;
        if(bucket[index] != NULL){
            Node *p = bucket[index]; //pointer of header
            Node *q = NULL;
            if(p->data == x){ //if the head will be remove
                bucket[index] = p->next;
                delete p;
                return;
            }
            while(p != NULL && p->data != x){ //look for the data
                q = p;
                p = p->next;
            } 
            if (p == NULL) { //if the data is not found
                cout << "no such data in the bucket." << endl;
                cin.ignore();cin.get();  
                return;
            }
            q->next = p->next;
            delete p;
        }else{
            cout << "The Bucket is empty" << endl;
            cin.ignore();cin.get();
        }
    }

    void display(){
        cout << "Index   Elements\n";
        for(int i = 0; i < BUCKET_SIZE; i++){
            Node *p = bucket[i];
            cout << "  "<< i << "\t ";
            while (p != NULL) {
                cout << p->data << "->";
                p = p->next;
            }cout << "NULL\n";
        }
    }

};

int menu(){ //menu for choices 
    int choice;
    system("clear");
    cout << "OPEN HASHING\n";
    cout << "1. Insert\n";
    cout << "2. Remove\n";
    cout << "3. Display\n";
    cout << "4. Exit\n";
    cin >> choice;
    return choice;
}
int main(){ 
    Open o;
    int x;
    while (true) {
        switch (menu()) {
            case 1: system("clear");cout << "Input data to insert: "; cin >> x; o.insert(x); break;
            case 2: system("clear");cout << "Input data to remove: "; cin >> x; o.remove(x); break;
            case 3: system("clear");o.display();cin.ignore(); cin.get(); break; 
            case 4: return 0;break;
            default: cout << "Invalid choice\n"; cin.ignore(); cin.get();break;
        }
    }
    return 0;
}
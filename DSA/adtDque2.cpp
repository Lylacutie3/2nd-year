#include <cstddef>
#include <iostream>
#include <malloc/_malloc_type.h>

using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int x):data(x),prev(NULL),next(NULL){}
};

class Deque{
private:
    Node* front;
    Node* rear;
public:
    Deque():front(NULL),rear(NULL){}

    void equeF(int x){
        Node* temp = new Node(x);
            if(front != NULL){
                temp->next = front;
                front->prev = temp;
                front = temp;   
            }else{
                rear = temp; 
                front = temp;
            }
    }

    void equeR(int x){
        Node* temp = new Node(x);
            if(rear != NULL){
                temp->prev = rear;
                rear->next = temp;  
                rear = temp;                                           
            }else{
                rear = temp; 
                front = temp;
            }
        }

    void dequeF(){
        Node* temp;

        if(front == NULL){
            cout << "List is empty";
            return;
        }
        temp = front;
        front = front->next;
        if(front != NULL)
            front -> prev = NULL;
        else
            rear = NULL;
        delete temp;
        }

    void dequeR(){
        Node* temp;

        if(rear == NULL){
            cout << "List is Empty";
            return;
        }
        temp = rear;
        rear = rear->prev;
        if(rear != NULL)
            rear->next = NULL;
        else
            front = NULL;
        delete temp;
    }
    

    void peekF(){
        if(front == NULL){
            cout << "List is empty";
            return;
        }
        cout << "FRONT: " << front->data;
    }

    void peekR(){
        if(rear == NULL){
            cout << "List is empty";
            return;
        }
        cout << "REAR: " << rear->data;
    }

    void display(){

        if(front == NULL or rear == NULL){
            cout << "List is empty";
            return;
        }
        Node* temp = front;
        while(temp!= NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }

    
};

int menu(){
    int pick;
    cout << "\n1. Eque Front" << endl;
    cout << "2. Eque Rear" << endl;
    cout << "3. Deque Front" << endl;
    cout << "4. Deque Rear" << endl;
    cout << "5. Peek Front" << endl;
    cout << "6. Peek Rear" << endl;
    cout << "7. Display All" << endl;
    cout << "8. Exit" << endl;
    cin >> pick;
    return pick;
}

int main(){
    Deque u;
    int x;
    while(true){
    switch(menu()){
        case 1: cout << "Number to ADD: "; cin >> x;u.equeF(x); break;
        case 2: cout << "Number to ADD: "; cin >> x;u.equeR(x); break;
        case 3: u.dequeF();break;
        case 4: u.dequeR();break;
        case 5: u.peekF();break;
        case 6: u.peekR();break;
        case 7: u.display();break;
        case 8: exit(0);
        default: cout << "INVALID INPUT";break;

    }}
}
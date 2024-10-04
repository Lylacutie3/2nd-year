/* VILLANUEVA, LYLA JANE L
    BSIT- 1A
    Write the Pointer Implementation of ADT Queue in OOP/C++
*/
#include <iostream>
using namespace std;

struct Node{
    int data; 
    Node* next;
    Node():data(),next(NULL){} // constructor 
};

class QueueP{
    private:
        Node *head;
    public:
        QueueP():head(NULL){} //initialize head 
        void enqueue(Node s){ //add new node
                Node *newNode = new Node(s); //create new node
                Node *p, *q; // declare pointers
                p = q = head; // initialized pointers
                if (head == NULL){  // if the head is null
                    head = newNode; // puting the evalue into head
                }else{
                    while (p!= NULL){ //look for the last node
                        q = p;
                        p = p->next;
                }q->next = newNode; //putting the value into the next of last node
                }
        }
        void dequeue(){
            if(head == NULL){ //check if the list is empty
                cout << "Your List is EMPTY."<<endl;
                cin.ignore();
                cin.get();
            }else {
                Node* temp = head; //declare and initialize temp 
                head = head->next; // initialize head to next
                cout << "Remove Number: " << temp->data << endl; //print the number will be remove
                delete temp; // delete the prev head or temp
                cout << "Press Enter to continue." << endl; 
                cin.ignore();
                cin.get();
            }
        }
        void front1(){
            if(head == NULL){ //check if the list is empty
                cout << "Your List is EMPTY."<<endl;
            }else {
                cout << "Front: " << head->data << endl; // show the head or front
        }
            cout << "Press Enter to continue." << endl; 
            cin.ignore();
            cin.get();
        }
        void rear1(){
            if(head == NULL){//check if the list is empty
                cout << "Your List is EMPTY."<<endl;
            }else {
                Node *p = head;
                while (p->next != NULL){ // look for last node
                    p = p->next;
                }
                cout << "Rear: " << p->data << endl; // show the  tail or rear
        }   
            cout << "Press Enter to continue." << endl;
            cin.ignore();
            cin.get();
        }
        void displayAll(){
            if(head == NULL){
                cout << "Your List is EMPTY."<<endl; //check the list if its empty
            }else{
                Node *p = head;
                int x = 1;
                while (p != NULL){
                    cout << x++ << ". "<< p->data <<endl; // print all the data inside the list
                    p = p->next;
            }
        }
            cout << "Press Enter to continue." << endl;
            cin.ignore();
            cin.get();
        }
};

int menu(){
    system("clear");
    int pick; 
    cout << "MENU:\n" << endl;
    cout << "1. ENQUEUE" << endl;
    cout << "2. DEQUEUE" << endl;
    cout << "3. FRONT" << endl;
    cout << "4. REAR" << endl;
    cout << "5. DISPLAY ALL" << endl;
    cout << "6. EXIT" << endl;
    cout << "Pick a number: ";
    cin >> pick;
    return pick;
}

int main(){
    QueueP q;
    Node s;
    while(true){
        switch(menu()){
            case 1: system("clear"); cout << "\nENQUEUE\n" << endl;
                    cout << "Add number: "; cin >> s.data; q.enqueue(s); break;
            case 2: system("clear"); cout << "\nDEQUEUE\n" << endl;
                    q.dequeue(); break;
            case 3: system("clear"); cout << "\nVIEW FRONT\n" << endl;
                    q.front1(); break;
            case 4: system("clear"); cout << "\nVIEW REAR\n" << endl;
                    q.rear1(); break;
            case 5: system("clear"); cout << "\nVIEW DISPLAY ALL\n" << endl;
                    q.displayAll(); break;
            case 6: exit(0);
        }
    }
return 0;
}
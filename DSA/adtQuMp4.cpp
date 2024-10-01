/* VILLANUEVA, LYLA JANE L. 
   BSIT - 1A
   Write the Array Implementation of ADT Queue in OOP/C++ 
   Includes - MENU, ENQUEUE, DEQUEUE, FRONT, REAR, DISPLAY ALL, EXIT
*/

#include <iostream>
#define MAX 5
using namespace std;

struct Que{
    int data[MAX];
    int f, r, ctr; 
    Que(): f(0), r(-1), ctr(0){} //i made f(0) cause i dont want to add another statement to initialize 
};

class MyQue{
    private:
        Que q;
        bool isFull(){
            return q.ctr == MAX;
        }
        bool isEmpty(){
            return q.ctr == 0;
        }
    public:
        void enqueue(int x){
            if(isFull()){
                cout << "Queue is full!" << endl;
                cin.ignore();
                cin.get(); 
            }else{ //here i removed the conditional statement is empty (cause i cant make it work)
                q.data[q.r = (q.r+1) % MAX] = x; //
                q.ctr++;
            }
        }
        void dequeue(){
            if(isEmpty()){
                cout << "Queue is empty! " << endl;
            }else{
                //it shows the number remove and the index (ofc its the q.f because of FIFO)
                cout << "Number is remove: " << "[" << q.f <<"] " << q.data[q.f] << endl;
                //the q.f increment because the previous was remove (i made it modulo too cause its circular)
                q.f = (q.f+ 1) % MAX; 
                q.ctr--; //reduce the ctr cause the number reduce
            }
            cin.ignore();cin.get();
        }
        int frnt(){
            return (isEmpty())? -1 :q.data[q.f];//return -1 if its empty
        }
        int rear(){
            return (isEmpty())? -1 :q.data[q.r];//use this cause shorter and cooler hehe
        }
        void display(){
            if(isEmpty()){ //also ask if empty
                cout << "Queue is empty!  ";
            }else{
                for(int i = 0; i < q.ctr;i++) { //loop to print all the data
                   //use modulo here again to print circular
                   int p = (q.f + i) % MAX; // (1 + 0) print 1 while q.f -> q.r (1 + 4) print 0
                   cout << i+1 << ". [" << p << "] " <<q.data[p] << endl;  
                }
           }       
            cin.ignore();cin.get();
        }
};

int menu(){
    int pick;
    system("clear");
    cout << "MENU:\n" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Front" << endl;
    cout << "4. Rear" << endl;
    cout << "5. Display All" << endl;
    cout << "6. Exit" << endl;
    cout << "Pick an option: ";
    cin >> pick;
    return pick;
}

int main(){
    MyQue mq;
    int x;
    while (true) {
        switch(menu()) {
            case 1: system("clear"); cout << "ENQUEUE (ADD)\n" << "Add a number: "; cin >> x; mq.enqueue(x);break;
            case 2: system("clear"); cout << "DEQUEUE (REMOVE)\n"; mq.dequeue();break;
            case 3: system("clear"); cout << "VIEW FRONT (HEAD)\n" << "Front: ";
                 (mq.frnt() == -1) ? cout <<"Queue is Empty": cout << mq.frnt();cin.ignore();cin.get();break;
            case 4: system("clear"); cout << "VIEW REAR (TAIL)\n" << "Rear: ";
                 (mq.rear() == -1) ? cout << "Queue is Empty" : cout << mq.rear();cin.ignore();cin.get();break;
            case 5: system("clear"); cout << "DISPLAY ALL (ELEMENTS WITH INDEX)\n"; mq.display();break;
            case 6: system("clear"); exit(0);break;
            default:system("clear"); cout << "Invalid choice!"<< endl;cin.ignore();cin.get();break;
        }
    }
}
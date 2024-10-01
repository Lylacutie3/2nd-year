/*VILLANUEVA, LYLA JANE L.
 BSIT-2A TUE, SEP 19, 2024
 STUDENT RECORD PROGRAM USING POINTERS
 using ADT Operation with File Handling*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Info{//struct consist of info of students
    string name;
    int q1;
    int q2;
    int q3;
};
struct Node{
    Info student;//info of students
    Node* next;
    //constructor, this use to easier way to create a new node
    Node(Info s) : student(s), next(NULL){}
    /*Info s means it deaclear the identifier s is a big as a info struct
    so the student inside the Node which is a big as info struct will receive a data from s struct
    next(NULL) this initialized the next is will be NULL
    */
};

class Record {
private:
    Node* head; //create a link list
public:
    Record(): head(NULL){} //initialized the head linklids from record into null
    void add(Info s){ //add a student
        Node* newNode = new Node(s);
        Node* p = head;
        Node* q = head;
        if (head == NULL){ // check if head have value
            head = newNode; // head receive the newNode 
       }else{
            while (p!= NULL) { //check where is the last
            q = p;
            p = p->next;
        }
        q->next = newNode; //when the last seen it will receive the newNode  
       }}
    void del(string nm){
        Node* p = head;
        Node* q = head;
        
        if(head == NULL){//check if the list is empty
            cout<<"The Record is empty."<<endl;;
            system("pause");
        }else{
            while(p!= NULL && p->student.name != nm){
               q = p;
               p = p->next;
           }
            if (p==NULL){
               cout<<"Student not found"<<endl;
               system("pause");
           }else if (p == head){//check if its in the head
               head = p->next;
               //put the value of the next into head so the previous value of head will be remove
           }else{
               q->next = p ->next;
               delete p;
        }}
    }
    void display(){
        Node* p = head;
        double average;
        cout << "NAME:\tQUIZ 1\tQUIZ 2\tQUIZ 3\tAVERAGE\tMARKS"<<endl;
        while (p!= NULL){
            average = (p->student.q1 + p->student.q2 + p->student.q3)/3.0;
            cout<<p->student.name<<"\t"<<p->student.q1<<"\t"<<p->student.q2<<"\t"
            <<p->student.q3<<"\t"<<fixed << setprecision(2)<< average<<"\t"<<(average < 75 ? "FAILED":"PASSED")<<endl;
            p = p->next;
       }system("pause");
    }
    void save(){ //print the data into the file
        fstream myFile;
        myFile.open("studentRec.txt",ios::out);
        if (!myFile) {
           cout << "Unable to open file";
           system("pause");
       }else{
            Node* p = head;
            while (p!= NULL){ //print until its NULL
                myFile << p->student.name<<endl;
                myFile << p->student.q1<<endl;
                myFile << p->student.q2<<endl;
                myFile << p->student.q3<<endl;
                p = p->next;
        }
        myFile.close();
    }}
    void retrieve(){ //read and add the data into the struct
        fstream myFile;
        myFile.open("studentRec.txt",ios::in);
        if (!myFile) {
            cout << "Unable to open file";
            system("pause");
        }else{
            Info s;//declare a variable s type Info struct
            while (getline(myFile, s.name)){
                myFile >> s.q1; //read the line  and insert it into a struct s
                myFile >> s.q2; //read the line  and insert
                myFile >> s.q3;
                //after getting the data needed
                myFile.ignore(); //this will ignore or discard any remaining characters on the current line

                add(s); //and now add into linklist
            }
        }
        myFile.close();
        }
};

int menu(){//menu
    system("cls");
    cout<<"MENU"<<endl;
    int pick;
    cout<<"1. Add Student"<<endl;
    cout<<"2. Delete Student"<<endl;
    cout<<"3. Display Students"<<endl;
    cout<<"4. Exit"<<endl;
    cin >> pick;
    return pick;
}

int main(){
    Record sl;
    Info s; //declare a variable s type Info struct
    string nm;
    sl.retrieve(); //read and add the data into the struct
    while(true){
        switch(menu()){
            case 1: system("cls");cout <<"ADD STUDENT:"<<endl; cout<<"Input Name: ";cin>>s.name;
                    cout <<"Quiz 1 Score: ";cin >>s.q1;cout<<"Quiz 2 Score: ";//inputting the data
                    cin >>s.q2;cout << "Quiz 3 Score: ";cin >>s.q3;sl.add(s);break;
            case 2: system("cls");cout <<"DELETE STUDENT:"<<endl; cout<<"Input Name: ";
                    cin >> nm; sl.del(nm);break;
            case 3: system("cls");cout << "DISPLAY STUDENTS" <<endl; sl.display();break;
            case 4: sl.save();exit(0);break; ////print the data into the file and exit the program
            default:system("cls");cout <<"INVALID INPUT!"<<endl; system("pause");break;
        }
    }
}
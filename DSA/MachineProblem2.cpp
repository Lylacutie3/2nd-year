/* VILLANUEVA, LYLA JANE L.
 BSIT-2A TUE, SEP 10, 2024
 STUDENT RECORD PROGRAM
 using ADT Operation with File Handling
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std; 

struct studentInfo {//declare struct
   string name;
   int q1;
   int q2;
   int q3;
};
#define MAX 10

class StudentRecod{
    private:
       studentInfo student[MAX];//create a array struct
       int last;
       int locate(string nm){ //function to loocate the string using name
        int i;
        for(i=0; i<MAX; i++){
            if(student[i].name == nm){
            return i;}}
        return -1;
       }
       bool itsempty(){
        return (last == -1);
       }
       bool itsfull(){
        return (last == MAX-1);
       }
    public:
       StudentRecod():last(-1){} //declaring that last in StudentRecord class is -1
       void addRecord(studentInfo info){//struct as an arguement
        if(itsfull()){
            cout<<"Record is full";
            cin.ignore();
            cin.get();//alternative for system pause (using different software)
       }else {
            //infect the value of struct emz
            student[++last] = info;//moving the point of last while also use as index
       }}

       void removeRecord(string nm){
        int p, i;
        if(itsempty()){
            cout<<"Record is empty";
            cin.ignore();
            cin.get();
       }else {
            p = locate(nm);
            if(p<0){
                cout<<"Student not found!";
                cin.ignore();
                cin.get();
            }else{
                for(i = p; i < MAX; i++){
                student[i] = student[i+1];
            }   last--;  
                cout<<"Successfully remove!";
                cin.ignore();
                cin.get();
            }
       }}
       void displayRecord(){
        if(itsempty()){
            
            cout<<"Record is empty!";
            cin.ignore();
               cin.get();
       }else{
            cout<<"STUDENT RECORDS DISPLAY\n"<<endl;
            cout<<left<<setw(15)<<"Name"<<setw(10)<<"Quiz 1"<<setw(10)<<"Quiz 2"<<setw(10)<<"Quiz 3"<<setw(10)<<"Average"<<setw(10)<<"Assessment"<<endl;//using setw to make alignment
            for(int i = 0; i <= last; i++){
                float average = (student[i].q1 + student[i].q2 + student[i].q3)/3.0;
                cout<<left<<setw(15)<<student[i].name<<setw(10)<<student[i].q1<<setw(10)<<student[i].q2<<setw(10)<<student[i].q3<<setw(10)<<fixed<<setprecision(2)<<average<<setw(10)<<(average < 75 ? "Failed" : "Pass")<<endl;
            }
            
               cin.ignore();
               cin.get();
       }
       }
       void retrieve(){
        fstream myFile;
        myFile.open("studentRec.txt",ios::in);
        if (!myFile){
           cout <<"File Error.\n";
           cin.ignore();
           cin.get();
       } else {
           studentInfo info;//declare a info as struct
           while(getline(myFile,info.name)){
             myFile >> info.q1;
             myFile >> info.q2;
             myFile >> info.q3; //inputing value 
             
             myFile.ignore();
             
             addRecord(info);
          }
       }
        myFile.close();
       }

    void save(){
      fstream myFile;
      myFile.open("studentRec.txt",ios::out);
      if (!myFile){
        cout <<"File Error.\n";
        cin.ignore();
        cin.get();
     } else {
        for (int i = 0;i<=last;i++){
           myFile << student[i].name<<endl;
           myFile << student[i].q1<<endl;
           myFile << student[i].q2<<endl; 
           myFile << student[i].q3<<endl;//printing value in file
       }
     }
      myFile.close();
     }
};
int menu(){
    int choice;
    cout<<"Student Record System\n"<<endl;
    cout<<"1. ADD RECORD"<<endl;
    cout<<"2. REMOVE RECORD"<<endl;
    cout<<"3. DISPLAY RECORD"<<endl;
    cout<<"4. EXIT"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    return choice;
}
int main(){
   string nm;
   StudentRecod stu;
   studentInfo info;
   stu.retrieve();
   while(true){
    system("clear");
    switch (menu()) {
        case 1: system("clear");cout<<"ADD STUDENT RECORD\n\n";
                cout<<"Enter student name: ";cin >> info.name;cout<<"Enter Quiz 1 Score: ";cin >> info.q1;
                cout<<"Enter Quiz 2 Score: ";cin >> info.q2;cout<<"Enter Quiz 3 Score: ";cin >> info.q3;
                stu.addRecord(info);break;
        case 2: system("clear");cout<<"DELETE STUDENT RECORD\n\n";
                cout<<"Enter student name: ";cin >>nm;stu.removeRecord(nm);break;
        case 3: system("clear");stu.displayRecord();break;
        case 4: system("clear");stu.save();exit(0);break;
        default: cout<<"Invalid choice";cin.ignore();cin.get();break;
    }
}}

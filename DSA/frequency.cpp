/*
    VILLANUEVA, LYLA JANE L.
    BSIT-2A   TUE, OCT 29, 2024
    Write a C++ program that reads a text file and outputs the list 
    of characters and corresponding frequencies (no. of occurrences in the file). 
    //included ASCII 32 - 126 characters 
*/

#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;
class Frequency {
private:
string line; //string for characters 
int frequency[100];//FREQUENCY storage

public:
void initialized(){
    for(int i=0;i<100;i++){
        frequency[i]=0; //initialized to 0
    }
}

void retrieve(){ //read the file
    fstream myFile;
    myFile.open("characters.txt", ios::in);
    
    if(!myFile){
        cout << "unable to open a file";
    }else{
        while(getline(myFile, line)){ //save into line 
            myFile.ignore();
            //function that count the nnumber of frequency
            frequencyNo(line);
            
        } 
    }
}

void frequencyNo(string x){
    int size =  x.size();
    for(int i = 0; i < size; i++){
        if(x[i] >= 32 && x[i] <= 126){
            //the space in ASCII is 32 which make the frequency  store in ->  frequency[0]; ascii subtraction.
            //if the character is space the frequency will increment in frequency[0]
            frequency[x[i] - 32]++; 
            // this increment everytime the letter repeat
    }}
}

void printOutput(){
    cout << "\nCharacter:" << " Frequency:\n";
    for(int i = 0; i < 100; i++){
        if(frequency[i] == 0) //if the frequency of letter is 0 its not print out
            continue;
        else{  // print if the frequency is more that 0
            if(i == 0)
                cout << "  " << "Space " << "\t" << frequency[i] << endl; // to print space word rather than just ' '.
            else
                cout << "    "<< char(i + 32) << "\t\t" << frequency[i] << endl; 
                //char start 32+i cause again we only store ascii character frequency from space to '~'
    }}
}

};

int main(){
    Frequency f;
    f.initialized(); //initialized to make sure every valuw of this array is 0
    f.retrieve(); 
    f.printOutput();
}
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
            frequencyNo(line); //count the letters
            //function that count the nnumber of frequency
        } 
    }
}

void frequencyNo(string x){
    int size =  x.size();
    for(int i = 0; i < size; i++){
        if(x[i] >= 32 && x[i] <= 126){
            frequency[x[i] - 32]++; //the A frequency is in frequency[1]; ascii subtraction
            // this increment everytime the letter repeat
    }}
}

void printOutput(){
    cout << "\nCharacter:" << " Frequency:\n";
    for(int i = 0; i < 100; i++){
        if(frequency[i] == 0) //if the frequency of letter is 0 its not print out
            continue;
        else{
            if(i == 0)
                cout << "  " << "Space " << "\t" << frequency[i] << endl;
            else
                cout << "    "<< char(i + 32) << "\t\t" << frequency[i] << endl; // print if the frequency is more that 0
    }}
}

};

int main(){
    Frequency f;
    f.initialized();
    f.retrieve();
    f.printOutput();
}
#include<iostream>
#include <string>
#define MAX 100

using namespace std; //to reduce using namespace every function 

struct Set{
    string elements[MAX]; // array of elements
    int last; //use as a pointer to last element
    Set() :last(-1){} //initialized to -1
};

class AdtSet{
private:
    bool isfull(Set *s){ 
        return s->last == (MAX-1); 
    }
    bool isempty(Set *s){
        return s->last == -1;
    }
    int locate(Set *s, string data){
        if(!isempty(s)){
        for(int i = 0; i <= s->last; i++){
            if(s->elements[i] == data)
                return i;
        }
        }
            return -1;
    }
public:
    bool isamember(Set *s, string data){
        if(locate(s, data) > -1)
            return true;
        else
            return false;;
    }
    void add(Set *s, string data){
        if(isfull(s)){
            cout << "Array is full";
            return;
        }
        if(!isamember(s, data)){
            s->elements[++s->last] = data;
        }
    }
    void remove(Set *s, string data){
        if(isempty(s)){
            cout << "Array is empty";
            return;
        }
        if(isamember(s,data)){
            int loc = locate(s, data);
            for(int i = loc; i < s->last; i++){ // to prevent overflow  
                s->elements[i] = s->elements[i+1];
            } s -> elements[s->last] = "";
            s->last --;
        }

    }
    void display(Set *s){
        if(isempty(s)){
            cout << "Array is empty";
            return;
        }
        for(int i = 0; i <= s->last; i++){
            cout << s->elements[i] << "\n";
        }
    }
    Set unions(Set *s1, Set *s2){ // all s1 and s2 member
        Set s3;
        for(int i = 0; i <= s1->last; i++){
            if(!isamember(&s3, s1->elements[i])){ 
                s3.elements[++s3.last] = s1->elements[i];
            }
        }
        for(int i = 0; i<= s2->last; i++){
            if(!isamember(&s3, s2->elements[i])){
                s3.elements[++s3.last] = s2->elements[i];
            }
        }
        return s3;
    }
    Set intersection(Set *s1, Set *s2){ // s1 and s2 all the common elements
        Set s3;
        for(int i = 0; i <= s2->last; i++){
            if(isamember(s1, s2->elements[i])){
                s3.elements[++s3.last] = s2->elements[i];
            }
        }
        return s3;
    }
    Set difference(Set *s1, Set *s2){ //s1 - s2
        Set s3;
        for(int i = 0; i <= s1->last; i++){ 
            if(!isamember(s2, s1->elements[i])){ 
                s3.elements[++s3.last] = s1->elements[i];
            }
        }
        return s3;
    }
    
};

int main(){
    AdtSet s; 
    Set s1,s2,s3;//run test data
    s.add(&s1, "lyla");
    s.add(&s1, "exe");
    s.add(&s1, "aliea");
    s.add(&s1, "rachelle");
    s.add(&s2, "paul");
    s.add(&s2, "ash");
    s.add(&s2, "anne");
    s.add(&s2, "lyla");
    cout << "\nSet 1\n";
    s.display(&s1);
    cout << "\nSet 2\n";
    s.display(&s2);
    cout << "\nUnion\n";
    s3 = s.unions(&s1, &s2);
    s.display(&s3);
    cout << "\nDifference s1-s2\n";
    s3 = s.difference(&s1, &s2);
    s.display(&s3);
    cout << "\nDifference s2-s1\n";
    s3 = s.difference(&s2, &s1);
    s.display(&s3);
    cout << "\nIntersection\n";
    s3 = s.intersection(&s1, &s2);
    s.display(&s3);

    return 0;

}
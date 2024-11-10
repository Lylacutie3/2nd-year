/*VILLANUEVA, LYLA JANE L.
* BSIT-2A
*   Write a C++ program to evaluate an expression tree. 
*/

#include <iostream>
using namespace std;
struct Node {
   int data;
   Node* left_child;
   Node* right_child;
   Node(int x) : data(x), left_child(NULL), right_child(NULL){}
};
class BinTree {
private:
    Node* root;
public:
    BinTree() : root(NULL){}
    Node *getter(){
        return root; //get the root
    }

    void add(Node*& r, int x){
        if(r == NULL){
            Node *newNode = new Node(x);
            r = newNode;
            return;
        }
        if(x < r->data){
            add(r->left_child, x);
        }else{
            add(r->right_child, x);
        }
    }

    void preOrder(Node* r){
    //NLR
    if (r==NULL)
        return;
    cout<<r->data<<" ";
    preOrder(r->left_child); 
    preOrder(r->right_child);
    }
    void inOrder(Node* r){
    //LNR
    if (r==NULL)
        return;
    inOrder(r->left_child);
    cout<<r->data<<" ";
    inOrder(r->right_child);
    }
    void postOrder(Node* r){
    //LRN
    if (r==NULL)
        return;
    postOrder(r->left_child);
    postOrder(r->right_child);//still cant grasp this recursion
    cout<<r->data<<" ";
    }
    //modify

};

char menu(){
    char pick;
    system("clear");
    cout << "\nBINARY TREE";
    cout << "\n1. ADD ELEMENT";
    cout << "\n2. VIEW PRE-ORDER TRAVERSAL";
    cout << "\n3. VIEW IN-ORDER TRAVERSAL";
    cout << "\n4. VIEW POST-ORDER TRAVERSAL";
    cout << "\n5. QUIT\n";
    cin >> pick;
    return pick;
}

int main(){
BinTree bt;
Node *n = bt.getter();
int x;
    while (true){
        switch (menu()) {
        case '1': system("clear");cout << "\nInput Number: "; cin >> x ;bt.add(n, x);break;
        case '2': system("clear");cout << "\nPre-Order Traversal: ";bt.preOrder(n);break;
        case '3': system("clear");cout << "\nInorder Traversal: ";bt.inOrder(n);break;
        case '4': system("clear");cout << "\nPost-Order Traversal: ";bt.postOrder(n);break;
        case '5': return 0;
        default: system("clear");cout << "\nInvalid choice. Please choose again." << endl;
        }
        cin.ignore();cin.get();
    }
return 0;
}


## Introduction to ADT

This read me File is for Prelims reviewer about ADT.

What is ADT?
    It stands for Abstract Data Type it is basically a user-defined data type.

What is ADT list?
    It is a collection of data elements, each identified by a unique index or key.

What is ADT operation?
    It is a set of operations that can be performed on an ADT.
    It includes insertion, deletion, search, traversal, etc.

We often work with built-in data types such as int, double, char, and string. These data types support various operations, for example, we can perform addition and subtraction on int values. The good thing is we can also create our own custom data types and define operations that can be performed on them. This concept is known as Abstract Data Types (ADTs). 

## Examples of ADTs

### Stack

* A stack is a collection of elements that follows the Last-In-First-Out (LIFO) principle.
* Operations:
	+ Push: adds an element to the top of the stack
	+ Pop: removes an element from the top of the stack
	+ Peek: returns the top element of the stack without removing it

### Queue

* A queue is a collection of elements that follows the First-In-First-Out (FIFO) principle.
* Operations:
    + Enqueue: adds an element to the end of the queue
    + Dequeue: removes an element from the front of the queue
    + Front: returns the front element of the queue without removing it

For sure you know all this information. In this part we will tackle on how those example of ADT will be code in c++.

### Stacks with detailed Explanation

* It fallows LIFO

![alt text](https://learnloner.com/wp-content/uploads/2023/05/Stack-Data-Structure.png)

To better visualization imagine a stack of plates. To get to the plate in the middle, you have to take off the plates on top first. This is how a stack works: you can only add or remove the top item. It's a "last in, first out" rule.

## ARRAY

When working with arrays, you can use an index to keep track of the current position you're working with. Let's call this index LastPointer. This index helps you know which element in the array you're currently accessing or modifying.

    int array[5]; // Example array with a capacity of 5 elements
    int LastPointer = -1; // Indicates the array is empty

    void push(int num){ //num is a value we want to add in array

        if (LastPointer == 5-1){ //before adding to array make sure that the array is not full
            cout << "array is full";
            return;
        }else{ //if the array is not full add 
            array[++LastPointer] = num; // Add an element and update LastPointer
        }
    }

Using ++ in front of LastPointer makes the value change immediately while the line array[++LastPointer] = num; is being executed.

Using ++ after LastPointer will change its value after the line array[LastPointer++] = num; has been executed.

        push(10); //array[0] = 10
        push(20); //array[1] = 20
        push(30); //array[2] = 30
        push(40); //array[3] = 40
        push(50); //array[4] = 50
        push(60); //array is full

After understanding how to push or add a value, let's now discuss how to remove a value. We considering LIFO, so we are gonna use the LastPointer to delete last value push.

    void pop(){ 
        if (LastPointer == -1){ //if the array is empty
            cout << "array is empty";
            return;
        }
        LastPointer--;//just reduce our pointers, indicating that its been removed
    }

        pop(); //array[0] = 10, array[1] = 20, array[2] = 30, array[3] = 40 

        //array[4] = 50 still present in the memory but not printed since where focusing in LastPointers
        
        add(60); //array[4] = 60 
        //we can add again and the value changes only

## Pointers (we know linklist)

When working in pointers you need to have a struct. Declare a struct that is Node. When we say NODE it means it have pointer inside to the next node.

    typedef struct Node {
    int data; // Data stored in the node (can be any data type)
    Node* next; // Pointer to the next node in the list
    Node(int x):data(x),next(NULL){} //constructor 
    };

This constructor ensures that whenever you create a new Node, it will have its data field initialized and its next pointer set to NULL.

Now lets talk about how to add or push using pointers. To add a new Node to the end of a linked list, we can use two pointers, q = prev and p = present, to traverse(visiting node) the list and find the last Node.

    Node *head; //start in creating a linklist

    head(NULL){} // initialized the head into a NULL

    void push(int x){ //pasing a Node x with value 
    Node newNode = new Node(x); //putting the value of x in the data of new created node
    
    if(head == NULL){//check if list is empty
        head == newNode //make sure that the head first, this will not create link list if head is empty
    }else{
        Node* q = head; //use p and q to transvers in the list
        Node* p = head;
        while(p != NULL){ //loop until we reach the end of the list
        q = p; //q is the previous node
        p = p->next;
        }
        q->next = newNode; //link the new node to the previous node
    }
    }

❌❌❌❌ Often Mistake! adding a value in head using pointers p or q... wrong.
Lets try adding a value to nodes!

    push(10); // 10 -> NULL
    push(20); // 10 -> 20 -> NULL
    push(30); // 10 -> 20 -> 30 -> NULL
    push(40); // 10 -> 20 -> 30 -> 40 -> NULL   
    push(50); // 10 -> 20 -> 30 -> 40 -> 50 -> NULL
    
You can add value as many as you want thats the perks of pointers no limit!

Here now how to remove a Node? unlike in array you just need to reduce your pointer, here you need to delete the node.

    void pop(){ 
        
        if (head == NULL){ //check it first if its empty 
            cout << "List is empty" << endl; 
            //there is nothing to remove here...
        }else{
            Node* q = head; //use p and q to transvers in the list
            Node* p = head;
            while(p->next!= NULL){ //loop until we reach the end of the list
                q = p;
                p = p->next;
            }
            q->next = NULL; //make the second to the last link into the NULL   
            delete p;//delete last node
        }

Now lets try to use the pop function.

    pop(); // 10 -> 20 -> 30 -> 40 -> NULL
    /*this happened:

             head               q      p
    linklist: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
            
    q->next = NULL; //make the second to the last link into the NULL
             head               q             p    
    linklist: 10 -> 20 -> 30 -> 40 -> NULL    50 -> NULL
            
    delete p;//delete last node
           50 -> NULL (delete to memory)
    */

And that how the pop function works it remove the last NODE incase of STACKS
I hope you understand! 




        






    

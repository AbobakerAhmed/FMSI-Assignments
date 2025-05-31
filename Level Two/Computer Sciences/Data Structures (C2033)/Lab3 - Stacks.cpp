//Name: Abobaker Ahmed Khidir Hassan
//ID: 	....
//D:  	Computer Science


/*

		// Assignemnt of lab 3 (Stacks)	\\	
	Question 1:	The push function add to the beginning of the Stack.
	Question 2:	The function multiplies each element in the stack by the given number x (x will be got from the user).
	
	// I made a small edite in the displying function to declare that is a stack not a normal linked list.

*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(NULL) {}

    void push(int val) {
        Node* newNode = new Node(val);
        
        //Question 1: That is incert at the bigging because if it was at the end newNode->next should be point to NULL,
        //			  and we don't have the head in this class so the top should be the head.
        newNode->next = top;			
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }


    //I will make a small enditing in this function to show that this is a stack not a normal linked list just.
    void displayStack() {
    	
    	cout<<" ";			// is added.
        Node* temp = top;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
        
        cout<<" ^\n |\ntop\n\n";	// is added too.
    }
    
    
    //Question 2: Multiply function.
    void multiply(int x){
    	
    	// Start from the last element entered to the stack (top) which the last first element in the linked list
		// End in the first element enterd to the stack which is the last element in the linked list (its next point to NULL)
		// Move a step forword each time to the next node. 
		for(Node *temp = top ; temp != NULL; temp = temp->next)
			temp->data *= x; // multiply the data of the current node by the given integer x.
			
	}// end multipliesBy
	
	
}; // end class Stacks



int main() {
    // define a stack object
    Stack stack;

    // push elements to the stack
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	
    // print the stack after pushing elements
	stack.displayStack();
	
    // define int x
	int x;
	cout << "Enter the number that you want to multiply it by each element of the stack: ";
	cin >> x;
	
    // call the stack multiply function that you implemented
	stack.multiply(x);
	
    // print the stack after multiplication
    cout<<"Stack after multiply each element by "<<x<<" is:"<<endl;
    stack.displayStack();
}

//Name: Abobaker Ahmed Khidir Hassan
//ID:   ....
//D:    Computer Science



#include <iostream>
using namespace std;

//creating Human struct has float weight and string gender
struct Human{
	float weight;
	string gender;
};

//6- This class for question 6
class LinkedList{
	private:
    	struct Node {
    		//6- changing the old variable data by struct Human from the fest section
    		//By this changing the struct Node will have 2 variables (person.weight and person.gender) and a poiner next
        	Human person;  
        	Node* next;
    	};
   		Node* head;
	
	
	//functions are under the main
	public:
		LinkedList() : head(NULL) {};
		void insertAtBeginning(float newWeight, string newGender);
		void insertAtEnd(float newWeight,string newGender);
		void deleteNode(float Keyweight, string keygender);
		void printList()const;
		int findNodeIndex(float Keyweight, string keygender)const;
		~LinkedList();
};


int main(){
	
	//1-1: Define Intger i and assign a value:
	int i= 0;
	
	//1-2: Define Float f and assign a value:
	float f= 0.0;
	
	//1-3: Define Struct Human :
	Human ahmed;
	ahmed.gender="male";
	ahmed.weight=69.5;
	
	
	//2: Definde a pointer for each variable:
	int* iPointer= &i;
	float* fPointer= &f;
	Human* ahmedPointer= &ahmed;
	
	
	//3: change the value of integer using dereferencing its pointer:
	*iPointer = 1;
	
	
	//4: Print the statement for all the defined variables:
	cout<<"The value "<<i<<" is stored in the memory address: "<<iPointer<<endl;
	cout<<"The value "<<f<<" is stored in the memory address: "<<fPointer<<endl;
	cout<<"The values of ahmed ["<<ahmed.weight<<","<<ahmed.gender<<"] are stored in the memory address: "<<ahmedPointer<<endl;
	
	cout<<endl;
	
	//5: Create another human struct, with other values, and print its values
	Human amna;
	amna.gender="female";
	amna.weight=65.5;
	cout<<"Amna's gender is: "<<amna.gender<<endl;
	cout<<"Amna's weight is: "<<amna.weight<<endl;
	
	cout<<endl;
	
	//6: last question.
	LinkedList list;
    list.insertAtBeginning(60.5,"male"); // 1st node	// head -> [60.5 , male] -> NULL
    list.insertAtEnd(79.2,"female");	// 2nd node		// head -> [60.5 , male] -> [79.2 , female] -> NULL
    list.insertAtBeginning(55.3,"female"); // 1st node 	// head -> [55.3 , male] -> [60.5 , male] -> [79.2 , female] -> NULL
    
    
    cout << "Linked List:\n"; 
    list.printList();       // head -> [55.3 , female] -> [60.5 , male] -> [79.2 , female] -> NULL
    
    
    list.insertAtEnd(70.0,"male"); // 4th node
    cout << "Linked List after insert [70.0 , male] at end:\n"; 
    list.printList();  // head -> [55.3 , female] -> [60.5 , male] -> [79.2 , female] -> [70.0 , male] -> NULL


    list.deleteNode(55.3,"female"); //delet the first node
    cout << "After Deletion [55.3 , female]:\n";
    list.printList();  // head -> [60.5 , male] -> [79.2 , female] -> [70.0 , male] -> NULL

	//insert ahmed from task 1 at the end and anma from task 3 at the beginning
    list.insertAtBeginning(amna.weight,amna.gender); // 1st node
    list.insertAtEnd(ahmed.weight,ahmed.gender);	// last node
    cout << "Linked list after adding amna at the beginning and ahmed at the end:\n";
    list.printList();  // head -> [65.5,female] -> [60.5 , male] -> [79.2 , female] -> [70.0 , male] -> [69.5,male] -> NULL
	//								  amna																   ahmed
		
	float keyWeight = 79.2;
	string keyGender = "female";
    int index = list.findNodeIndex(keyWeight,keyGender);
    if (index != -1) {
        cout << "Node with values weight " << keyWeight << " and gender "<<keyGender<<" found at index " << index << endl;
    } else {
        cout << "Node with values weight " << keyWeight << " and gender "<<keyGender<<" not found." << endl;
    }

    return 0;	
}//main







//___________________________________________________________________________ 

//insert node using the person's weight and gender at the beginning of the linked list
void LinkedList :: insertAtBeginning(float newWeight, string newGender) {
    Node* newNode = new Node();
    newNode->person.weight = newWeight; //adding a value to the person's weight
    newNode->person.gender = newGender; //adding a value to the person's gender
    newNode->next = head;
    head = newNode;
}//insertAtBeginning


//insert node using the person's weight and gender at the end of the linked list
void LinkedList :: insertAtEnd(float newWeight,string newGender) {
    Node* newNode = new Node();
	newNode->person.weight = newWeight; //adding a value to the person's weight
    newNode->person.gender = newGender; //adding a value to the person's gender
    newNode->next = NULL;
    if (head == NULL) {
    	head = newNode;
		return;
    }//if
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }//while
    temp->next = newNode;
}//insertAtEnd


//deleting a node using its person's weight and gender
void LinkedList :: deleteNode(float KeyWeight, string keyGender) {
	Node* temp = head;
	Node* prev = NULL;
    if (temp != NULL && (temp->person.weight == KeyWeight && temp->person.gender == keyGender) ) {
	    head = temp->next;
        delete temp;
        return;
    }
    while (temp != NULL && ((temp->person.weight != KeyWeight) or (temp->person.gender != keyGender))) {
    	prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    delete temp;

}//deleteNode


//Printing function has been edited as you ask		
void LinkedList::printList() const {
	Node* node = head;
	cout<<"head -> ";
    //the list will be printed like the drow of the linked list ( head -> [n1] -> [n2] -> ... -> NULLL ) 
	while (node != NULL) {
		//each node has data (person) has two variables (weight and gender)
		cout << "["<< node->person.weight <<","<< node->person.gender << "] -> "; //[weight,gender] ->
        node = node->next;
    }//while
    cout << "NULL\n\n";
   	
}//printList


//finding a node using the person's weight and gender
int LinkedList::findNodeIndex(float KeyWeight, string keyGender) const {
	 Node* current = head;
        int index = 0;
        while (current != NULL) {
            if (current->person.weight == KeyWeight && current->person.gender ==keyGender) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;// Key not found
}//findNodeIndex


//deleting a linked list
LinkedList:: ~LinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
}//~LinkedList







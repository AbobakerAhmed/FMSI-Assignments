// Name: Abobaker Ahmed Khidir Hassan
// ID:   ....
// D:    CS

/*
    Assignment of Lab 4 (Queues):

    1. Inside the circular queue class (array implementation),
       write a function to print all the queue elements by the order they were enqueued to the queue
       (starting from front to rear, not from 0 size). 
 
    2. Write the main function for the queue and try to enqueue, dequeue elements to and from the queue,
       and call the peak function after each dequeue to check the first element in the stack,
       and the print function you created. 
 
    3. Fix the isEmpty and isFull functions as follows:
        a. IsEmpty: to print that the queue is empty if it is, before returning 0 or 1.
        b. IsFull: to print that the queue is full if it is, before returning 0 or 1. 
        c.Try to enqueue and dequeue elements until both functions print something (to try them out). 

*/


#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int size;
    int rear;
    int front;
    int num;


public:
    Queue(int size) : size(size), front(0), rear(-1), num(0) {
        arr = new int[size];
    }

    ~Queue() {
        delete[] arr;
    }

	//Question 3.b
    bool isFull() const {
    	if(num == size){
    		cout<<"The queue is full!\n";
    		return true;
		}
        return false;
    }

	//Question 3.a
    bool isEmpty() const {
        if(num == 0){
    		cout<<"The queue is empty!\n";
    		return true;
		}
        return false;
    }

	//I made a small change in this function, because the statement "queue is full" will be printed by (is) function
    void enqueue(int value) {
        if (not isFull())
        {
            rear = (rear + 1) % size ;
            arr[rear] = value;
            num++;
        }// end if
    }// end enqueue

	//I made a small change in this function, because the statement "queue is empty" will be printed by (isEmpty) function
    void dequeue() {
         if ( not isEmpty() )
        {
            front = (front + 1) % size ;
            num--;
        }// end if
    }// end dequeue

    int peek() const {
        if (isEmpty())
            return -1;
        return (arr[front]);
    }

	//Question 1: 
    int printQ()
    {
    	if(not isEmpty()){
    		
    		//print the first line that contains the front element
    		cout<<"front ->\t"<<arr[front]<<endl;
    	
    		//print all elements from the second one to the element which is before the rear element
	    	for(int i=(front+1)%size; i != rear; i++)
    			cout<<"\t\t"<<arr[i]<<endl;
    
    		//print the last element which is the rear element
  		  	cout << "\t\t" <<arr[rear] << "\t<- rear\n\n";
    		
		}//end if
		
		//if the queue is empty that will be printed by isEmpty function.
		
    }// end printQ
};

//Question 2:
int main() {

    Queue q(7);

	//enqueue elements to the queue
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    //print the queue before deleting.
	cout<<"\nQueue:\n";   
    q.printQ();


	//dequeue elements from the queue
    cout<<"The element {"<<q.peek()<<"} is deleted from the queue."<<endl; //check the first element in the queue (2)
    q.dequeue(); // delete 1
    cout<<"The element {"<<q.peek()<<"} is deleted from the queue."<<endl; //check the first element in the queue (3)
	q.dequeue(); // delete 2
	//print the queue after deleting
 	cout<<"\nQueue after deleting:\n";   
    q.printQ();

	

	//Question 3.c.1: print the queue is empty!
	q.dequeue(); // delete 3
	q.dequeue(); // delete 4
	q.dequeue(); // delete 5
	q.dequeue(); // delete 6
	cout<<"After deleting 3,4,5, and 6; then try to delete another element\n";
	q.dequeue(); // will print the queue is emtpy statement
	
	//Question 3.c.2: print the queue is full!
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	cout<<"After incerting 1,2,3,4,5,6, and 7; then try to incerte 8\n";
	q.enqueue(8); // will print the queue is full.
	
	


}

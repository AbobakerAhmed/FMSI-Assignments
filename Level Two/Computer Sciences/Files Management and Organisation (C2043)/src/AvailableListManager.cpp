// Date: 10th - 18th of Dec 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:    ....
// D:     Computer Science
// Title: File Management and Organization Assignment

/*  About This File (AvailableListManager.cpp)

        Task 1 - 2:
            c- Using an available list to reclaim space for deleted records.
            
        - Addition work: 
        	create an available list for fixed length records (below the first one)
*/



#include <iostream>  // Input / Output operations
using namespace std;

// AvailableRecord
struct AvailableRecord{
public:
	int address; // the byte of set of the deleted record
	int recordLength; // represent the size of the deleted record
	AvailableRecord* next;
};

// AvailableList
class AvailableList{
private:
	AvailableRecord* head;
	int maxAvailSize; // the maximum available size

public:
	
	// constructor:
	AvailableList(){	head = NULL;	} // constructor
	
	// descructor
	~AvailableList(){
		AvailableRecord* temp;
		while (head){
			temp = head;
			head = head->next;
			delete temp;
		} // while
	} // Descructor

	// is the available list is empty?
	bool IsEmpty() { return head == NULL; }
	// insert a deleted record to the avail list
	// since we will use the first fit the insertion will be at the end
	void insertNewAvailableRecord( int byte_ofset , const int length){
		
		// create a new avail record
		AvailableRecord* newAvailableRecord = new AvailableRecord;
		
		// assigne the byte of set of the delete record to the available list
		newAvailableRecord->address = byte_ofset;
		
		// assigne the length of the deleted record
		newAvailableRecord->recordLength = length;
		
		if( length > maxAvailSize ){ maxAvailSize = length; }// if
		
		// we want to insert it at the end, then its next will point to NULL
		newAvailableRecord->next = NULL;
		
		// insert the AvailableRecord at the end of the availble list

		// if the avail list is empty, insert it with the head
		if( head == NULL ){
			head =  newAvailableRecord;	
		}
		
		else{ // if ther is an avail record there or more, insert it there
	

	 		AvailableRecord* temp = head; // this is to move throw the list until the end
	 			// while there is avail records in the list, go forword 
	 		while( temp->next != NULL ){ temp = temp->next;} // while
	 		// we are at the end, now we will insert the available place

			temp->next = newAvailableRecord; // let the next of the last avail record inserted before point to the new avail record
		} // else
		
	} // insertDeletedRecord

// return the address of the space that can fit the new record
	AvailableRecord firstFit(int lengthOfTheNewRecord) {
	    AvailableRecord firstFitPlace;
	
	    if(IsEmpty() || maxAvailSize < lengthOfTheNewRecord){ // there is no place can fit the record
	        firstFitPlace.address = -1; // return the address -1
	        firstFitPlace.recordLength = -1; // return the length of -1
	        return firstFitPlace;
	    } // if
	
	    // There are available places
	    firstFitPlace.recordLength = lengthOfTheNewRecord; // get the length of the new record
	    AvailableRecord* temp = head; // start from the head of the list
	    AvailableRecord* prevRecord = NULL; // to keep track of the previous record
	
	    // Traverse the list to find a place that fits
	    while(temp != NULL && lengthOfTheNewRecord >= temp->recordLength){
	        prevRecord = temp;
	        temp = temp->next;
	    } // while
		
	    // if no space found
	    if(temp == NULL){
	        firstFitPlace.address = -1; // return address -1
	        return firstFitPlace;
	    } // if
	
	    // if we found a space that fits
	    firstFitPlace.address = temp->address;
	
	    // remove this space from the available list
	    if(prevRecord == NULL){
	        // This means we are deleting the head of the list
	        head = temp->next; // update the head
	    } // if
		else{
	        prevRecord->next = temp->next; // update the previous avail record to skip the current avail record
	    } // else
	
	    delete temp; // delete the current avail record (which fits the new record)

	    return firstFitPlace; // return the available record (address and length)
	    
	} // firstFit

		
}; // AvailableList



// Avalilable list for the fiexed length records file manager ()
struct Node{
public:
	int possition; // the byte of set of the deleted record
	Node* next;
};

class AvailableListForFixedLength{ // (unrquiered)
private:
	Node* head;
	int numberOfDeletedRecords;

public:
	
	// constructor:
	AvailableListForFixedLength(){
		head = NULL; 
		numberOfDeletedRecords = 0;
	} // constructor
	
	// descructor
	~AvailableListForFixedLength(){
		Node* temp;
		while (head){
			temp = head;
			head = head->next;
			delete temp;
		} // while
	} // Descructor

	// is the available list is empty?
	bool IsEmpty() { return head == NULL; } // or numberOfDeletedRecords == 0

	// insert a deleted record to the avail list
	void insertDeletedRecord(const int byte_ofset){
		Node* newNode = new Node;
		
		// assigne the byte of set of the delete record to the available list
		newNode->possition = byte_ofset;
		
 		// insert the node at the beginning of the availble list
			newNode->next = head; // let the next point where the head is pointing
			head = newNode; // let the head point to the inserted node

			numberOfDeletedRecords++;
			
	} // insertDeletedRecord

// return the byte_ofset of the available place (the last deleted on)
	int reuseAvailableSpace(){
		// check is the list is empty
		if (IsEmpty()) // there is no available place
			return -1; // return -1
	
		// there is an available sapce
		int byte_ofset = head->possition;
		Node* temp = head;
		delete temp;
		numberOfDeletedRecords--;
		return byte_ofset; // return the byte_ofset of the available place
	
	} // reuseDeletedRecord

}; // AvailableList



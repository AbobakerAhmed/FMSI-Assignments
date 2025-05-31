// Date: 10th - 18th of Dec 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:    ....
// D:     Computer Science
// Title: File Management and Organization Assignment

/*  About This File (RecordStructures.cpp)
    This file contains each the record structures as
	a fixed length record or variable length record.            
*/


#include <iostream>
#include <String> 	// to_string, substr
#include <cstring> // strncpy
using namespace std;

const int FIXED_RECORD_LENGTH = 45; // the length of the record in the file
const short ENTRY_LENGTH = 10; // the length of the entry in the index


class FixedLengthRecord{
public:
	int id; // 4 bytes
    char name[FIXED_RECORD_LENGTH - 27];  // will be determind later after determine the FIXED_RECORD_LENGTH
	double score;   // 5 bytes
    string dateOfBirth; // 11 bytes (dd-mmm-yyyy) (Look assignment statement in the constructor)

    /*  // each record is a fixed length record:
    	recordLength =	  4 (id) + 2 (fields sepatator)
						+ sizeof(name) (name) + 2 (fields sepatator)
    					+ 5 (score in the file) + 2 (fields sepatator)
						+ 11(dateOfBirth) + 1 (records sepatator)
					=  sizeof(name) + 27					
	*/ 

	// constructor 1 : tacks the dateOfBirth as numbers
    FixedLengthRecord(int id, const char* name, double score, short birthDay, short birthMonth, int birthYear) {
        this->id = id; //set the id 
        strncpy(this->name, name, sizeof(this->name)); // setting the name ()     
        // set the score
        while( ! (0 <= score && score <= 100) ) {
        	cout << "Score must be in range (0-100)!\nEntere score again, please: ";
        	cin >> score;
		}// while
        
        this->score = score; //set the score
        
        // setting the dateOfBirth:
        // checking the range of the day, month, and year
        while(!(0 < birthDay && birthDay <= 31 && 0 < birthMonth && birthMonth <= 12 && 1980 <= birthYear && birthYear <= 2020)){
			cout << "The date of birth of " << name << " is out of range, Pleas try again:\n";	
			cout << "Enter the day: "; cin >> birthDay;
			cout << "Enter the month: "; cin >> birthMonth;
			cout << "Enter the year: "; cin >> birthYear;
    	} // while
    	
    	// Set the month as its sort string form
    	string strMonth;
    	switch(birthMonth){
    		case 1: strMonth = "Jan"; break;
    		case 2: strMonth = "Feb"; break;
    		case 3: strMonth = "Mar"; break;
    		case 4: strMonth = "Apr"; break;
    		case 5: strMonth = "May"; break;
    		case 6: strMonth = "Jun"; break;
    		case 7: strMonth = "Jul"; break;
    		case 8: strMonth = "Aug"; break;
    		case 9: strMonth = "Sep"; break;
    		case 10: strMonth = "Oct"; break;
    		case 11: strMonth = "Nov"; break;
    		case 12: strMonth = "Dec"; break;
		}

    	// after insert the right date store it in the standerd form (dd-mmm-yyyy)
		this->dateOfBirth = to_string(birthDay) + "-" + strMonth + "-" + to_string(birthYear);
		    	
    } // constructor 1
    
    
    // constructor 2 : tacks the dateOfBirth as a string 
		// note: this constructor must be used carefully to save the date form
     FixedLengthRecord(int id, char* name, double score, string dateOfBirth) {
        this->id = id; //set the id 
        strncpy(this->name, name, sizeof(this->name)); // setting the name ()
        this->score = score; //set the score

    	// setting the dateOfBirth
		this->dateOfBirth = dateOfBirth;
    	
    } // constructor 2
        
    
};	// fixedLengthRecord








struct VariableLengthRecord{
public:
	int id; // 4 bytes
    string name;  // variable length
	double score;   // 5 bytes
    string dateOfBirth; // 11 bytes (dd-mmm-yyyy) (Look assignment statement in the constructor)
	int recordLength; // the length of the record in the file

	// Constructor
    VariableLengthRecord(const int id, const string name, double score, short birthDay, short birthMonth, int birthYear) {
        this->id = id; // set the id
        this->name = name; // set the name
        this->score = score; // set the score
        
               // set the score
        while( ! (0 <= score && score <= 100) ) {
        	cout << "Score must be in range (0-100)!\nEntere score again, please: ";
        	cin >> score;
		}// while
		
        // setting the dateOfBirth:
        // checking the range of the day, month, and year
        while(!(0 < birthDay && birthDay <= 31 && 0 < birthMonth && birthMonth <= 12  && 1980 <= birthYear && birthYear <= 2020 )){
			cout << "The date of birth of " << name << " is out of range, Pleas try again:\n";	
			cout << "Enter the day: "; cin >> birthDay;
			cout << "Enter the month: "; cin >> birthMonth;
			cout << "Enter the year: "; cin >> birthYear;
    	} // while
    	
    	// Set the month as its sort string form
    	string strMonth;
    	switch(birthMonth){
    		case 1: strMonth = "Jan"; break;
    		case 2: strMonth = "Feb"; break;
    		case 3: strMonth = "Mar"; break;
    		case 4: strMonth = "Apr"; break;
    		case 5: strMonth = "May"; break;
    		case 6: strMonth = "Jun"; break;
    		case 7: strMonth = "Jul"; break;
    		case 8: strMonth = "Aug"; break;
    		case 9: strMonth = "Sep"; break;
    		case 10: strMonth = "Oct"; break;
    		case 11: strMonth = "Nov"; break;
    		case 12: strMonth = "Dec"; break;
		}

    	// after insert the right date store it in the standerd form (dd-mmm-yyyy)
		this->dateOfBirth = to_string(birthDay) + "-" + strMonth + "-" + to_string(birthYear);
		

		// setting the recordLength:	
        this->recordLength = 4 + 2// id length in the file + fields separator
							+ name.length() + 2 // variable + fields separator
							+ 6 + 2 // score length in the file + fields separator
							+ sizeof(this->dateOfBirth) + 1 //11 + records separator
							; 	
							  
    } // constructor

};	//VariableLengthRecord




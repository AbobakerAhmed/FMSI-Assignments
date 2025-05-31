// Date: 10th - 18th of Dec 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:    ....
// D:     Computer Science
// Title: File Management and Organization Assignment

/*  About This File (IndexManager.cpp)

        Task 3 - 1:
            a- Creating a primary index for fixed length records in the file using the ID as the key.
            b- Enable efficient searching using the index.
        
        Task 3 - 2:
        	a-  Creating a secondary index for variable length records in the file using the Name as the key.
				(create and add)

*/



#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>  // setfill, setw
#include <sstream>
#include <vector>
using namespace std;



class PrimaryIndex{
public:

	// create
	void createPrimaryIndex( string &fileName){
		// 5- open the index of the file in the truncate mood
		ofstream index("index_of_"+fileName, ios::trunc);
		if(!index)
			cerr << "index_of_"+fileName << " does not created!\n";
		else
			index.close();
	}// create
	
	
	// add
	void addRecordToPrimaryIndex(int id, int recordLength, int entryLength, string &fileName){
		// 5- open the index
		ofstream index("index_of_"+fileName, ios::app);
		
		// 6- write the entry of the record in the form:
				// id in 4 digits filled by 0 + \t
				// byte_ofset in (ENTRY_LENGTH - 6) digits
				// entries separator '\n'
		index << setw(4) << setfill('0') << id << "\t"
			  << setw(entryLength - 6) << setfill('0') << (id-1) * (recordLength + 1)<< '\n';
			 
		//7- close the index
		index.close();
	
	}// add


	// delete
	void deleteFromIndex(int rrnOfTargetRecord, int entryLength, string &fileName){
		
				// 10- open the index in the read/write mood
				fstream index("index_of_"+fileName, ios::in | ios::out);
				
				// 11- check the index is opened
				if(!index){ // the file is not opened
					cerr << "Something wrong, " << fileName << " did not be opend!\n";
				} // in if
			
				else{ // the file is opened	
				
					// 12- move the writing pointer to the beginning of the entry of the deleted record
					index.seekp(rrnOfTargetRecord * (entryLength +1) );
					
					// 13- mark the entry as deleted (id = -1)
					index.write("00-1", 4);
					
					// rease the old address
					for(int i=0; i<entryLength-4; i++){ index.write("\0",1); }
					
					// 14- close the index
					index.close();
					
				}// in in else
				
		
		
	} // delete	
	
	
//	void update(){} // since the update in the file doesn't change the key, then there no changes are needed
	
	

//	binary using index
   int binarySearchInIndex( int tagetId, int lastId, int entryLength, string &fileName ){
    			
    	// 1- check the id is in the index
    	if( tagetId > lastId ){ // the id is out of bound
			return -1;
		} // if
		
				
		else{ // the id may in the file
		
			// 2- open the index of the file in reading mood
    		fstream file("index_of_"+fileName, ios::in);
    	
			// 3- check the index is opened
				// 	if no, just throw an error
			if(!file){ // the index is not opened
					cerr << "Something wrong, " << "index_of_"+fileName << " did not be opend!\n";
			} // in if
		 
			else{ // the index is opened
    			
//    			int comparisons = 0;
    			
  	   			int lowestRRN = 0, highestRRN = lastId-1;
    	
		    	while( lowestRRN <= highestRRN ){
					
					// 3- go to the middle of the entry
    				int mid = (lowestRRN + highestRRN) / 2;
    				
//    				comparisons++;

    				// 4- move the reading pointer to the beginning of the middle entry in this scope
    				file.seekg( mid * (entryLength + 1) );
    				
    				// 5- read the id of the middle entry
    				char buffer[4];
    				file.read(buffer, 4);
    				
    				// 6- convare it to int and compare it with the given id
						// if that was a deleted entry skip it to the next on
					if(stoi(buffer) == -1)
    					mid +=1;
						// if the id of the current record = the given id return its RRN (mid)
    				if( stoi(buffer) == tagetId ){ // the target record is found

    					file.close(); // close the index
//    					cout << "comparissons with binary = " << comparisons << endl;
						return mid; // the RRN of the record			
					} // in in if
					
    					// if the given id < the id of the current record search in the above half of the file
    				else if( tagetId < stoi(buffer) )
						highestRRN = mid - 1; // go to the above half
					
						// if the id of the current record > the given id search in the below half of the file
    				else	
						lowestRRN = mid + 1; // go to the below half
    		
    			} // while
    			
    			// if the loop is terminated,
    				// the id is not in the index
				
				file.close(); // close the index
//				cout << "comparissons with binary = " << comparisons << endl;
				return -1; // return -1
			} // in else
		
		} // out else
    	
    	
    	
	} // binarySearchUsingIndex
	
	
	
}; // FileManager




struct entryOfSecondary{
	string name;
	int address;
	entryOfSecondary(string name, int address){
		this->name = name;
		this->address = address;
	}
	entryOfSecondary(){
		this->address = -1;
		this->name = "non";
	}
	static entryOfSecondary fromString(const string& entryAsString){
		istringstream line(entryAsString);
		string name, strAddress;
		getline(line, name, '\t');
		getline(line, strAddress, '\t');
		return entryOfSecondary(name, stoi(strAddress));
	} // fromString
	
};


// manage the secondary index
class secondaryIndex{
 	int countOfEntries;
 	
public:

	// create
	void createSecondaryIndex(string fileName){
		ofstream indexFile;
		indexFile.open("index_of_"+fileName, ios::trunc );
		if(!indexFile)
			cerr << "index_of_"+fileName << " does not created!\n";
		else{
			indexFile.close();
			countOfEntries =0;
		}// else
			
	} // createSecondaryIndex

  	// add (hash secondary index: name \t\t address)
    void addRecordToIndex(const string& name, int address, const string& fileName) {
        // Open the index file in append mode
        ofstream indexFile("index_of_" + fileName, ios::app);
        if (!indexFile) {
            cerr << "Error opening index file: index_of_" + fileName << endl;
            return;
        }

        // Append the name and address as "name\t\taddress" format
        indexFile << name << '\t' << setw(6) << setfill('0') << address << '\n';
        indexFile.close();
        countOfEntries++;

    } // add


	void deleteFromIndex(const string& name, const string& fileName) {
	    // Open the index file in read/write mode
	    fstream index("index_of_" + fileName, ios::in | ios::out);
	    
	    // Check if the file is opened
	    if (!index) {
	        cerr << "Error, index_of_" + fileName + " did not open!\n";
	        return;
	    }
	
	    string line;
	    int byte_ofset = 0;
	    
	    // Read the index file line by line
	    while (getline(index, line)) {
	        // Find the position of the tab character between name and address
	        size_t pos = line.find("\t");
	        
	        if (pos != string::npos) {
	            string currentName = line.substr(0, pos);  // Extract the name from the line
	
	            // If the current name matches the provided name
	            if (currentName == name) {
	                // Calculate the space available in the line (including the name and address part)
	                int availSpace = line.length() + name.length();
	
	                // Move the file pointer to the start of the line for overwriting
	                index.seekp(byte_ofset);
	
	                // Erase the data in the deleted record by writing "00-1" and filling the rest with '\0'
	                index.write("00-1", 4);  // Replace the first 4 characters with "00-1"
	                index.write(string(line.length() - 4, '\0').c_str(), line.length() - 4);  // Fill the rest of the line with spaces

	                cout << "Record with name " << name << " has been deleted." << endl;
	                index.close();
	                return; // Exit the function after deletion
	            }
	        }
	        
	        // Update the byte offset to the start of the next record
	        byte_ofset += line.length() + 1;  // +1 for the newline character that we read with `getline`
	    }
	
	    // If no matching name is found
	    cout << "Record with name " << name << " not found." << endl;
	
	    // Close the file
	    index.close();
	}



	// update the intry
	void updateRecordInIndex(const string& oldName, const string& newName, const string& fileName) {
	    // Open the index file in read/write mode
	    fstream indexFile("index_of_" + fileName, ios::in | ios::out);
	    if (!indexFile) {
	        cerr << "Error opening index file: index_of_" + fileName << endl;
	        return;
	    }
	
	    string line;
	    bool found = false;
	    int pos;  // Position of the tab character
	
	    // Read each line and check for the oldName
	    while (getline(indexFile, line)) {
	        pos = line.find("\t\t");  // Find the tab between name and address
	        if (pos != string::npos) {  // Check if tab was found
	            string currentName = line.substr(0, pos);  // Extract the name
	            if (currentName == oldName) {  // If we found the oldName
	                found = true;
	
	                // Move the file pointer back to the start of the line for overwriting
	                indexFile.seekp(indexFile.tellg());  // Move the pointer to overwrite the current line
	                
	                // Replace the old name with the new name (same length as the original name)
	                indexFile.write(newName.c_str(), newName.length());
	                
	                // If the new name is shorter, fill the remaining space with spaces
	                if (newName.length() < oldName.length()) {
	                    indexFile.write(string(oldName.length() - newName.length(), ' ').c_str(), oldName.length() - newName.length());
	                }
	                
	                // Ensure the rest of the line remains intact
	                int remainingBytes = line.length() - pos - 2;  // Remaining bytes after the name and tab
	                indexFile.write(line.substr(pos + 2, remainingBytes).c_str(), remainingBytes);
	                
	                cout << "Record with name " << oldName << " has been updated to " << newName << "." << endl;
	                break;
	            }
	        }
	    }
	
	    if (!found) {
	        cout << "Record with name " << oldName << " not found." << endl;
	    }
	
	    // Close the file
	    indexFile.close();
	} // update




    // Search for a record by name and return its address (byte offset)
    int searchInIndex(const string& name, const string& fileName) {
        // Open the index file in read mode
        fstream indexFile("index_of_" + fileName, ios::in);
        if (!indexFile) {
            cerr << "Error opening index file: index_of_" + fileName << endl;
            return -1;
        }

        string line;
        int byte_ofset = 0;  // Initialize byte offset
        
        // Read each line and check for the name
        while (getline(indexFile, line)) {
            int pos = line.find('\t');  // Find the tab between name and address
            string currentName = line.substr(0, name.length());  // Extract the name
            	if (currentName == name) {  // If the name matches
                	indexFile.seekg(pos+1);
                	char buffer[4];
                	indexFile.read(buffer,4);
                	
                    // Return the byte offset of the address field (after the tab)
                    return stoi(buffer);  // Adding 2 to skip the tab and get the address part
                }
            
            byte_ofset += line.length() + 1;  // Increment byte offset (line length + 1 for newline character)
        }

        // If not found, return -1
        cout << "Record with name " << name << " not found." << endl;
        return -1;
    }// searching

  
    
    
}; // secondary index




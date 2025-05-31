// Date: 10th - 18th of Dec 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:    ....
// D:     Computer Science
// Title: File Management and Organization Assignment

/*  About This File (FixedLengthFileManager.cpp)
    This file contains each task about the fixed-length records.
        Task 1 - 1: 
            a- Creating a file to store records as fixed-length records.
            b- Implementing functionality to add, delete, and update records.
            c- Allowing direct access to records using their ID.
        
        Task 2 - 2: 
            a- Implementing binary search for records in the file.            
*/

// #include "RecordStructures.cpp" // in VariableLengthFileManager.cpp
// #include "IndexManager.cpp" //in VariableLengthFileManager.cpp
// #include "RecordStructures.cpp" // in VariableLengthFileManager.cpp
// #include "AvailableListManager.cpp" // in VariableLengthFileManager.cpp
#include "VariableLengthFileManager.cpp" // contains all above


string FIXED_LENGTH_FILE_NAME = "fixed_length_records.txt"; // the file name that store fixed-length records


class FixedLengthFileManagement{
public:
	int lastId; // the index of the last record in the file
	AvailableListForFixedLength avail; // the avail list that store the adresses of the deleted records
	PrimaryIndex index;
	
// Task 1 - 1 - a: Creating a file to store records as fixed-length records.
// Task 3 - 1 - a: Creating the index file
	// create:
	void createFixedLengthFile(){
		
		// 1- open the file in the truncate mood (if it is already exist, truncate its content)
		ofstream file(FIXED_LENGTH_FILE_NAME, ios::trunc);
		
		// 2- check the file is created
			// if no throw an error
		if(!file) cerr << FIXED_LENGTH_FILE_NAME << " does not created!\n";
		
			
		else{ // the file is created and opened
			// 3- close it
			file.close();
	
			// set the last id in the file by 0		
			this->lastId = 0;

		
// index steps
			index.createPrimaryIndex(FIXED_LENGTH_FILE_NAME);			

		
			cout << FIXED_LENGTH_FILE_NAME << " is created sccessufully.\n";				
	
				 
		} // else
		
	} // createFixedLengthFile 

	
// Task 1 - b: Implementing functionality to add, delete, and update records.
	// add:
	void addFixedLengthRecord( FixedLengthRecord record ){
		
		// 1- open the file in append mood
    	ofstream file(FIXED_LENGTH_FILE_NAME, ios::app);
    	
    	// 2- check the file is opened
    	if(!file){ // error when opening the file
    		cerr << "Something wrong, " << FIXED_LENGTH_FILE_NAME << " did not be opend!\n";
		} // if
		
		else{ // the file is open


			
// reclime the available space (didn't required in the project)

			
			// 3- write the record to the file in this form:
				// id in 4 digits filled by 0 + \t\t  (automatic)
				// name in its size (19) bytes (if shorter fill by '_' , if longer tack the 1st 19 chars) + \t\t
				// score in 5 bytes (the commah and 4 digits right or left it) + \t\t
				// dateOfBirth in 11 bytes filled by '0' in the form (dd-MMM-yyyy) where months are an its shortname
				// records separator '\n'
				// ex (0001		_______________Adam		90.55		15-Jan-1990) + \n
			file << setw(4) << setfill('0') << ++lastId << "\t\t"
				 << setw(sizeof(record.name)) << setfill('_') << record.name << "\t\t"
				 << to_string(record.score).substr(0,5) <<  "\t\t"
				 << setw(11) << setfill('0') << record.dateOfBirth << '\n';	
			
			// 4- close the file
			file.close();


// index steps
			index.addRecordToPrimaryIndex(lastId, FIXED_RECORD_LENGTH, ENTRY_LENGTH, FIXED_LENGTH_FILE_NAME);
						
			cout << "Record has been added to the file with id = " << lastId << ".\n";	


    	
		} // else
    	
	}	// addFixedLengthRecord

	
	// sequential search
	int sequentialSearchForFixedLengthRecord( int targetId ){
		
		if( targetId > lastId ) //the target id is not in the file (out of ids bound)
			return -1;

		else{ // the id may in the file
			
			// 1- open the file in the read mood
			fstream file(FIXED_LENGTH_FILE_NAME, ios::in | ios::out | ios::binary);
			
			// 2- check the file is open
			if(!file){	// the file is not opened
				cerr << "Something wrong, " << FIXED_LENGTH_FILE_NAME << " did not be opend!\n";
	 		} // if
	 		
			else { // the file is opened
			
				// 3- move the reading pointer to the begginning
				file.seekg(0);
				
				// the record RRN (order) in the file
				int rrn = 0;
				
//				int comparisons =0;
				char buffer[4];	// this is a temp to read the id of the record
				
				while( rrn < lastId ){ // RRN of the last record in the file is (lastId - 1)
				
					// 4- read the first 4 characters from the current record ( its id )
					file.read(buffer, 4);
					
//					comparisons++;
					// 5- convert those charcters into an int (the id of the record),
					// 6- and then compare it with the id of the target record
					if( stoi(buffer) == targetId ){ // if they are the same, the record is found
						file.close();
//						cout << "comparissons with find = " << comparisons << endl;
						return rrn; // return its RRN (its order in the file)
					} // if
					
					// if the are not the same, move to the beginning of the next record
					else{
						rrn++ ; // increament the RRN by one
	
					// go to the first byte of the next record
						// we are at the first byte after the id which is the 5th byte
						// to move to the first byte of the id of next record we have to:
							// move more the recordSize steps + 1 (the new line)
							// we will be after the id of the next record
							// back 4 steps to be at the beginning of the next record
							// FIXED_RECORD_LENGTH + 1 - 4 = FIXED_RECORD_LENGTH - 3
					file.seekg( FIXED_RECORD_LENGTH -3, ios::cur );
					
					} // in in else
		
				} // out while
			
			
				// if the loop terminated, then file ended without finding a record
				file.close(); // 10- close the file			
	//			cout << "comparissons with find = " << comparisons << endl;
				return -1; // 11- return -1
				
			} // in else
			
			
		} // out else
		
	} // findFixedLengthRecord


	//	delete:
	void daleteFixedLengthRecord( int targetId ){
		
		if( targetId > lastId){
			cout << "Record with id = " << targetId << " is not in " << FIXED_LENGTH_FILE_NAME << "!" << endl;
			return;
		}
		
		// 1- get the RRN of the target record
		int rrnOfTargetRecord = targetId - 1; //findFixedLengthRecord( targetId );
			
		// 3- open the file in the read/write mood 
		fstream file(FIXED_LENGTH_FILE_NAME, ios::in | ios::out );
	
		// 4- check the file is opened
		if(!file){ // the file is not opened
			cerr << "Something wrong, " << FIXED_LENGTH_FILE_NAME << " did not be opend!\n";
		} // in if
		
		
		else{ // the file is opened	
			// 5- move the write head to the beginning of that record
			// from the beginning of the file move the first record's size
			// move more 
			file.seekp( rrnOfTargetRecord * ( FIXED_RECORD_LENGTH + 1 ) );
			
			// 2- check is the record in the file?
			char buffer[4];
			file.read(buffer, 4);
			// 	if not, just throw an error
			if( stoi(buffer) == -1 ){
				cerr << "Record with id = " << targetId << " is not in " << FIXED_LENGTH_FILE_NAME << "!" << endl;
				return;
			} // if

			// the record is not deleted
			// move to its place				
			file.seekp( rrnOfTargetRecord * ( FIXED_RECORD_LENGTH + 1 ) );
			
			// 6- mark it as deleted record (using id -1)
			file.write("00-1", 4); 
			
			// file the availbale space by spaces
			for(int i=0; i < FIXED_RECORD_LENGTH - 5; i++ ) file.write("\0", 1 ); // full the line by spaces 
							
			// 7- close the file
			file.close();
			
			// 8- notify the user
			cout << "Record with id = " << targetId << " has been deleted successfully." << endl << endl;

			// 9- insert the byte_ofset to the avail list
				// byte of set of a record = RRN * (record size+1) (1 is the fields separator new line)
			avail.insertDeletedRecord( rrnOfTargetRecord * ( FIXED_RECORD_LENGTH + 1 ) );

// index steps
			index.deleteFromIndex(rrnOfTargetRecord, ENTRY_LENGTH, FIXED_LENGTH_FILE_NAME);
				
								
		} // out else
				
	} // daleteFixedLengthRecord

	// update:
	void updateFixedLengthRecord( int id, FixedLengthRecord updatedRecord ){

		// 1- get the RRN of the target record
		int rrnOfTargetRecord = id - 1; //findFixedLengthRecord( targetId );
	
			
		// 3- open the file in the read/write mood 
		fstream file(FIXED_LENGTH_FILE_NAME, ios::in | ios::out );
	
		// 4- check the file is opened
		if(!file){ // the file is not opened
			cerr << "Something wrong, " << FIXED_LENGTH_FILE_NAME << " did not be opend!\n";
		} // in if
		
		
		else{ // the file is opened	
			// 5- move the write head to the beginning of that record
			// from the beginning of the file move the first record's size
			// move more 
			file.seekp( rrnOfTargetRecord * ( FIXED_RECORD_LENGTH + 1 )  );
			
			// 2- check is the record in the file?
			char buffer[4];
			file.read(buffer, 4);
			// 	if not, just throw an error
			if( stoi(buffer) == -1 ){
				cerr << "Record with id = " << id << " is not in " << FIXED_LENGTH_FILE_NAME << "!" << endl;
				return;
			} // if
			
			// the record is not deleted:	
			// move to the beginnig of the name field of the target record
			file.seekp( rrnOfTargetRecord * ( FIXED_RECORD_LENGTH + 1 ) + 6);
			// 7- update the record
				// id will not be updated
			file << setw(FIXED_RECORD_LENGTH - 27) << setfill('_') << updatedRecord.name << "\t\t" // FIXED_RECORD_LENGTH-27 is the length of the name
			     << to_string(updatedRecord.score).substr(0,5) << "\t\t"
				 << setw(11) << setfill('0') << updatedRecord.dateOfBirth;	// there is no new line here	

			// 8- close the file
			file.close();
			
			// 9- notify the user
			cout << "The record with id = "<< id << " has been updated successfully." << endl;
		
	
			} // else
	} // updateFixedLengthRecord


// Task 1 - c: Allowing direct access to records using their ID. 
	// directAccess
	FixedLengthRecord directAccess( int id ){
		
		// 1- check the id is in the file
		if( id > lastId)
			cerr << "Record with id = " << id << " is not in " << FIXED_LENGTH_FILE_NAME << "!" << endl;

		else{

			// 2- open the file
			fstream file(FIXED_LENGTH_FILE_NAME, ios::in | ios::out);
			
			// 3- check the file is opened
			// 	if not, just throw an error
			if(!file){ // the file is not opened
					cerr << "Something wrong, " << FIXED_LENGTH_FILE_NAME << "did not be opend!\n";
			} // if
			 
			else{ // the file is opened
				
				// 4- move the reading pointer to the beginning of the target record
				// file.seekg( (id-1) * (RECORD_LEMGTH+1) ); 
				
				// reading the id
				// char buffer[4];
				// file.read(buffer, 4);
				// in ID = stoi(buffer);
					// we have the id already :) 
	
				// 4- move the reading pointer to the beginning of the name field
						//	 RRN = id -1
				file.seekg( (id-1) * (FIXED_RECORD_LENGTH+1) + 6 ); // FIXED_RECORD_LENGTH + 1 (new line) + 6 id field and the fields separator
	
				// 5- read the name and store it as a char
					// It will be readed char by char to skip '_' (what it was filled by)
				char nameTemp[FIXED_RECORD_LENGTH - 27];
				char nameWithoutSpace[FIXED_RECORD_LENGTH - 27];
				for(int i=0,j=0; i<sizeof(nameTemp); i++){ 
					file.get(nameTemp[i]);
					if( nameTemp[i] == '_') continue; // ignor '_'
					nameWithoutSpace[j] = nameTemp[i];
					j++; 
				} // for
	//			cout << endl << "Name: " << nameWithoutSpace << endl; // testing step
	
				// 6- move the pointer to the beginning of the score field
					// file.seekg(1, ios::cur); //  fields separator  ( The pointer is already there )
					// it will be done in the reading step
					
				// 7- read the score and coverce it and store it as a double
				char scoreTemp[5]; // the length of the score in the file
				file.read(scoreTemp, 7); // fields separator
	//			cout << "Score: " << stof(scoreTemp) << endl; // testing step
	
				// 8- move the pointer to the date of birth field
					// file.seekg(2, ios_base::cur); //  field and the fields separator
					// it will be done in the reading step
					
				// 9- read the dateOfBirth and store it as a string in its form			
				char dateOfBirthTemp[11]; // the length of the date in the file
				file.read(dateOfBirthTemp, 13);  // it will read the  fields separator too here
				
				// take the date without the fields separator
				string date;
				for(int i=0; i<sizeof(dateOfBirthTemp)-1; i++){ date += dateOfBirthTemp[i+3];} // for
	//			cout << "Date of Birth: " << date << ",\tIts length: " << sizeof(date) << endl; // testing step
				
				// 10- close the file
				file.close();
	
				// 11- return a FixedLengthRecord object with the same proparities
				return FixedLengthRecord(id, nameWithoutSpace, stof(scoreTemp), date); // covare the dateOfBirthTemp to string
				
			} // in else
		
		} // out else
		
	} // directAccess
	

// Task 2 - a: Implementing binary search for records in the file.
	// binary search:
    int binarySearch( int id ){
    			
    	// 1- check the record in the file
    	if( id > lastId )
    		return -1; // the record is not in the file
		
		else{ // the id may in the file
		
			// 2- open the file in reading mood
    		fstream file(FIXED_LENGTH_FILE_NAME, ios::in);
    	
			// 3- check the file is opened
			// 	if not, just throw an error
			if(!file){ // the file is not opened
					cerr << "Something wrong, " << FIXED_LENGTH_FILE_NAME << "did not be opend!\n";
			} // in if
		 
			else{ // the file is opened
    			
//    			int comparisons = 0; // comparisons in with this fun
    			
    			// detrmine the scope of searching
  	   			int lowestRRN = 0, highestRRN = lastId-1;
    	
		    	while( lowestRRN <= highestRRN ){
					    				
//    				comparisons++; // increament the comparisons by on
  
  					// 3- calculate the middle record
    				int mid = (lowestRRN + highestRRN) / 2;
    				
    				// 4- move the reading pointer to the beginning of the middle record
    				file.seekg( mid * (FIXED_RECORD_LENGTH+1) );
    				
    				// 5- read the id of the middle record
    				char buffer[4];
    				file.read(buffer, 4);
    				
    				// 6- convare it to int and compare it with the given id
  						// if that was a deleted record skip it to the next on
					if( stoi(buffer) == -1)
    					mid +=1;  				
					
						// if the id of the current record = the given id return its RRN (mid)
    				if( stoi(buffer) == id ){ // the target record is found
    					file.close(); // close the file
//    					cout << "comparissons with binary = " << comparisons << endl;
						return mid; // the RRN of the record			
					} // in in if
					
    					// if the given id < the id of the current record search in the above half of the file
    				else if( id < stoi(buffer) )
						highestRRN = mid - 1; // go to the above half
					
						// if the id of the current record > the given id search in the below half of the file
    				else	
						lowestRRN = mid + 1; // go to the below half
						
    			} // while
    			
    			// if the loop is terminated, the record is not in the file			
				file.close(); // close the file
//				cout << "comparissons with binary = " << comparisons << endl;
				return -1; // return -1
			} // in else
		
		} // out else
    		
	} // binarySearch
	

//	binary using index
   int binarySearchUsingIndex( int id ){
  		
		return index.binarySearchInIndex(id, lastId, ENTRY_LENGTH, FIXED_LENGTH_FILE_NAME);
    	
	} // binarySearchUsingIndex
	
	
	
	// generate 50 record
	void generate50fixedLengthRecords() {
		addFixedLengthRecord(FixedLengthRecord(0, "Omar", 95.3, 30, 5, 1985));
	    addFixedLengthRecord(FixedLengthRecord(0, "Ahmed", 54.73333333233, 1, 7, 1987));
	    addFixedLengthRecord(FixedLengthRecord(0, "Adam", 9.41, 4, 1, 1992));
	    addFixedLengthRecord(FixedLengthRecord(0, "Monzir", 79, 3, 9, 1996));
	    addFixedLengthRecord(FixedLengthRecord(0, "Osman", 89.3, 3, 11, 1991));
	    addFixedLengthRecord(FixedLengthRecord(0, "Awab", 54.23, 3, 1, 1987));
	    addFixedLengthRecord(FixedLengthRecord(0, "Khalid", 93.19, 23, 6, 1990));
	    addFixedLengthRecord(FixedLengthRecord(0, "Abobaker", 100, 2, 2, 1988));
	    addFixedLengthRecord(FixedLengthRecord(0, "Hassan", 65, 25, 12, 1995));
	    addFixedLengthRecord(FixedLengthRecord(0, "Malik", 80.3, 16, 7, 1986));
	
	    addFixedLengthRecord(FixedLengthRecord(0, "Zain", 77.2, 14, 10, 1993));
	    addFixedLengthRecord(FixedLengthRecord(0, "Liam", 88.5, 22, 12, 1994));
	    addFixedLengthRecord(FixedLengthRecord(0, "Noah", 56.4, 19, 11, 1989));
	    addFixedLengthRecord(FixedLengthRecord(0, "Maya", 62.1, 8, 8, 1986));
	    addFixedLengthRecord(FixedLengthRecord(0, "Sara", 91.7, 2, 3, 1985));
	    addFixedLengthRecord(FixedLengthRecord(0, "Lara", 72.8, 13, 5, 1990));
	    addFixedLengthRecord(FixedLengthRecord(0, "Mona", 84.5, 27, 9, 1992));
	    addFixedLengthRecord(FixedLengthRecord(0, "Ali", 67.2, 17, 4, 1988));
	    addFixedLengthRecord(FixedLengthRecord(0, "Ibrahim", 78.9, 12, 7, 1991));
	    addFixedLengthRecord(FixedLengthRecord(0, "Yasmin", 69.5, 1, 9, 1993));
	
	    addFixedLengthRecord(FixedLengthRecord(0, "Farah", 83.4, 20, 2, 1987));
	    addFixedLengthRecord(FixedLengthRecord(0, "Amina", 95.0, 5, 10, 1990));
	    addFixedLengthRecord(FixedLengthRecord(0, "Kareem", 60.3, 21, 1, 1986));
	    addFixedLengthRecord(FixedLengthRecord(0, "Rami", 76.5, 26, 6, 1994));
	    addFixedLengthRecord(FixedLengthRecord(0, "Dalia", 80.7, 7, 11, 1988));
	    addFixedLengthRecord(FixedLengthRecord(0, "Salma", 87.6, 3, 4, 1991));
	    addFixedLengthRecord(FixedLengthRecord(0, "Karim", 71.2, 11, 12, 1995));
	    addFixedLengthRecord(FixedLengthRecord(0, "Layla", 93.1, 9, 6, 1992));
	    addFixedLengthRecord(FixedLengthRecord(0, "Amira", 68.8, 28, 7, 1990));
	    addFixedLengthRecord(FixedLengthRecord(0, "Zayd", 85.4, 4, 1, 1994));
	
	    addFixedLengthRecord(FixedLengthRecord(0, "Rashid", 77.3, 24, 8, 1989));
	    addFixedLengthRecord(FixedLengthRecord(0, "Fayza", 79.0, 13, 2, 1987));
	    addFixedLengthRecord(FixedLengthRecord(0, "Tariq", 66.2, 6, 11, 1991));
	    addFixedLengthRecord(FixedLengthRecord(0, "Samira", 92.4, 12, 9, 1985));
	    addFixedLengthRecord(FixedLengthRecord(0, "Sami", 85.6, 30, 3, 1989));
	    addFixedLengthRecord(FixedLengthRecord(0, "Maha", 72.9, 18, 5, 1994));
	    addFixedLengthRecord(FixedLengthRecord(0, "Jamal", 90.1, 8, 7, 1990));
	    addFixedLengthRecord(FixedLengthRecord(0, "Zaki", 76.3, 21, 4, 1987));
	    addFixedLengthRecord(FixedLengthRecord(0, "Rana", 81.4, 15, 8, 1993));
	    addFixedLengthRecord(FixedLengthRecord(0, "Omar", 68.0, 23, 12, 1986));
	
	    addFixedLengthRecord(FixedLengthRecord(0, "Samiha", 95.5, 2, 6, 1988));
	    addFixedLengthRecord(FixedLengthRecord(0, "Ibrahim", 84.6, 17, 10, 1995));
	    addFixedLengthRecord(FixedLengthRecord(0, "Reem", 79.8, 9, 4, 1992));
	    addFixedLengthRecord(FixedLengthRecord(0, "Zahra", 75.3, 11, 12, 1994));
	    addFixedLengthRecord(FixedLengthRecord(0, "Khalid", 82.0, 4, 9, 1987));
	    addFixedLengthRecord(FixedLengthRecord(0, "Amir", 78.2, 17, 2, 1991));
	    addFixedLengthRecord(FixedLengthRecord(0, "Sana", 89.7, 23, 8, 1989));
	    addFixedLengthRecord(FixedLengthRecord(0, "Lina", 66.5, 12, 11, 1995));
	    addFixedLengthRecord(FixedLengthRecord(0, "Dina", 94.8, 20, 4, 1992));
	    addFixedLengthRecord(FixedLengthRecord(0, "Zainab", 70.4, 9, 9, 1990));
	
	    addFixedLengthRecord(FixedLengthRecord(0, "Huda", 88.1, 3, 10, 1986));
	} // genera

	
			
}; // FixedLengthFileManagement

/*

int main(){
	FixedLengthFileManagement fileManager;
	
	// create a file to store fixed length records
	fileManager.createFixedLengthFile();
	
	// adding 10 records to the file
	fileManager.addFixedLengthRecord( FixedLengthRecord(0,"Omar",95.3, 30,5,1985) );
	fileManager.addFixedLengthRecord( FixedLengthRecord(0,"Ahmed",54.73333333233, 1,7,1987) );
	fileManager.addFixedLengthRecord( FixedLengthRecord(0,"Adam",9.41, 4,1,1992) );
	fileManager.addFixedLengthRecord( FixedLengthRecord(0,"Monzir",79, 3,9,1996) );
	fileManager.addFixedLengthRecord( FixedLengthRecord(0,"Osman",89.3, 3,11,1991) );
	fileManager.addFixedLengthRecord( FixedLengthRecord(0,"Awab",54.23, 3,1,1987) );
	fileManager.addFixedLengthRecord( FixedLengthRecord(0,"Khalid",93.19, 23,6,1990) );
	fileManager.addFixedLengthRecord( FixedLengthRecord(0,"Abobaker",100, 2,2,1988) );
	fileManager.addFixedLengthRecord( FixedLengthRecord(0,"Hassan",65, 25,12,1995) );
	fileManager.addFixedLengthRecord( FixedLengthRecord(0,"Malik",80.3,16,7,1986) );	

//	fileManager.lineLength(FixedLengthRecord(9,"Issam",78.1,3,1,1992),"fixedLengthRecords.txt");
	
	// test the finding fun.
	cout<< endl << "Test Find Function (finding the record with id = 7:)\n";
 	FixedLengthRecord myRecord = FixedLengthRecord(7,"Khalid",93.19, 23,6,1990);	
	int index = fileManager.sequentialSearchForFixedLengthRecord( 7 );	// the new version of find (paramiter type of int)
	if(index != -1) cout << myRecord.name << "'s record has RRN = " << index << endl;
	else cout << myRecord.name << "'s record is not found" << endl;

	// test deleting fun.
	cout<< endl << "Test Deleting Function:\n";	// the new verstion of delete (paramiter type of int)
	fileManager.daleteFixedLengthRecord( 3 );
	fileManager.daleteFixedLengthRecord( 13 ); // is not in the file

	// test the updating fun.
	cout<< endl << "Test Updating Function:\n";
	fileManager.updateFixedLengthRecord( 4, FixedLengthRecord(4,"Mohamed",70.7, 7,6,1991) );


	// test direct access	
	cout<< endl << "Test Direct Access Function:\nAccess Record With id = 6:\n";
	myRecord = fileManager.directAccess(6);
	cout << "Name: " << myRecord.name << endl
		 << "Score: " << myRecord.score << endl
		 << "Date of Birth: " << myRecord.dateOfBirth << endl;

	
	// test binary search		 
	cout<< endl << "Test Binary Search (finding the record with id = 9)\n";
	index = fileManager.binarySearch(9);
	if(index != -1) cout << "Record with id 9 has RRN = " << index << endl;
	else cout << "Record with id 9 is not found" << endl;

	cout<< endl << "Test Binary Search (finding the record with id = 20)\n";
	index = fileManager.binarySearch(20);
	if(index != -1) cout << "Record with id 20 has RRN = " << index << endl;
	else cout << "Record with id 20 is not found" << endl;	

	// test binary search using the index
	cout<< endl << "Test Binary Search Using Index (finding the record with id = 9)\n";
	index = fileManager.binarySearchUsingIndex(9);
	if(index != -1) cout << "Record with id 9 has RRN = " << index << endl;
	else cout << "Record with id 9 is not found" << endl;

	
	return 0;
} //main

*/




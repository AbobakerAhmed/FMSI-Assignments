// Date: 10th - 18th of Dec 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:    ....
// D:     Computer Science
// Title: File Management and Organization Assignment

/*  About This File (VariableLengthFileManager.cpp)
    This file contains each task about the fixed-length records.
        Task 1 - 2: 
            a- Creating a file to store records as variable-length records.
            b- Implementing functionality to add, delete, and update records.
            c- Using the available list to reclaim for deleted records.
        
        Task 2 - 1: 
            a- Implementing sequential search for records in the file.            
*/

#include "IndexManager.cpp" // the index manager
#include "RecordStructures.cpp" // structre variavle length record
#include "AvailableListManager.cpp"
const string VARIABLE_LENGTH_FILE_NAME = "variable_length_records.txt"; // the file name that store fixed-length records


class VariableLengthFileManagemer{
public:
	int lastId; // the last id in the file
	AvailableList avail; // the available list that contains the byte of set of each deletd record
	secondaryIndex index; // to manage the index file
	
		
	// create
    void createVariableLengthFile( string fileName = VARIABLE_LENGTH_FILE_NAME){
			
		// 1- open the file in the truncate mood (if it is already exist, truncate its content)
		ofstream file(fileName, ios::trunc);
		
		// 2- check the file is created
			// if no throw an error
		if(!file) cerr << fileName << " does not created!\n";
				
		else{ // the file is created and opened
			// 3- close it
			file.close();
			
			// 4- set the last id in the file by 0	
			lastId = 0;
			

// index steps			
			// 5- open the index of the file in the truncate mood
			index.createSecondaryIndex(fileName);	
			
			cout << fileName << " created successfully.\n";			 
		} // else
			
    } // createVariableLengthFile

    
	// add (using reclaimming space)
	void addVariableLengthRecord( VariableLengthRecord record ){

		// check is there an available place can fit the record?
		// if there is one get its byte ofset of the deleted record and its length, then remove it from the avail list
		AvailableRecord availRecord = avail.firstFit( record.recordLength );
				
		// check
		if( availRecord.address == -1 ) { // the list does not contain an available plact that can fit the record
				// just inserte it at the end
				appendVariableLengthRecord( record ); // the below function	
		} // if
		
		else{ // the available list contains a place that can fit the record
		
			// 1- open the file in writting mood
		    ofstream file(VARIABLE_LENGTH_FILE_NAME, ios::in | ios::out);
	    	
	    	// 2- check the file is opened
	    	if(!file){ // error when opening the file
	    		cerr << "Something wrong, " << VARIABLE_LENGTH_FILE_NAME << " did not be opend!\n";
			} // if
			
			else{ // the file is open
										
				// move the writting pointer to the begginng of the available address
				file.seekp( availRecord.address );


				// 7- write the record
				file /* << setw(availRecord.recordLength) << setfill('_') */
					 << setw(4) << setfill('0') << ++lastId << "\t\t" 
					 << record.name << "\t\t" // the name is variable length
				     << to_string(record.score).substr(0,5) << "\t\t" // set the score in 5 bytes (comma and 4 digits)
					 << setw(11) << setfill('0') << record.dateOfBirth;	// there is no new line here	


				// 8- close the file
				file.close();
				
// index steps
				// add the entry of the record (name and address) to the index
	   			index.addRecordToIndex(record.name, availRecord.address, VARIABLE_LENGTH_FILE_NAME);
			
				// notify the user
				cout << "Record has been added to the file with id = " << lastId << ".\n";	

			} // in else (the file is opened) 

		} // out else (the avail list has an avail place)
		
	} // addVariableLengthRecord

	    
	// append (add at the end)
	void appendVariableLengthRecord( VariableLengthRecord record ){

		// 1- open the file in append mood
	    fstream file(VARIABLE_LENGTH_FILE_NAME, ios::in|ios::out);
    	
    	// 2- check the file is opened
    	if(!file){ // error when opening the file
    		cerr << "Something wrong, " << VARIABLE_LENGTH_FILE_NAME << " did not be opend!\n";
		} // if
		
		else{ // the file is open
				
				// move the writting pointer to the end
				file.seekp(0, ios::end);
				int byte_ofset = file.tellp(); // store the address of that place to add it to the index

			// 3- write the record to the file in this form:
				// id in 4 digits filled by 0 + \t\t  (automatic)
				// name in its size + \t\t
				// score in 5 bytes (the commah and 4 digits right or left it) + \t\t
				// dateOfBirth in 11 bytes filled by '0' in the form (dd-MMM-yyyy) where months are an its shortname
				// records separator '\n'
				// ex (0001		Name		90.55		15-Jan-1990) + \n
				
			file << setw(4) << setfill('0') << ++lastId << "\t\t"
				 << record.name << "\t\t"
				 << to_string(record.score).substr(0,5) <<  "\t\t"
				 << setw(11) << setfill('0') << record.dateOfBirth << '\n';	
			
			// 4- close the file
			file.close();

// index steps
			// add the entry of the record (name and address) to the index
	 		index.addRecordToIndex(record.name, byte_ofset, VARIABLE_LENGTH_FILE_NAME);

		// notify the user
		cout << "Record has been added to the file with id = " << lastId << ".\n";	
    	
		} // else

	}	//appendVariableLengthRecord


	// sequential search (for an id)
	int sequentialSearchForVariableLengthRecord( int targetId ){

// Time	
		// starting time:
//		(the time will be added at the main because this function is used in delete and update)
//		auto start = chrono::high_resolution_clock::now();
		
		// 1- check the id is in the ids bound
		if( targetId > lastId ){ //the target id is not in the file (out of ids bound)
			return -1;
		} // if
		
		else{ // the id may in the file
			
			// 2- open the file in the read mood
			fstream file(VARIABLE_LENGTH_FILE_NAME, ios::in);
			
			// 3- check the file is open
			if(!file){	// the file is not opened
				cerr << "Something wrong, " << VARIABLE_LENGTH_FILE_NAME << " did not be opend!\n";
	 		} // if
	 		
			else { // the file is opened
			
				// 4- move the reading pointer to the begginning
				file.seekg(0);
				
				
				int byte_ofset = 0; // this is the byte_ofset of the target record
				int rrn = 0; // this is just to manage the below loop
				char buffer[4];	// this is a temp to read the id of the record
			
//	int comparisons =0;

				while( rrn < lastId ){ // the file is not ended

//					comparisons++;
	
					// 5- read the first 4 characters from the current record ( its id )
					file.read(buffer,4);

					// 6- convert those charcters into an int (the id of the record),
					// 7- and then compare it with the id of the target record
					if( stoi(buffer) == targetId ){ // if they are the same, the record is found

// Time
						// finishing time
//						auto end = chrono::high_resolution_clock::now();
//                   		searchBlock.time = chrono::duration<double, milli> duration_ms = end - start;

						file.close();
						return byte_ofset; // return the byte_ofset of the record
					} // if
					
					// if the are not the same, move to the beginning of the next record
					else{
						
					 	// 8- read a line of the file
					 	string line;	// this is a temp to seek to the next line (the next record)			 
					 	getline(file, line);
					 						 	
					 	// 9- increament the byte_ofset by the length of the line
					 		// 4 bytes of the id + up to the end of the line + 2 '\n' records separator 
					 	byte_ofset += line.length() + 6; 
					 	
						// 10- move to the first byte of the next record (move the length of the line)
							// since we have just read the line we have just seeked to the first byte after the new line
							// which is the records separator, then we are already at the first byte of the next record						
							// no seeking is needed			
					} // in else
		
					rrn++; // go to the next record
					
				} // out while

// Time					
				// finishing time
//				auto end = chrono::high_resolution_clock::now();
                
				// if the loop terminated, then file ended without finding a record
				file.close(); // 11- close the file			
 
//				searchBlock.time = chrono::duration<double, milli> duration_ms = end - start;
//				searchBlock.address = -1;
				
				return -1; // 12- return -1
				
			} // in else
		} // out else
	
	} // SequentialSearchForVariableLengthRecord
		
  	
	// delete 
	void daleteVariableLengthRecord( int targetId ){
		
		// 1- get the byte_ofset of the target record
		int byte_ofset = sequentialSearchForVariableLengthRecord( targetId );
		
		// 2- check is the record in the file?
		// 	if not, just throw an error
		if( byte_ofset == -1 ){
			cerr << "Record with id = " << targetId << " is not in " << VARIABLE_LENGTH_FILE_NAME << "!" << endl;
		} // if
		
		// 	if the record is in the file
		else{
			
			// 3- open the file in the read/write mood 
			fstream file(VARIABLE_LENGTH_FILE_NAME, ios::in | ios::out);
		
			// 4- check the file is opened
			if(!file){ // the file is not opened
				cerr << "Something wrong, " << VARIABLE_LENGTH_FILE_NAME << " did not be opend!\n";
			} // in if
			
			
			else{ // the file is opened	
			
// read the name before deleting the record			
	            // move the read pointer to the beginning of the target record
	            file.seekg(byte_ofset+6);
	
	            // read the name field before deleting the record
	            string name;
	            getline(file, name, '\t');  // Assuming name ends with a tab character


				// 5- move the write head to the beginning of the target record
				file.seekp( byte_ofset );
				
				// 6- mark it as deleted record (using id -1)
				file.write("00-1", 4); 
				
				// 7- get a line to calculate the deleted record size
				string line;	// this is a temp to count the length of the deleted record			 
				getline(file, line); // the length of this line + 4 is the deleted record size

				// erase the data in the deleted record:
				file.seekp( byte_ofset + 4 ); // go after the id of the deleted record 
				for(int i=0; i < line.length(); i++ ) file.write("\0", 1 ); // full the line by spaces 
			
				// 8- insert the byte_ofset and the length to the avail list
				avail.insertNewAvailableRecord(byte_ofset , (line.length() + 4) );

				// 9- close the file
				file.close();
				
				// 10- notify the user
				cout << "Record with id = " << targetId << " has been deleted successfully." << endl << endl;

// index step:
//				index.deleteFromIndex( byte_ofset, VARIABLE_LENGTH_FILE_NAME);
		
										
			} // in else
			
		} // out else
				
	} // daleteVariableLengthRecord


	// update
	void updateVariableLengthRecord( int targetId, VariableLengthRecord updatedRecord ){

		// 1- get the byte_ofset of the target record
		int byte_ofset = sequentialSearchForVariableLengthRecord(targetId);
		
		// 2- check is the record in the file?
		// 	if not, just throw an error
		if( byte_ofset == -1 ){
			cerr << "Record with id = " << targetId << " is not in " << VARIABLE_LENGTH_FILE_NAME << "!" << endl;
		} // if
		
		// 	if the record is in the file
		else{
			
			// 3- open the file in the read/write mood 
			ofstream file(VARIABLE_LENGTH_FILE_NAME, ios::in | ios::out );
		
			// 4- check the file is opened
					// 	if not, just throw an error
			if(!file){ // the file is not opened
					cerr << "Something wrong, " << VARIABLE_LENGTH_FILE_NAME << " did not be opend!\n";
			} // in if
			
			else{ // the file is opened
				
				// 5- move the write pointer to the beginning of that record
				file.seekp( byte_ofset + 6 );


				// 7- update the record
					// id will not be updated
				file <<  updatedRecord.name << "\t\t" // the name is variable length
				     << to_string(updatedRecord.score).substr(0,5) << "\t\t" // set the score in 5 bytes (comma and 4 digits)
					 << setw(11) << setfill('0') << updatedRecord.dateOfBirth;	// there is no new line here	


				// 8- close the file
				file.close();
				
				// 9- notify the user
				cout << "The record with id = "<< targetId << " has been updated successfully." << endl;
			
// index:
//				index.updateRecordInIndex(targetRecord.name, updatedRecord.name, VARIABLE_LENGTH_FILE_NAME);	
		
			} // in else
						
		} // out else
		
	} // updateVariableLengthRecord


// index:
	int sequentialSearchForVariableLengthRecordUsingIndex( string name ){
		return index.searchInIndex(name, VARIABLE_LENGTH_FILE_NAME);
	}// 


	void generate50VariableLengthRecords() {
		
	    addVariableLengthRecord(VariableLengthRecord(2, "Ahmed Khalid Ahmed", 54.73333333233, 1, 7, 1987));
	    addVariableLengthRecord(VariableLengthRecord(3, "Adam Majid Adam", 9.41, 4, 1, 1992));
	    addVariableLengthRecord(VariableLengthRecord(4, "Monzir Osamah Abdurahman", 79, 3, 9, 1996));
	    addVariableLengthRecord(VariableLengthRecord(5, "Osman Sidiq", 89.3, 3, 11, 1991));
	    addVariableLengthRecord(VariableLengthRecord(6, "Awab Jabir", 54.23, 3, 1, 1987));
	    
	    addVariableLengthRecord(VariableLengthRecord(7, "Khalid Ahmed", 93.19, 23, 6, 1990));
	    addVariableLengthRecord(VariableLengthRecord(8, "Abobaker Khaled", 100, 2, 2, 1988));
	    addVariableLengthRecord(VariableLengthRecord(9, "Hassan Malik", 65, 25, 12, 1995));
	    addVariableLengthRecord(VariableLengthRecord(10, "Malik Jibran", 80.3, 16, 7, 1986));
	    addVariableLengthRecord(VariableLengthRecord(11, "Zain Al Abidin", 77.2, 14, 10, 1993));
	
	    addVariableLengthRecord(VariableLengthRecord(12, "Liam Michael", 88.5, 22, 12, 1994));
	    addVariableLengthRecord(VariableLengthRecord(13, "Noah Benjamin", 56.4, 19, 11, 1989));
	    addVariableLengthRecord(VariableLengthRecord(14, "Maya Susan", 62.1, 8, 8, 1986));
	    addVariableLengthRecord(VariableLengthRecord(15, "Sara Nicole", 91.7, 2, 3, 1985));
	    addVariableLengthRecord(VariableLengthRecord(16, "Lara Olivia", 72.8, 13, 5, 1990));
	
	    addVariableLengthRecord(VariableLengthRecord(17, "Mona Nadia", 84.5, 27, 9, 1992));
	    addVariableLengthRecord(VariableLengthRecord(18, "Ali Hassan", 67.2, 17, 4, 1988));
	    addVariableLengthRecord(VariableLengthRecord(19, "Ibrahim Omar", 78.9, 12, 7, 1991));
	    addVariableLengthRecord(VariableLengthRecord(20, "Yasmin Noor", 69.5, 1, 9, 1993));
	    
	    addVariableLengthRecord(VariableLengthRecord(21, "Farah Noor", 83.4, 20, 2, 1987));
	    addVariableLengthRecord(VariableLengthRecord(22, "Amina Sharif", 95.0, 5, 10, 1990));
	    addVariableLengthRecord(VariableLengthRecord(23, "Kareem Saeed", 60.3, 21, 1, 1986));
	    addVariableLengthRecord(VariableLengthRecord(24, "Rami Jamal", 76.5, 26, 6, 1994));
	    addVariableLengthRecord(VariableLengthRecord(25, "Dalia Faisal", 80.7, 7, 11, 1988));
	
	    addVariableLengthRecord(VariableLengthRecord(26, "Salma Malik", 87.6, 3, 4, 1991));
	    addVariableLengthRecord(VariableLengthRecord(27, "Karim Zayed", 71.2, 11, 12, 1995));
	    addVariableLengthRecord(VariableLengthRecord(28, "Layla Ali", 93.1, 9, 6, 1992));
	    addVariableLengthRecord(VariableLengthRecord(29, "Amira Khalid", 68.8, 28, 7, 1990));
	    addVariableLengthRecord(VariableLengthRecord(30, "Zayd Samir", 85.4, 4, 1, 1994));
	
	    addVariableLengthRecord(VariableLengthRecord(31, "Rashid Nadir", 77.3, 24, 8, 1989));
	    addVariableLengthRecord(VariableLengthRecord(32, "Fayza Iman", 79.0, 13, 2, 1987));
	    addVariableLengthRecord(VariableLengthRecord(33, "Tariq Raza", 66.2, 6, 11, 1991));
	    addVariableLengthRecord(VariableLengthRecord(34, "Samira Khadija", 92.4, 12, 9, 1985));
	    addVariableLengthRecord(VariableLengthRecord(35, "Sami Khaled", 85.6, 30, 3, 1989));
	
	    addVariableLengthRecord(VariableLengthRecord(36, "Maha Nour", 72.9, 18, 5, 1994));
	    addVariableLengthRecord(VariableLengthRecord(37, "Jamal Iqbal", 90.1, 8, 7, 1990));
	    addVariableLengthRecord(VariableLengthRecord(38, "Zaki Hani", 76.3, 21, 4, 1987));
	    addVariableLengthRecord(VariableLengthRecord(39, "Rana Fadila", 81.4, 15, 8, 1993));
	    addVariableLengthRecord(VariableLengthRecord(40, "Omar Ibrahim", 68.0, 23, 12, 1986));
	
	    addVariableLengthRecord(VariableLengthRecord(41, "Samiha Noor", 95.5, 2, 6, 1988));
	    addVariableLengthRecord(VariableLengthRecord(42, "Ibrahim Faisal", 84.6, 17, 10, 1995));
	    addVariableLengthRecord(VariableLengthRecord(43, "Reem Malik", 79.8, 9, 4, 1992));
	    addVariableLengthRecord(VariableLengthRecord(44, "Zahra Yasmin", 75.3, 11, 12, 1994));
	    addVariableLengthRecord(VariableLengthRecord(45, "Khalid Saeed", 82.0, 4, 9, 1987));
	
	    addVariableLengthRecord(VariableLengthRecord(46, "Amir Zaid", 78.2, 17, 2, 1991));
	    addVariableLengthRecord(VariableLengthRecord(47, "Sana Omer", 89.7, 23, 8, 1989));
	    addVariableLengthRecord(VariableLengthRecord(48, "Lina Firas", 66.5, 12, 11, 1995));
	    addVariableLengthRecord(VariableLengthRecord(49, "Dina Nabil", 94.8, 20, 4, 1992));
	    addVariableLengthRecord(VariableLengthRecord(50, "Zainab Majid", 70.4, 9, 9, 1990));
	}

}; //VariableLengthFileManagemer

/*

int main(){
	
	VariableLengthFileManagemer fileManager;
	
	// create a file to store variable length records
	fileManager.createVariableLengthFile();
	
	// adding 10 records to the file
	fileManager.addVariableLengthRecord( VariableLengthRecord(1,"Omar Adam",95.3, 30,5,1985) );
	fileManager.addVariableLengthRecord( VariableLengthRecord(2,"Ahmed Khalid Ahmed",54.73333333233, 1,7,1987) );
	fileManager.addVariableLengthRecord( VariableLengthRecord(3,"Adam Majid Adam",9.41, 4,1,1992) );
	fileManager.addVariableLengthRecord( VariableLengthRecord(4,"Monzir Osamah Abdurahman",79, 3,9,1996) );
	fileManager.addVariableLengthRecord( VariableLengthRecord(5,"Osman Sidiq",89.3, 3,11,1991) );
	fileManager.addVariableLengthRecord( VariableLengthRecord(6,"Awab Jabir",54.23, 3,1,1987) );
	fileManager.addVariableLengthRecord( VariableLengthRecord(7,"Khalid Eltigany",93.19, 23,6,1990) );
	fileManager.addVariableLengthRecord( VariableLengthRecord(8,"Abobaker Mohamed",100, 2,2,1988) );
	fileManager.addVariableLengthRecord( VariableLengthRecord(9,"rak",65, 25,12,1995) );
	fileManager.addVariableLengthRecord( VariableLengthRecord(10,"Malik Ibrahim",80.3,16,7,1986) );

	// test the finding fun.
	cout<< endl << "Test Find Function (finding the record with id = 7)\n";
	int byte_ofset = fileManager.sequentialSearchForVariableLengthRecord( 7 );	// the new version of find (paramiter type of int)
	if(byte_ofset != -1) cout << "Record with id = 7 has byte_ofset = " << byte_ofset << endl;
	else cout << "Record with id = 7 is not found in " << VARIABLE_LENGTH_FILE_NAME <<"!" << endl;


	// test deleting fun.
	cout<< endl << "Test Deleting Function:\n";	// the new verstion of delete (paramiter type of int)
	
	fileManager.daleteVariableLengthRecord( 4 ); // is not in the file
	fileManager.daleteVariableLengthRecord( 2 );
	fileManager.daleteVariableLengthRecord( 9 );
	
	// test reclaimming space:
	fileManager.addVariableLengthRecord( VariableLengthRecord(11,"Abu Eljod",79, 3,9,1988) );
	fileManager.addVariableLengthRecord( VariableLengthRecord(12,"Abssssssssssssssssssssssu",79, 3,9,7777) );
	fileManager.addVariableLengthRecord( VariableLengthRecord(13,"Abbbbbbbbbbbbbbbbb",79, 3,9,1988) );


	// test the updating fun.
	cout<< endl << "Test Updating Function:\n";
	fileManager.updateVariableLengthRecord( VariableLengthRecord(7,"Monzir Adam Khalid",79, 3,9,1996), VariableLengthRecord(4,"Mohamed Awad",70.7, 7,6,1991) );

	cout << "Test Searching Function Using Index:\n";
	int address = fileManager.sequentialSearchForVariableLengthRecordUsingIndex("Osman Sidiq");
	cout << "Its address in: " << address << ".\n";

}// main



*/





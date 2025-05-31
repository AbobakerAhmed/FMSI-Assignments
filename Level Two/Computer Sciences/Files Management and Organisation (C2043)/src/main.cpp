// Date: 10th - 18th of Dec 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:    ....
// D:     Computer Science
// Title: File Management and Organization Assignment

/*  About This File (main.cpp)
    This is the result of working hard on the parion: the 10th to the 18th of December 2024
	It contains the main function which run our program
	It also contains masuring time of searching (Task 2-1-b)
	Plased: Abobaker Ahmed.          
*/
// #include "VariableLengthFileManager.cpp" // in FixedLengthFileManager.cpp
#include "FixedLengthFileManager.cpp"
#include <chrono> // masure the time

using namespace std;


int main(){
	cout << "Hello, Welcome to the files management system" << endl << endl;
	
	short choice1, choice2;

	do {
		
		cout << "which one you want to deal with?\n"
			 << "0- exit the program\n"
			 << "1- fixed length records file\n"
			 << "2- vriable length records file\n"
			 << "your choice: ";
			 cin >> choice1;
			  cout << endl;
			 if( choice1 == 0)
			 	break;
			 	
			else if( choice1 == 1){
				
				FixedLengthFileManagement fixedLengthFileManagemer;
				fixedLengthFileManagemer.createFixedLengthFile();
				
				cout << endl;
						
				int id;
				short dayOfBirth, monthOfBirth;
				int yearOfBirth, rrn;
				double score;
				char name[FIXED_RECORD_LENGTH - 27];
				do
				{
					cout << "enter you choice\n"
						 << "0- exit the program\n"
						 << "1- go back\n"
						 << "2- generate 50 records\n"
						 << "3- add a record\n"
						 << "4- delete a record\n"
						 << "5- update a record\n"
						 << "6- search for a record\n"
						 << "7- access a record\n"
						 << "you choice: ";		 
					
					cin >> choice2;
					
					switch (choice2){
						case 0:
							choice2 =0;
							choice1 =0;
							break;
							
						case 1:
							choice2 =0;
							break;
							
						case 2:
							fixedLengthFileManagemer.generate50fixedLengthRecords();
							break;
						case 3:
							cout << "enter the name: ";
							// ignore the '\n' recently inserted when entering indexNumber
							cin.ignore();
							cin.getline(name, FIXED_RECORD_LENGTH - 27);

							
							cout << "enter the score (0 - 100): ";
							cin >> score;
							// ignore the '\n' recently inserted when entering indexNumber
							cin.ignore();
							
							cout << "enter date of birth as:\nday(1-31): ";
							cin >> dayOfBirth;
							cin.ignore();
							cout << "month(1-12): ";
							cin >> monthOfBirth;
							cin.ignore();
							cout << "year(1980-2020): ";
							cin >> yearOfBirth;
							cin.ignore();
							fixedLengthFileManagemer.addFixedLengthRecord( FixedLengthRecord(0, name, score, dayOfBirth, monthOfBirth, yearOfBirth));					
							break;
			
						case 4:
							cout << "enter the id: ";
							cin >> id;
							cin.ignore();
							fixedLengthFileManagemer.daleteFixedLengthRecord( id );
							break;
						case 5:
							cout << "enter the id: ";
							int id;
							cin >> id;							
							cin.ignore();
							cout << "enter the new name: ";
							// ignore the '\n' recently inserted when entering id
							cin.ignore();
							cin.getline(name, FIXED_RECORD_LENGTH - 27);

							
							cout << "enter new score (0 - 100): ";
							// ignore the '\n' recently inserted when entering indexNumber
							cin.ignore();
							cin >> score;

							
							cout << "enter new date of birth as:\nday(1-31): ";
							cin >> dayOfBirth;
							cin.ignore();
							cout << "month: ";
							cin >> monthOfBirth;
							cin.ignore();
							cout << "year: ";
							cin >> yearOfBirth;
							cin.ignore();
							fixedLengthFileManagemer.updateFixedLengthRecord(id, FixedLengthRecord(0,name, score, dayOfBirth,monthOfBirth, yearOfBirth));
							break;
							
						case 6:
							cout << "enter id: ";
							cin >> id;
							cin.ignore();

// Start time measurement
				//			auto start = chrono::high_resolution_clock::now();	
							rrn = fixedLengthFileManagemer.binarySearch(id);

// End time measurement
				//		    auto end = chrono::high_resolution_clock::now();
							if(rrn == -1) cout << "Record is not found!\n";
							else cout << "Rcord is found, it is the " << rrn+1 << "th record in the file.\n";
// Print the time							
				//			auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
				//			cout << "Time taken for search: " << duration.count() << " milliseconds\n";	
						
							break;
							
						case 7:
							cout << "enter id: ";
							cin >> id;
							FixedLengthRecord myRecord = fixedLengthFileManagemer.directAccess(id);
							cout << "Name: " << myRecord.name << endl;
							cout << "Score: " << myRecord.score << endl;
							cout << "Date of Birth: " << myRecord.dateOfBirth << endl;
							break;
									
//						default:
//							cout << "unsupported choice " << choice2 << '\n';
//							break;
						}
					
					cout << endl;
				
				} while (choice2 != 0);
					
			}// else if

			
			else if( choice1 == 2){
				VariableLengthFileManagemer variableLengthFileManagemer;
				variableLengthFileManagemer.createVariableLengthFile();
							
				cout << endl;
				
				int id;
				short dayOfBirth, monthOfBirth;
				int yearOfBirth;
				double score, address;
				string name;
				do
				{
					cout << "enter you choice\n"
						 << "0- exit the program\n"
						 << "1- go back\n"
						 << "2- generate 50 records\n"
						 << "3- add a record\n"
						 << "4- delete a record\n"
						 << "5- update a record\n"
						 << "6- search for a record\n"
						 << "you choice: ";		 
					
					cin >> choice2;
					
					switch (choice2){
						case 0:
							choice2 =0;
							choice1 =0;
							break;
							
						case 1:
							choice2 =0;							
							break;
						case 2:
							variableLengthFileManagemer.generate50VariableLengthRecords();
							break;
							
						case 3:
							cout << "enter the name: ";
							cin >> name;
							// ignore the '\n' recently inserted when entering indexNumber
							cin.ignore();
							
							cout << "enter score (0 - 100): ";
							cin >> score;
							// ignore the '\n' recently inserted when entering indexNumber
							cin.ignore();
							
							cout << "enter date of birth as:\nday(1-31): ";
							cin >> dayOfBirth;
							cin.ignore();
							cout << "month(1-12): ";
							cin >> monthOfBirth;
							cin.ignore();
							cout << "year(1980-2020): ";
							cin >> yearOfBirth;
							cin.ignore();
							variableLengthFileManagemer.addVariableLengthRecord( VariableLengthRecord(0,name, score, dayOfBirth, monthOfBirth, yearOfBirth));					
							break;
			
						case 4:
							cout << "enter the id: ";
							int id;
							cin >> id;
							cin.ignore();
							variableLengthFileManagemer.daleteVariableLengthRecord( id );
							break;
						case 5:
							cout << "enter the id: ";
							cin >> id;
							cin.ignore();
							
							cout << "enter the new name: ";
							cin >> name;
							// ignore the '\n' recently inserted when entering indexNumber
							cin.ignore();
							
							cout << "enter new score (0 - 100): ";
							cin >> score;
							// ignore the '\n' recently inserted when entering indexNumber
							cin.ignore();		
							cout << "enter new date of birth as:\nday(1-31): ";
							cin >> dayOfBirth;							
							cin.ignore();
							cout << "month: ";
							cin >> monthOfBirth;
							cin.ignore();
							cout << "year: ";
							cin >> yearOfBirth;
							cin.ignore();
							variableLengthFileManagemer.updateVariableLengthRecord(id,VariableLengthRecord(0,name, score, dayOfBirth, monthOfBirth, yearOfBirth));
							break;
							
						case 6:
					

							cout << "enter id: ";
							cin >> id;
							cin.ignore();

// Start time measurement
			//				auto start = chrono::high_resolution_clock::now();
							address = variableLengthFileManagemer.sequentialSearchForVariableLengthRecord(id);
							if(address ==-1) cout << "Record is not found!\n";
							else cout << "Record is found, its address is: " << address << ".\n";
// End time measurement
    		//				auto end = chrono::high_resolution_clock::now();

// Print the time							
			//				auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
			//				cout << "Time taken for search: " << duration.count() << " milliseconds\n";	
							break;
							
						default:
							cout << "unsupported choice " << choice2 << '\n';
							break;
						}
					
					cout << endl;
				
				} while (choice2 != 0);
			}
				


			else
				cout << "unsupported choice " << choice1 << '\n';
		
			cout << endl;
	}while(choice1 != 0); 	

	
	
	return 0;
	
} // main

// Date: 18th of Oct 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:   ....
// D:    CS

/**
		Assignment(8&9): Test Student Class
*/

public class TestStudent{

	public static void main(String [] args){

		// Define and create and intialize objects from Student class 
		Student st1 = new Student("Abobaker",304);
		Student st2 = new Student("Adam",202);
		Student st3 = new Student("Mazin",107);
		Student st4 = new Student("Omer" , 509);
	
		double [] abobakerGrades = {90,89.5,79,95.7,50};
 		st1.addGrade(abobakerGrades); // adding an array of grades
		st1.displayInfo();	// printing informations of the 1st object 
		
		st2.addGrade(80.3); // adding a single gread
		st2.displayInfo();  // printing informations of the 2nd object 

		double [] mazinGrades = { 50.6, 70.7, 89.5, 102, -3.5}; // incorect grades
 		st3.addGrade(mazinGrades); // adding an array of grades
		st3.displayInfo();	// printing informations of the 1st object 		

		double [] omerGrades = {11, 3, 7, 3, 9.7, 5}; // incorect num of grades
 		st4.addGrade(omerGrades); // adding an array of grades
		st4.displayInfo();	// printing informations of the 1st object 
	} // main

} // TestStudent
// Date: 9th of Oct 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:   ....
// D:    CS

/**
		Assignment of Lab 7: Student Grade Calculator
*/

// 1. Create a Student Class:
public class Student{

	// The class should have the following attributes:
	private String studentName = "Unknown";
	private int studentID = 999;

	// 2. Constructor Overloading: Create two constructors for the Student class:
	//Constructor 1: Takes studentName and studentID as parameters.
	Student(String studentName, int studentID){
		this.studentName = studentName;
		this.studentID = studentID;
	} //Constructor 1

	//Constructor 2: Takes only studentName and assigns a default studentID 
	Student(String studentName){
		this.studentName = studentName;
	} //Constructor 2

	
	// 3. Method Overloading: Create overloaded methods named calculateGrade:
	/* Version 1: Takes one integer parameter representing the marks
	   out of 100 and prints the corresponding grade (A, B, C, D, or F). */
	public void calculateGrade(int marks){
		char gread = '0';
		if(marks < 0 || 100 < marks) System.out.println("Pleas enter a real mark");
		else if(marks >= 90) gread = 'A'; // 90-100: A
		else if(marks >= 80) gread = 'B'; // 80-89: B
		else if(marks >= 70) gread = 'C'; // 70-79: C
		else if(marks >= 60) gread = 'D'; // 60-69: D
		else gread = 'F';			    // Below 60: F
		System.out.println("Sudent: " + this.studentName + "\nID: " + this.studentID);
		System.out.println("Grade for " + marks + " marks: " + gread);
		System.out.println();
	} //calculateGrade Version 1
	
	/* Version 2: Takes three integer parameters representing the marks of three
	   subjects, calculates the average, and prints the
	   corresponding grade */
	public void calculateGrade(int marksOfSubject1, int marksOfSubject2, int marksOfSubject3){
		//Each of them mast be between 0 - 100.
		if(marksOfSubject1 < 0 || 100 < marksOfSubject1) System.out.println("Pleas try again and enter real marks");
		else if(marksOfSubject2 < 0 || 100 < marksOfSubject2) System.out.println("Pleas try again and enter real marks");
		else if(marksOfSubject2 < 0 || 100 < marksOfSubject2) System.out.println("Pleas try again and enter real marks");
		else{
			char gread = '0';
			double avrage = (marksOfSubject1 + marksOfSubject2 + marksOfSubject3) / 3;
			if(avrage >= 90) gread = 'A'; // 90-100: A
			else if(avrage >= 80) gread = 'B'; // 80-89: B
			else if(avrage >= 70) gread = 'C'; // 70-79: C
			else if(avrage >= 60) gread = 'D'; // 60-69: D
			else gread = 'F';	
			System.out.println("Sudent: " + this.studentName + "\nID: " + this.studentID);
			System.out.println("Avrage grade for marks " + marksOfSubject1 + ", " + marksOfSubject2 + ", " + marksOfSubject3 + ": " + gread);
			System.out.println();
		} // else
	} //calculateGrade Version 2

	
	// 5. Create a Main Class:
	public static void main(String [] args){
		// create objects of the Student class using both constructors.
		Student student1 = new Student("Ahmed Ali", 101); // Using Constructor 1
		Student student2 = new Student("Salih Omer"); // Using Constructor 2

		// Test the overloaded calculateGrade methods with single and multiple subject marks.
		student1.calculateGrade(95); // Using version 1
		student1.calculateGrade(95,80,74); // Using version 2

		student2.calculateGrade(82);	// Using version 1
		student2.calculateGrade(80,89,85);	// Using version 2

	} //main 		

} //Student

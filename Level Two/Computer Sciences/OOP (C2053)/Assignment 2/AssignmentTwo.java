// Date: 7th of September 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:   ....
// D:    Computer Science

/**
	Assignment 2 of Lab 2: Java Application to Calculate the Student GPA Out of 100
*/

import java.util.*; // to use inputs
public class AssignmentTwo{
static Scanner input = new Scanner(System.in);

public static float getGPA(){
		double gpa;
		while(true){
			gpa  = input.nextDouble();
			if( gpa <= 100 && gpa >= 0 ) break;
			else System.out.println("Your gpa must be in [0,100]!");
		} //while
		return (float) gpa;
	} //checkGPA

	public static void main(String [] args){
		// Get the Student's name:
		System.out.print("Inter your name: ");	String name = input.nextLine();

		// Get GPAs:
		System.out.println("Inter your GPAs in");
		System.out.print("Arabic: ");	float arabic = getGPA();	// Arabic
		System.out.print("English: ");	float english = getGPA();	// English
		System.out.print("OOP: ");		float oop = getGPA();	// OOP
		System.out.print("C++: ");		float cpp = getGPA();	// C++
		System.out.print("Python: ");	float python = getGPA();	// Python
		
		// Calculate the Avarage:
		double avarage = ( arabic + english + oop + cpp + python ) / 5 ;

		// Display the result:
		System.out.printf("%s, your avarage is: %2.2f\n",name,avarage);
		
		if(avarage > 50)  System.out.println("Congratlation! , you did pass!");	// he/she passed
		else			System.out.println("You didn't pass!");			// he/she didn't pass

	} //main

} //AssignmentTow
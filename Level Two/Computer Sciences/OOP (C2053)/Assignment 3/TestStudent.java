// Date: 17th of Sep 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:   ....
// D:    CS


/**
		Ass 3 of OOP
	1:   Create a class named Student has (String name, Integer age, Double gread)
	2-1: Defind a constructor that sets (name, age, gread)
	2-2: Defind the default constructor (with default values) 
	3-1: Defind void displayDetails
	3-2: Defind bool hasPassed
	4-1: Create at least 3 Obj. of class Student
	4-2: Use those methods with your obj.
*/


// 1:
class Student{

	private String name = "Unknown";
	private int age = 0;
	private double gread = 0;

	//2-1:
	Student(String name, int age, double gread){
		this.name = name;
		this.age = age;
		this.gread = gread;
	}// constructor 1
	
	//2-2:
	Student(){} // constructor 2

	//3-1:
	public void displayDetails(){
		System.out.println("Name: " + this.name);
		System.out.println("Age: " + this.age);
		System.out.println("Gread: " + this.gread);
	} // displayDetails

	//3-2:
	public boolean hasPassed(){
		if(gread >= 50){
			System.out.println("he\\she has passed.\n");
			return true;
		} //if
		else 
			System.out.println("he\\she has not passed.\n");
		return false;
	} //hasPassed

}// Student 


public class TestStudent{

	public static void main(String [] args){
		//4-1:
		Student studentOne = new Student("Osama", 20, 70.4);
		Student studentTwo = new Student("Omnia", 21, 50);
		Student studentThree = new Student("Mazin", 19, 38.9);
		Student studentFour = new Student();
		
		//4-2:
		studentOne.displayDetails();
		studentOne.hasPassed();

		studentTwo.displayDetails();
		studentTwo.hasPassed();

		studentThree.displayDetails();
		studentThree.hasPassed();

		studentFour.displayDetails();
		studentFour.hasPassed();		
	} // main 

} // TestStudent
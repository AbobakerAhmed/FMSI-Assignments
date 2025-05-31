//Date: 22nd of July 2024
//Name: Abobaker Ahmed Khidir Hassan
//ID:   21-304
//D:    CS


/**
	Lab 9&10 Assignment
	Exercise 2
	Part 4: Object Casting
	Step 6: Practice Object Casting
*/

// 1.	Create a TestCasting class with a main method.
public class TestCasting{

	public static void main(String [] args){

		Animal animal1 = new Animal();	Dog dog1 = new Dog();
		Animal animal2 = new Animal();	Cat cat1 = new Cat(); 

		//2.	Perform downcasting: 
		animal1 = dog1; 
		System.out.println("Downcasting is done successfully.\n"); //will be printed 

		//2.	Perform upcasting:
		cat1 = (Cat) animal2; //It looks like tring to store an integer in a byte.
		System.out.println("Upcasting is done successfully.\n"); //Will not be printed
			
	}//main

}//TestCasting
//Date: 24th of July 2024
//Name: Abobaker Ahmed Khidir Hassan
//ID:   21-304
//D:    CS


/**
	Lab 9&10 Assignment
	Exercise 2
	Tasks
	2.	Implement a scenario where upcasting and downcasting are
		used correctly with the `Bird` class.

	- It can be done correctly if the Animal object was storing a Bird
	  object when we try to assign it.
	- In another words, we can it by do the downcasting before the upcasting 
	  between Animal and Bird.
*/



public class TestCastingInBird2{

	public static void main(String [] args){
		Animal animal3 = new Animal();	Bird bird1 = new Bird();
		
		try{
			//Upcasting:
			bird1 = (Bird) animal3; //It looks like tring to store an integer in a byte.
			System.out.println("Upcasting is done successfully.\n"); //Will be printed

			//Downcasting: 
			animal3 = bird1; 
			System.out.println("Downcasting is done successfully.\n"); //will be printed

		}//try
		catch(ClassCastException ex){
			System.out.println("Error: The is some error in this type casting!");
		}//catch

	}//main

}//TestCastingInBird

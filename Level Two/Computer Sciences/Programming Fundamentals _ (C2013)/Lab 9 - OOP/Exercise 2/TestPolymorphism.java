//Date: 22nd of July 2024
//Name: Abobaker Ahmed Khidir Hassan
//ID:   21-304
//D:    CS

/**
	Lab 9&10 Assignment
	Exercise 2
	Part 2: Polymorphism
	Step 4: Use Polymorphism
*/


// 1.	Create a TestPolymorphism class with a main method.
public class TestPolymorphism{
	
	public static void main(String [] args){
		// 2.	Declare variables of type Animal and assign them instances of Dog and Cat.
		Animal dog = new Dog();
		Animal cat = new Cat();

		// 3.	Call the makeSound() method on each variable and check the output.
		dog.makeSound();
		cat.makeSound();
	}//main

}//TestPolymorphism
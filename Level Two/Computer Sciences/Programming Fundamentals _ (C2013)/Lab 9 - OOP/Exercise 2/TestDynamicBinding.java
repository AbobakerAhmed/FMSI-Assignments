//Date: 22nd of July 2024
//Name: Abobaker Ahmed Khidir Hassan
//ID:   21-304
//D:    CS


/**
	Lab 9&10 Assignment
	Exercise 2
	Part 3: Dynamic Binding
	Step 5: Understand Dynamic Binding
*/

// 1.	Create a TestDynamicBinding class with a main method.
public class TestDynamicBinding{

	public static void main(String [] args){
		
		// 2.	Declare a variable of type Animal.
		Animal animal;
		
		// 3.	Assign it an instance of Dog and call makeSound().
		animal = new Dog();
		animal.makeSound();

		// 4.	Assign it an instance of Cat and call makeSound().
		animal = new Cat();
		animal.makeSound();
		
	}//main

}//TestDynamicBinding

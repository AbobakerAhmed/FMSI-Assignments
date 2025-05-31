//Date: 22nd of July 2024
//Name: Abobaker Ahmed Khidir Hassan
//ID:   21-304
//D:    CS


/**
	Lab 9&10 Assignment
	Exercise 2
	Part 1: Inheritance
	Step 2: Create Derived Classes
*/


// 1.	Create a class called Dog that extends Animal.
class Dog extends Animal{

	Dog(){ super("Dog"); }//constructor

	// 2.	Override the makeSound() method to print "Dog barks".
	@Override
	public void makeSound(){
		System.out.println("Dog barks");
	}//makeSound

}//Dog
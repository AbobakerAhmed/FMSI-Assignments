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

// 3.	Create a class called Cat that extends Animal.
class Cat extends Animal{

	Cat(){ super("Cat"); }//constructor

	// 4.	Override the makeSound() method to print "Cat meows".
	@Override
	public void makeSound(){
		System.out.println("Cat meows");
	}//makeSound

}//Cat
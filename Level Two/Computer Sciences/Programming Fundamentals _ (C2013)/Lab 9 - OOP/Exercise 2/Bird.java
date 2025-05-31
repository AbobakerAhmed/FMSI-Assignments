//Date: 22nd of July 2024
//Name: Abobaker Ahmed Khidir Hassan
//ID:   21-304
//D:    CS


/**
	Lab 9&10 Assignment
	Exercise 2
	Tasks
*/


// 1.a) Extend the `Animal` class to include another derived class called `Bird`.
class Bird extends Animal{

	Bird(){ super("Bird"); }//constructor
	
	// 1.b) Override the `makeSound()` method.
	public void makeSound(){
		System.out.println("Birds Sound");
	}//makeSound

}//Bird
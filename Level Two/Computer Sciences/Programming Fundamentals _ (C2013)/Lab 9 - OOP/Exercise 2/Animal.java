//Date: 22nd of July 2024
//Name: Abobaker Ahmed Khidir Hassan
//ID:   21-304
//D:    CS


/**
	Lab 9&10 Assignment
	Exercise 2
	Part 1: Inheritance
	Step 1: Create a Base Class
*/


// 1.	Create a class called Animal. 
class Animal{

	// 2.	Add a string field name.
	private String name; 	
	
	// 3. Add a constructor that initializes the name field.
	Animal(){
		this.name = "Animal";
	}//constructor 1
	Animal(String name){
		this.name = name;
	}//constructor 2
	
	public void setName(String name){ this.name = name; }//setName
	public String getName(){ return this.name; }//getName

	// 4. Add a method makeSound() that prints "Animal makes a sound".
	public void makeSound(){
		System.out.println("Animal makes a sound");
	}//makeSound

}// Animal
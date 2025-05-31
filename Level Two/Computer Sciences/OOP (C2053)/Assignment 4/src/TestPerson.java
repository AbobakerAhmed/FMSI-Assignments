// Date: 23rd of Sep 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:   ....
// D:    CS


//		Assignament 2 of Lab 4: Person in Java		\\

public class TestPerson{

	public static void main(String [] args){
		
		// Create an object type Person:
		Person person1 = new Person("Adam", 23);

		// Use getters to print its details
		System.out.println("Name: " + person1.getName());
		System.out.println("Age: " + person1.getAge());
		System.out.println("Nationality: " + person1.getNationality());
		System.out.println("Phone: " + person1.getPhone());

		System.out.println();

		// Use setters to reset its attributes
		person1.setName("Ahmed");
		person1.setAge(30);
		person1.setNationality("Sudanies");
		person1.setPhone(999757397);

		//Use printPersonDetails() to print the new info
		person1.printPersonDetails();		

				
	} // main

} //TestPerson

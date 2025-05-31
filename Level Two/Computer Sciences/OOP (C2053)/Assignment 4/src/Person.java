// Date: 23rd of Sep 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:   ....
// D:    CS


//		Assignament 2 of Lab 4: Person in Java		\\

// 1- Create a class named person
class Person{
	
	// 1.2: Attributes
	private String name = "Unknown";
	private int age = 0;
	private String nationality = "Unknown";
	private int phone = 0000000000;
	
	// 1.3: Constructors
	Person(String name, int age){
		this.name = name;
		this.age = age;
	} //Constructor 1

	Person(String name, int age, String nationality, int phone){
		this.name = name;
		this.age = age;
		this.nationality = nationality;
		this.phone = phone;
	} //Constructor 2
	
	// 1.4: Getters
	public String getName(){ return this.name; } //getName
	public int getAge(){ return this.age; } //getAge
	public String getNationality(){ return this.nationality; } //getNationality
	public int getPhone(){ return this.phone; } //getPhone

	// 1.5: Setters
	public void setName(String name) { this.name = name; } // setName
	public void setAge(int age) { this.age = age; } // setAge
	public void setNationality(String nationality) { this.nationality = nationality; } // setNationality
	public void setPhone(int phone) { this.phone = phone; } // setPhone

	// 1.6: printPersonDetails
	public void printPersonDetails(){
		System.out.println("Name: " + this.name);
		System.out.println("Age: " + this.age);
		System.out.println("Nationality: " + this.nationality);
		System.out.println("Phone: " + this.phone);
	} //printPersonDetails

} //Person

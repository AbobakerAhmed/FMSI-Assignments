// Date: 18th of Oct 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:   ....
// D:    CS

/**
		Assignment(8&9): Students Management Class

	Create a basic system to manage student grades for a university course.
	The system should handle student information and allow for:
	adding, searching, and displaying grades.

*/

// 1. Create a class named Student
public class Student{

	// with the following attributes:
	private String name = "Unkown";	// (student's name)
	private int id = 0;			// (student's ID number)
	private double [] grades; 		// (array to store up to 5 grades)
		

	// 2: Methods
	
	// Constructor to initialize name, id, and an empty grades array.
	Student(String name, int id){
		this.name = name; // initialize name
		this.id = id;	// initialize id
		this.grades = new double [5];
	} // Constructor 1
	

	/* Method to add grades:
         Overload the addGrade() method to allow adding grades in two ways:
		1- addGrade(double grade) – adds a single grade.
		2- addGrade(double[] grades) – adds multiple grades at once.
	*/

	public void addGrade(double grade){ this.grades[0] = grade; } // addGrade1
	public void addGrade(double [] grades){
		if(grades.length <= 5){
			for(int i=0; i < grades.length ; i++){

				if(0 <= grades[i] && grades[i] <= 100)
					this.grades[i] = grades[i];
				else	
					System.out.printf("There is a wrong in %s's grade number %d\n" , this.name, i+1);
			} // for

		} // if
		else
			System.out.printf("There is a wrong in %s's number of grades\n" , this.name);
	} // Overloaded addGrade


	// 3.Method to display student information: displayInfo()
	public void displayInfo(){
		System.out.printf("Name: %s\nID: %s\nGreads: ", this.name, this.id);
		for(int i=0; i < grades.length ; i++)
			System.out.print(this.grades[i] + " , ");
		System.out.print("\n\n");
	} // displayInfo

} //Student

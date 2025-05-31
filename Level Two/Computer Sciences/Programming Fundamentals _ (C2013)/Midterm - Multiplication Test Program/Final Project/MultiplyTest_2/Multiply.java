// Project 1: Multiply.java
// Program generates single digit multiplication problems
// Date: 20th of June 2024

//Name: Abobaker Ahmed Khidir Hassan
//ID:   ....
//D:    Computer Science


/* 
	- This is the 2nd version of MultiplyTest Project
	  Motivation massages are added to display one of them randomly with each guess
	
	- In section (4- Program Templet) line 18 you asked me to call checkResponse to display a question
	  I think that will make an error because the guess doesn't have a value till now.
	    + we don't need anything here except creating a question. so I used createQuestion().

*/


import java.util.*; 

public class Multiply
{

	Random randomNumbers = new Random(); // from java.util

	//I changed the data type of answer to byte because the maximum possible value in the program is 81 ( 9 * 9 )
	byte answer; // the correct answer



	
//_______________ 1. quiz ___________________\\

	// ask the user to answer multiplication problems
	public void quiz()
	{
		Scanner input = new Scanner( System.in );

		int guess; // the user's guess

		createQuestion(); // you can see the first comment above the class header and the report for more informations

		//get the user's guess
		System.out.println( "Enter your answer (-1 to exit):" );
		guess = input.nextInt();
		
		//the test will be repeatedlly ales the user enters -1
		while ( guess != -1 )
		{
			//checks the user's guess
			checkResponse(guess);

			//getting the guess of the next question if the guess was correct or the guess of the same question if the last guess was incorrect
			System.out.println( "Enter your answer (-1 to exit):" );
			guess = input.nextInt();
	
		} // end while

	} // end method



//___________ 2. createQuestion ___________________\\
	
	// geterate two one-digit numbers and display the question
	public void createQuestion()
	{
		//generating two random numbers and storing them at digit1 and digit2
		byte digit1 = (byte) randomNumbers.nextInt(1,9); // using nextInt() method from class Random from 1 to 9
		byte digit2 = (byte) randomNumbers.nextInt(1,9); // we don't need int, byte is more than enough
		
		answer = (byte) (digit1 * digit2); //store the correct answer at the globule variable answer
		System.out.printf( "How much is %d times %d?\n", digit1, digit2 ); // display the question

	} // end method createQuestion




//___________ 3. checkResponse ___________________\\

	//checks user's answers is correct or not?
	public void checkResponse(int guess)
	{
		//if the user's guess is incorrect
		if(guess != -1 && guess != answer){
			createResponse(false); // calling creatResponse to display a motivation massages for an incorrect guess
			//the same question will be asked so there is no creating of a new question here
		} // end if

		//the answer is correct
		else
		{
			createResponse(true); // calling creatResponse to display a motivation massages for a correct guess  
			createQuestion(); // ask another question

		} // end else

	} // end method checkResponse






//___________ 4. creatResponse ___________________\\
	
	// create response with each answer
	public void createResponse(boolean isCorrect){

		if(isCorrect){ //guess = answer

			/* The response of a correct answer */	
			switch(randomNumbers.nextInt(1,5)){
				case 1: System.out.println("Very good!");break;  
				case 2: System.out.println("Excellent!");break;
				case 3: System.out.println("Nice work!");break;
				case 4: System.out.println("Keep up the good work!");break;
	
			}//swich
		}//if

		else{ // guess != answer
	
			/* The response of an incorrect answer */
			switch(randomNumbers.nextInt(1,5)){
				case 1: System.out.println("No.Please try again.");break;  
				case 2: System.out.println("Wrong. Try once more.");break;
				case 3: System.out.println("Don't give up!");break;
				case 4: System.out.println("No. Keep trying.");break;

			}//swich
	
		}//else if

	}//end creatResponse method



} // end class Multiply
//Name: Abobaker Ahmed Khidir Hassan
//D:    Computer Science
//ID:   ....

/**

					//	Area Calculator	\\
				_______________________________________

	- squares area = width^2 = length^2
	- rectangles area = length * width

	- #Note: In Instructions-> 3-> c,d: You made the calling in a statement and the displying
	  in anothe statmentm, so I understanded that the method should returns a value and I have
	  to display it using another statement -like what I made-.
	  # These methodes return the area or -1 if there is wrong valuse ard enterd.

	- I think there is some method that checks if the string is number or not. But I don't know it,
	  so I made one,
	  It returns true only if the string is possitive number, you can check it under the main method.

*/



//____________________________________________________________________________________________________\\


import java.util.Scanner;

//1: Create a class named AreaCalculator
public class AreaCalculator{


	//2: Implement Overloaded Methods:


	//------------ a: Implement a method to compute the area of a square. -------------------\\

		public static double computeArea(String length){
			
			//Possitive number inputs check 
			if(isPossitiveNumber(length)){ //This method is under the main method.

				//Change it to double
				double dLength= Double.parseDouble(length);
				return (dLength*dLength);

			}//if possitive number inputs check

			//Wrong valus:			
			return -1;

		}//computeArea (a)Square


	//----------- b: Implement an overloaded method to compute the area of a rectangle. -------\\

		public static double computeArea(String length,String width){

			//Numerical inputs check
			if(isPossitiveNumber(length) && isPossitiveNumber(width)){ //This method is under the main method.

				//change them to daubles
				double dLength= Double.parseDouble(length);
				double dWidth=  Double.parseDouble(width);
				return (dLength*dWidth);

			}//if possitive number inputs check

	

			//Wrong valus:
			return -1;
	
		}//computeArea (b)Rectangle



//________________________ 3: Implement Main Method. ______________________________\\

	
	public static void main(String[] args){
		
		Scanner input= new Scanner(System.in);



		//a: Choosing between calculating the area of a square or a rectangle.
		String choice; //to make sure the enterd value will not make an error.
		System.out.println("Choose the shape to compute the area:\n1. Square\n2. Rectangle");
		
		//check and retrying if the enterd value is wrong.
		do{
			choice= input.nextLine();


			//b: Based on the user's choice, prompt for the necessary dimensions.
			//We have 4 cases (Stop the programe, Square area, Rectangle area, and wrong input)
			//I made them with (if,else if) because choice is a string


		//--------------- 1- Stop the programe ---------------------\\

			if(choice.equals("-1")){
				System.out.println("\nSee you again :)");
				break;		
			}//if			

		//-------------------- 2- Square Area --------------------------\\
			
			else if(choice.equals("1")){//he\she chosed a square.

				///get the length of one side:
				System.out.print("Enter the length of one side of the square: ");
				String length = input.nextLine();
				
				//c:Call the appropriate method,
				if(computeArea(length)==-1)
					System.out.println("Pleas enter the a correct value \n1. Square\n2. Rectangle \n-1. to exit");

				else{
					//d: Display the computed area.
					System.out.printf("The area is: %1.1f\n",computeArea(length));
					break;
				}//else
		
			}//else if of sqauare


		//--------------------- 3- Rectangle Area --------------------------\\
			
			else if(choice.equals("2")){ //he\she chosed a rectangle.

				//ask the user and get the length of two diffrent sides of the rectangle.
				//Get them in strings to make sure they will not make an error
				System.out.println("Enter the length and the width of the rectangle:");
				System.out.print("The length: ");
				String length = input.nextLine();
				System.out.print("The width: ");
				String width = input.nextLine();

				//c:Call the appropriate method,
				if(computeArea(length,width)==-1)
					System.out.println("Pleas try again and enter the a correct value \n1. Square\n2. Rectangle \n-1. to exit");

				else{
					//d: Display the computed area.
					System.out.printf("The area is: %1.1f\n",computeArea(length,width));
					break;
				}//else				

			}//else if rectangle

		//---------------------- 4- Wrong values in choise ------------------------------\\

			else 	System.out.println("Pleas enter the a correct value \n1. Square\n2. Rectangle \n-1. to exit ");

		} while(true);// The user will keep trying anles he enters a right value.


	}//main



//******************************** Method that checks is a string is Possitive number *********************************\\

	public static boolean isPossitiveNumber(String temp){

		for(int i=0;i<(temp.length());i++){
			if(Character.isDigit(temp.charAt(i))||temp.charAt(i)=='.') continue;
			else return false;
		}//for

		return true;
  
	}//isNumber

//*************************************************************************************************************\\


}//AreaCalculator

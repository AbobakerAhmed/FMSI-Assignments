// Date: 7th of Oct 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:   ....
// D:    CS


/*		
	Assignmet of Lab 6: A Java Program to Print the Multiplication Table of a Number Entered By User	
*/

import java.util.*;

public class Multiplication{

	public static void main(String [] args){

		Scanner input = new Scanner(System.in);
		
		// get the number from the user
		System.out.print("You need the Multiplication Table of: ");
		byte n = (byte) input.nextInt();
		
		for(int i = 1 ; i <= 10 ; i++ ){
			System.out.println( n + " x " + i + " = " + n * i);
		} //for
		
	} //main

} //Multiplication

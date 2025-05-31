
//Name: Abobaker Ahmed Khidir Hassan                       // I coudn't download any IDE, So I'm using the cmd for this assignemt 
//ID:    ....
//D:     CS



					//		Ex2	: A Programe to calculate the cost of the package		//
	


import java.util.*;


public class Ex2{

	public static void main(String[] args){

		Scanner input= new Scanner(System.in);
		
		//Ask the user to enter the weight of the package.
		System.out.print("Enter the weight of the package in pounds: ");
		double weight=input.nextDouble();

		//the weight must be greater than 0.
		if (weight<0) System.out.println("Pleas enter the real weight of the pacage");
	
		//This is the assigment cases.
		else if(weight <=2)System.out.println("It cost only "+2.5+"$.");

		else if (weight <= 4) System.out.println("It cost only "+4.5+"$.");	

		else if (weight <= 10) System.out.println("It cost only "+7.5+"$.");

		else if (weight <=20 ) System.out.println("It cost only "+10.5+"$.");

		else  System.out.println("The package cannot be shipped");
				

	}



}
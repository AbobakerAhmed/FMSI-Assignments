// Name: Abobaker Ahmed Khidir Hassan                       // I coudn't download any IDE, So I'm using the cmd for this assignemt 
//ID:    ....
//D:     CS


					//		Ex1: A Programe to calculate the tax		//
	


import java.util.*;


public class Ex1{

	public static void main(String[] args){

		Scanner input= new Scanner(System.in);

		double income;


		//Ask the user to enter his\her income:
		System.out.print("Enter Your Income: ");	
		income= input.nextDouble();

		//if the income is less than 30,000 we don't have to get the number of children and the tax is: 0.1*income.
 		
		if (income<30_000){
			System.out.println("Your income is less than 30,000 so:"); 
			System.out.println("Your tax is:"+0.1*income+", Your net salary is: "+(income-(0.1*income)));}

		
		else{
			
			// If the last condition isn't true then the income certainly is more than or equal 30,000.
			// Then we have jast to classify them by the number of children they have.
			// I will not use the switch statement becuase there is to much cases 0,1,2... I will use the ranges {(-inf,0),[0,3),[3,inf)}
			
			byte children;    // I think no one will have more than 127 children  :) .
		

			//Ask the user to enter the number of children:
			System.out.print("How many children do you have? ");
			children=(byte)input.nextByte();

	
			// children can't be less than 0.
			if(children<0)   
				System.out.println("They died or what?! \nPleas try again to enter the real number of children. ");
	
	

			// if he has 3 children or more the tax will be 20% else that mean he has less than 3 children and the tax will be 30%
			else{ 
			 
				System.out.println("Your income is 30,000 or more and you have "+ children+" children so");
				System.out.println(
				"Your tax is: "+ ((children>=3) ? (0.2*income) :( 0.3*income)) 
				+ ", Your net salary is: "+( (children>=3) ? (income-0.2*income) : (income-0.3*income)));
	
			}


	
		}

	

	}



}
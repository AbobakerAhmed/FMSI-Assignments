// Name: Abobaker Ahmed Khidir Hassan.
//ID:    ....
//D:     Computer Sciences

import java.util.*;
 
public class Ex4{

	
	
	public static void main(String args[]){

	Scanner input = new Scanner(System.in);
	int num_people=0;
	int num_Pizzas=0;

	System.out.print("How many people? ");
	num_people= input.nextInt();
	System.out.print("How many pizzas do you have? ");
	num_Pizzas=input.nextInt();	
	

	System.out.println("Each person gets "+ 8*num_Pizzas/num_people +" pieces of pizza.");
	System.out.println("There are "+ (8*num_Pizzas)%num_people +" leftover pieces.");


	}


}
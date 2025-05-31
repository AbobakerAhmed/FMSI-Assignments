//Name: Abobaker Ahmed Khidir Hassan                        
//ID:    ....
//D:     CS



					//		Ex4	: A Programe to calculate the Discriminent of the quadratic equation			//
	


import java.util.*;



public class Ex4{

	public static void main(String[] args){

		Scanner input= new Scanner(System.in);
		

		double discriminent,r1,r2;
		double a,b,c;

		
		//Ask the user to enter a,b,c
		System.out.println("The quadratic equation in this formula: a(x*x) + b(x) +c .");
		System.out.print("Enter your a, b, c in order: ");				
		a=input.nextDouble();b=input.nextDouble();c=input.nextDouble();  //I used (,) to enter a double

		//calculate the discriminent
		discriminent = Math.pow(b,2) -4*a*c;
		

		/**
			1- if it is a positive then the equation has 2 real roods
			2- else if it equal 0 then the equation has onle one real rood
			3- else it will be a negative then the equation has no any real rood
		*/ 


		//1-
		if (discriminent>0){
			
			//this is the roods equations.
			r1= (double) (-b + (Math.pow(discriminent, 0.5))) / 2*a;
			r2= (double) (-b - (Math.pow(discriminent, 0.5))) / 2*a;
			
			//Printting the real roods.
			System.out.println("This equation has two real roods:");
			System.out.print("r1 = "+r1+", and r2 = "+ r2);
			}


		//2-
		else if (discriminent==0){
			r1= (double) (-b + (Math.pow(discriminent, 0.5))) / 2*a;
			System.out.println("This equation has only one real roods:\nr1 = "+r1+".");
 		}


		//3- discriminent < 0
		else 
			System.out.println("This equation has no real roods.");

	}



}
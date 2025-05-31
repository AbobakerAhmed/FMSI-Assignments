
// Name: Abobaker Ahmed Khidir Hassan                       
//ID:    ....
//D:     CS



					//	Ex3	: An aplication to read the Watts of a standard light bulb 		//
	


import java.util.*;


public class Ex3{

	public static void main(String[] args){

		Scanner input= new Scanner(System.in);
		

		double watts; //I don't know the watts has (.) or not so I will use the double data type

		
		
		watts= input.nextDouble();  // This app reads the watts from a bulb so it doesn't need to ask the user.

		short lumens;     

		switch((int)watts){
		
			case 15: lumens=125; break;
			
			case 25: lumens=215; break;

			case 40: lumens=500; break;

			case 60: lumens=880; break;

			case 75: lumens=1000; break;

			case 100: lumens=1675; break;

			default: lumens=-1;
		}
		
		
		if(lumens==-1)  // The watts is not in the table
			System.out.println(lumens);
		else
			System.out.println("The expected brightness of the bulb is "+lumens+".");


		
		//we can also use the printting statement on the switch then we will low the memory using.
				

	}



}
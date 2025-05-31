//Name: Abobaker Ahmed Khidir Hassan.
//D: 	Computer Science.
//ID:	....



		//	Ex2: Java program That Simulates a Simple User Authentication System	  //




import java.util.*;

public class Exercise2{

	public static void main(String[] args){

	
		Scanner input = new Scanner(System.in);
		
		String password; //The password of the user in the system.
		

		


		int i=0;//while condition. and it represent the number of tries.

		do{
			
			//Ask the user to enter the username;
			System.out.print("\nEnter the Username: ");
			String username=input.nextLine();
			username=username.trim();// spaces in the username ofthen are typing errors 
			

			//Check is his\her username in the data base?
			if(username.equals("m0hammed")) 
				password="mohammed12";
			
			else if(username.equals("amnah")) 
				password="Amnah77";
			
			else if(username.equals("admin"))
				password="password123";

			else{
				System.out.println("This username is not found!\n");
				password="\0";
				i++;
				continue;}			
					

			//Ask the user to enter the password after finding his username.
			System.out.print("Enter the Password: ");
			String enterdPassword=input.nextLine();
			
			//check is the password is correct?
			boolean isCorrect=password.equals(enterdPassword);


			if(isCorrect){
				System.out.printf("Welcome %s!.\n",username.toUpperCase());
				break;}
			else if(i>=5){
				System.out.printf("Invaliod password, pleas be carefule you have only %d chances\n",i);
				i++;}
			
			else
				System.out.println("Invaliod password, pleas try again.");
				i++;
				
		}while(i<7); //The user has 7 chances to enter the correct username and its password.	
		


	}//main

}//class

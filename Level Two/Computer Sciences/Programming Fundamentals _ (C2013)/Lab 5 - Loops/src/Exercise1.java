//Name: Abobaker Ahmed Khidir Hassan.
//D: 	Computer Science.
//ID:	....



		//	Ex1: An Application That Evaluates The Factorials of the Integers from 1 to 5.	  //


/**
What difficulty might prevent you from
calculating the factorial of 20?

Nothing, I have just to make the xFactorial as long.
*/	


public class Exercise1{

	public static void main(String[] args){
	
		//5! is less than the byte range (127).
		byte xFactorial =1;

		//colomens: and we have just 2 colomens ( x and x! )
		System.out.print("   x    x!");
		System.out.println("\n   ----------");

	
		//rows and the factorial:
		//if you wanna to calculate the factorial of any positive value say n, just replace 5 by (n).
		for(int x=1;x<=5;x++){
			System.out.printf("   %d |  ",x);  //rows.
			

			//That next loop isn't useful because we have just 2 colomons such x and x! and it will work one time anyway.
			for(int j=1;j<=1;j++){ 
				xFactorial*=x; //calculate the x factorial
				System.out.println(xFactorial);
			}//en.loop

		}//ex.loop

	}//main

}//class

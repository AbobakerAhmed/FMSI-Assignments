//	Abobaker Ahmed Khidir Hassan
//	....
//	CS
//	Ass of Lab 7&8 ( Ex 1 )


// Debugging Problem Chapter 7: Sales2.java
// Program totals sales for salespeople and products.

/*
	This file has 6 compilation errors and 4 logical errors
	Compalation errors will be counted as 1-, 2- ... above the line
	Logical errors will be declared in the end of the line as // LE:...
*/


import java.util.Scanner;

public class Sales2
{
	public void calculateSales()
	{
		Scanner input = new Scanner( System.in );
		// sales array holds data on number of each product sold
		// by each salesman

		// 1- declare an array 2D " [][] " and create it.
		double [][] sales = new double[ 5 ][ 4 ];

		int person = 0;


		// LE: We have to ask the user about the sales person each time.
		while ( person != -1 )
		{


			//These two statements shuld be inside the loop
			System.out.print( "Enter sales person number (-1 to end): " );
			person = input.nextInt();



			if(person != -1)  // LE: All of the next questions should be asked if and only if the user doen't input -1.
			{
				System.out.print( "Enter product number: " );

				// 2- "input.next()" get string and the int data type can not get it so we have to use nextInt() or change the data type to string.
				int product = input.nextInt();

				System.out.print( "Enter sales amount: " );
				double amount = input.nextDouble();


				// error-check the input

			
				// 3- if statement can not be hapened becase "person" can not be less than 1 and greater than 5 in the same time!
				if ( person >= 1 && person < 5 && product >= 1 && product < 6 && amount >= 0 )
					sales[ product - 1 ][ person - 1 ] += amount;

				else
				{
					System.out.print( "Enter sales person number (-1 to end): " );
					person = input.nextInt();
				}// en else

			}//ex if

		} // end while


		// total for each salesperson

		//4- declare an array 2D and create 1D array! 
		double salesPersonTotal[] = new double[ 4 ];

		// display the table
		for ( int column = 0; column < 4; column++ )
			
		// 5- To get the total of a 2D array we must make a nested loop.
		{ // start columns for

			for (int row = 0 ; row < 5 ; row++ )
				salesPersonTotal[ column ] = sales[row][column]; // The old LE: "= 0" .
		
		} //end columns for
			System.out.printf( "%7s%14s%14s%14s%14s%10s\n",
			"Product", "Salesperson 1", "Salesperson 2",
			"Salesperson 3", "Salesperson 4", "Total" );


		// for each column of each row, print the appropriate
		// value representing a person's sales of a product
		for ( int row = 0; row < 5; row++ )
		{
			double productTotal = 0.0;
			System.out.printf( "%7d", ( row + 1 ) );

			for ( int column = 0; column < 4; column++ ) {
				System.out.printf( "%14.2f", sales[ row ][ column ] ); // The old LE: sales[ column ][ row ]
				productTotal += sales[row][ column ]; // The old LE: sales[ column ][ row ]

				// 6- salesPersonTotal is a 2D array.
				salesPersonTotal[ column ] += sales[ row ][ column ];

			} // end for

			System.out.printf( "%10.2f\n", productTotal );
		} // end for

		System.out.printf( "%7s", "Total" );

		for ( int column = 0; column < 4; column++ )
			System.out.printf( "%14.2f", salesPersonTotal[ column ] );

		System.out.println();
	} // end method calculateSales


} // end class Sales2
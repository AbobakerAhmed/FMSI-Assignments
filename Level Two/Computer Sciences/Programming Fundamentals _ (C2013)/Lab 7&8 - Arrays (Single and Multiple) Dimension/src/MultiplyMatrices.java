// Abobaker Ahmed Khidir Hassan
// ....
// CS


	//	Program that calculates and displays the multiplycation of two matrices 3X3	\\ 




import java.util.*;

public class MultiplyMatrices{


	public static void main(String [] args){

		//declare and create two 3X3 matrices.
		double [][] matrix1 = new double [3][3]; 	//{{1,2,3},{4,5,6},{7,8,9}};new double [3][3];
		double [][] matrix2 = new double [3][3];	//{{0,2,4},{1,4.3,2.2},{1.1,4.3,5.2}};

		//Get matrix1 from the user
		System.out.print("Enter matrix1: ");
		enterMatrix(matrix1);

		//Get matrix2 from the user
		System.out.print("Enter matrix2: ");
		enterMatrix(matrix2);

		
		//Print matrix1 * matrix2 = thier product.
		System.out.println("The maltiplication of matrices is");
		displayMultiplication(matrix1,matrix2,multiplyMatrix(matrix1,matrix2));
				

		
	}// end main



	public static double[][]
	multiplyMatrix(double[][] a, double[][] b) {

		double [][] c = new double [3][3]; //The result
		
		for(int row = 0; row < 3; row++){

			for(int column = 0; column < 3; column++ ){

				//calculate any element and store it in its place in c			
				c[row][column] = a[row][0] * b[0][column] + a[row][1] * b[1][column] + a[row][2] * b[2][column]; 

			}// end colmns for

		}// end rows for


		return c;
	}// end method multiplyMatrix



	public static void enterMatrix(double [][] matrix){

		Scanner input = new Scanner(System.in);

		for(int row = 0; row < matrix.length; row++ ){

			for(int column = 0; column < matrix[row].length; column++ ){
				matrix[row][column] = input.nextDouble();	//entring the matrix
			}// end colmns for

		}//end rows for

	}// end method enterMatrix



	

	public static void displayMultiplication(double [][] matrix1,double [][] matrix2,double [][] result){

	//Print matrix1 and matrix2 and result line by line:
		for(int row =0; row < 3; row++){

			//Print matrix1
			for(int column =0; column < 3; column++){
				
				System.out.printf("%4.1f\t",matrix2[row][column]);			

			}//end for of matrix1 columns

			//If that was the second row print "*"
			if(row == 1)
				System.out.print("*\t");
			else 
				System.out.print(" \t");

			//Print matrix2
			for(int column =0; column < 3; column++){
				
				System.out.printf("%4.1f\t",matrix2[row][column]);			

			}//end for of matrix2 columns

			//If that was the second row print "="
			if(row == 1)
				System.out.print("=\t");
			else 
				System.out.print(" \t");
	
			//Print result
			for(int column =0; column < 3; column++){
				
				System.out.printf("%4.1f\t",result[row][column]);			

			}//end for of result columns
	
			
			System.out.println();			


		}// end for rows

	}// end method displayMultiplication



}// end class
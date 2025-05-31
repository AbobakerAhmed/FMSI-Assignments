//Name: Abobaker Ahmed Khidir Hassan
//ID:   ....
//D:    CS
//Date: 23rd of July 2024


/**
	Lab 9&10 assignment
	Exercise 1 :
	A program that tests the Triangle class
*/
	
//package testcirclerectangle;

import java.util.*;


public class Exercise1{

	public static void main(String [] args){
		Scanner input = new Scanner(System.in);
		
		// 1- Prompt the user to enter the triangle
		System.out.println("Enter 3 sides of your triangle please");
			//Side 1
		System.out.print("Side 1: "); double side1 = input.nextDouble();
			//Side 2
		System.out.print("Side 2: "); double side2 = input.nextDouble();
			//Side 3
		System.out.print("Side 3: "); double side3 = input.nextDouble();
			//Color
		System.out.print("Color: "); String color = input.next();
			//Is filled?
		System.out.print("Is it filled? (If yes enter T, else enter F): ");
		String temp = input.next(); Boolean isFilled = false;
		if(temp.equals("T") || temp.equals("t") || temp.equals("true")) isFilled = true;
		
		System.out.println();

		// 2- Create a Triangle object with these properties
		Triangle triangle1 = new Triangle( side1, side2, side3);	//Set sides.
		triangle1.setColor(color);	//Set the color.
		triangle1.setFilled(isFilled);	//Set is it filled or not.
		
		// 3- The program should display:
			//The area:
		System.out.println("The area: " + triangle1.getArea() + " unite square.");
			//The perimeter:
		System.out.println("The perimeter: " + triangle1.getPerimeter() + " unit."); 
			//color + is it filled or not:
		System.out.println("The color: " + triangle1.getColor() + ".\nIs it filled? " + triangle1.isFilled() + ".");

	}//main	

}//TestTriangle 

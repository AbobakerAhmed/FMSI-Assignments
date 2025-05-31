//Name: Abobaker Ahmed Khidir Hassan
//ID:   ....
//D:    CS
//Date: 23rd of July 2024


/**
	Lab 9&10 assignment
	Exercise 1 :
	The Triangle class that extends GeometricObject class
*/

//package testcirclerectangle;

// 1- Design a class named Triangle that extends GeometricObject. 
class Triangle extends GeometricObject{

	//■ Three double data fields with default values 1.0.
	private double side1 = 1;
	private double side2 = 1;
	private double side3 = 1;
	
	//■ A no-arg constructor that creates a default triangle.
	Triangle(){}

	//■ A constructor with specified three sides.
	Triangle(double side1, double side2, double side3){
		this.side1 = side1;
		this.side2 = side2;
		this.side3 = side3;
	}//constructor

	
	//■ The accessor methods for all three data fields.
		//Seters:
	public void setSide1(double side1){ this.side1 = side1; }//setSide1
	public void setSide2(double side2){ this.side2 = side2; }//setSide2
	public void setSide3(double side3){ this.side3 = side3; }//setSide3
		//Geters:
	public double getSide1(){ return this.side1; }//getSide1
	public double getSide2(){ return this.side2; }//getSide2
	public double getSide3(){ return this.side3; }//getSide3

	//■ A method named getArea() that returns the area of this triangle. 
	public double getArea(){
		double s = (side1 + side2 + side3)/2;
		return Math.pow((s * (s - side1) * (s - side2) * (s - side3)),0.5);
	}//getArea


	//■ A method named getPerimeter() that returns the perimeter of this triangle. 
	public double getPerimeter(){
		return ( side1 + side2 + side3 );
	}//getPerimeter


	//■ A method named toString() that returns a string description for the triangle.
	@Override
	public String toString(){
		return "Triangle: side1 = " + side1 + " side2 = " + side2 + " side3 = " + side3;
	}//toString
 
}//Triangle 
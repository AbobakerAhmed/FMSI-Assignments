// Date: 7th of Oct 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:   ....
// D:    CS

/*		
	Assignmet of Lab 5: A Java Program That Classifies the Weather Based on Temperature	
*/

import java.util.*;

public class Weather{

	public static void main(String [] args){
		
		Scanner input = new Scanner(System.in);	

		System.out.print("Enter the temperature please: ");
		double temperature = input.nextDouble();

		String weather;

		//1: If the temperature is 30°C or higher, the weather is "Hot".
		if(temperature >= 30) weather = "Hot";

		//2: If the temperature is between 20°C and 29°C, the weather is "Warm".
		else if(temperature >= 20) weather = "Warm";		

		//3: If the temperature is between 10°C and 19°C, the weather is "Cool".
		else if(temperature >= 10) weather = "Cool";		

		//4: If the temperature is between 0°C and 9°C, the weather is "Cold".
		else if(temperature >= 0) weather = "Cold";		

		//5: If the temperature is below 0°C, the weather is "Freezing".
		else weather = "Freezing";	

		System.out.println("The weather is " + weather + ".");	// Print the result.
	} //main

} //Weather
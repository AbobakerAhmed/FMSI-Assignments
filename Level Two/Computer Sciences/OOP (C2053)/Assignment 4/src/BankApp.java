// Date: 24th of Sep 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:   ....
// D:    CS

/** 
		Assignment 1 of Lab 4
	3- Define 3 Objects type BankAccount
	4- Use credit and depit with each of these accounts.
	5- Print details of each account (account num. , holder name , balance).

*/


//package bankapp;

//import BankAccount.*;

public class BankApp {
    public static void main(String[] args) {
        BankAccount account1 = new BankAccount("Ali Ahmed", 0);
        account1.printInfo();
        account1.credit(1000);
        account1.printInfo();
        account1.depit(300);
        System.out.println(" After debit ");
        //account1.accountHolderName = "Ali Mohammed";
        account1.setAccountHolderName("Ali Mohammed");
        account1.printInfo();
        
        String name = account1.getAccountHolderName();
         System.out.println("name : "+name);
         System.out.println("name : "+account1.getAccountHolderName());

		System.out.println("\n\nOutput of Assignment 1:");

// 	3- Define 3 Objects type BankAccount
		BankAccount account2 = new BankAccount("Adil Salah",5000);
		BankAccount account3 = new BankAccount("Khalid Rashed",15000);
		BankAccount account4 = new BankAccount("Omnia Mazin",34000);

		// Before any edite
		System.out.println("Before any credit or depit:");
		account2.printInfo();
		account3.printInfo();
		account4.printInfo();

//	4- Use credit and depit with each of these accounts.
		account2.credit(200);
		account2.depit(3000);

		account3.credit(2000);
		account3.depit(7500);

		account4.credit(3400);
		account4.depit(50000);


//	5- Print details of each account (account num. , holder name , balance).
		System.out.println("\nAfter credit and depit:");
		account2.printInfo();
		account3.printInfo();
		account4.printInfo();

		System.out.println("\nUsing methods:");
		System.out.println("Account 2:\nHolder Name: " + account2.getAccountHolderName() + "\nBalance: " + account2.getBalance());
		System.out.println();
		System.out.println("Account 3:\nHolder Name: " + account3.getAccountHolderName() + "\nBalance: " + account3.getBalance());
		System.out.println();
		System.out.println("Account 4:\nHolder Name: " + account4.getAccountHolderName() + "\nBalance: " + account4.getBalance());


	} // main
    
} // BankApp

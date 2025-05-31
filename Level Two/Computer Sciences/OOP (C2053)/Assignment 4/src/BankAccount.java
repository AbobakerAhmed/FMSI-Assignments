// Date: 24th of Sep 2024
// Name: Abobaker Ahmed Khidir Hassan
// ID:   ....
// D:    CS

/** 
		Assignment 1 of Lab 4
	1- Change the balance to private
	2- Create two methods to get and set the balance
	3- Define 3 Objects type BankAccount
	4- Use credit and depit with each of these accounts.
	5- Print details of each account (account num. , holder name , balance).

*/

//package bankapp;

public class BankAccount {
    private String accountHolderName;


// 1- Change the balance to private
    private double balance;				
    
    BankAccount(String name, double b){
        accountHolderName = name;
        balance = b;
    }
    
    BankAccount(){
        
    }
    
    public void credit(double ammount){
        balance = balance + ammount;
    }
    
// Adding if cond.
    public void depit(double ammount){
	if(balance >= ammount)
		balance = balance - ammount;
	else
		System.out.println(this.accountHolderName + ", Your balance is not enugh to depit " + ammount + " SDN!");
    }

// Adding a new line after the neme and balancd
    public void printInfo(){
        System.out.println("Account Holder Name : "+ accountHolderName + "\nbalance : "+ balance +" SDN\n");
    }
    
    public void setAccountHolderName(String newName){
        accountHolderName = newName;
    }
    
    public String getAccountHolderName(){
        return accountHolderName;
    }



// 2- Create two methods to get and set the balance

	public void setBalance(double amount){
		this.balance += amount;	
	} // setBalance

	public double getBalance(){
		return this.balance;
	} // getBalance

}


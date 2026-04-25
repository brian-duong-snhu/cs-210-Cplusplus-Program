//Date: 4/5/2026
//Author: Brian Duong
//Purpose: Create an application that accepts user's input for investments and outputs amounts based on the user's inputs

// include iostream is needed for input and output
#include <iostream>
// include iomanip is needed for manipulating input and output format
#include <iomanip>
// using namespace std is needed for cout without having to use std::cout
using namespace std;

// include header files to use from the files
#include "InvestmentDataCalculations.h"
#include "UserInputCalculations.h"

void mainInterface() {
	// create an instance of InvestmentDataCalculations
	InvestmentDataCalculations investmentDataCalculations;

	// create an instance of UserInputCalculations
	UserInputCalculations userInputCalculations;

	// initialize input variables
	double initialAmount;
	double monthlyDeposit;
	double annualInterest;
	int yearsInvested;
	string keepLooping;

	// initialize boolean to continue looping for different inputs for new calculations
	bool continueLooping = true;

	// do while loop to accept user inputs for calculations. keep looping while continueLooping is true
	do {
		// clear the console screen at the beginning of the loop
		system("cls");

		// output header for user input. use built-in functions from iomanip. need to use single quotes for setfill
		cout << setfill('*') << setw(35) << "*" << endl;
		cout << "*\t" << "Data Input" << "\t *" << endl;
		cout << setfill('*') << endl;

		// ask user to input initial investment amount
		cout << "Initial Investment Amount: $";
		cin >> initialAmount;
		cout << endl;

		// ask user to input monthly deposit amount
		cout << "Monthly deposit: $";
		cin >> monthlyDeposit;
		cout << endl;

		// ask user to input annual interest percentage
		cout << "Annual Interest: %";
		cin >> annualInterest;
		cout << endl;

		// ask user to put number of years investing
		cout << "Number of years: ";
		cin >> yearsInvested;
		cout << endl;

		// set amounts for calculation as the user's inputs
		investmentDataCalculations.setInitialInvestment(initialAmount);
		investmentDataCalculations.setMonthlyDeposit(monthlyDeposit);
		investmentDataCalculations.setAnnualInterest(annualInterest);
		investmentDataCalculations.setNumberOfYears(yearsInvested);

		// format the amounts in table form. use built-in functions from iomanip. need to use single quotes for setfill
		cout << "Initial Investment Amount: " << setfill(' ') << right << setw(10) << "$" << fixed << setprecision(2) << investmentDataCalculations.getInitialInvestment() << endl;
		cout << "Monthly Deposit: " << setfill(' ') << right << setw(20) << "$" << fixed << setprecision(2) << investmentDataCalculations.getMonthlyDeposit() << endl;
		cout << "Annual Interest: " << setfill(' ') << right << setw(20) << " " << investmentDataCalculations.getAnnualInterest() << "%" << endl;
		cout << "Number of years: " << setfill(' ') << right << setw(20) << " " << investmentDataCalculations.getNumberOfYears() << endl;
		cout << endl;

		// wait for user input
		system("pause");

		// call userInputCalculations.dataWithoutDeposits(investmentDataCalculations);
		// use try catch for run-time error handling
		try {
			userInputCalculations.dataWithoutDeposits(investmentDataCalculations);
		}
		catch (const exception& e) {
			// output an error message
			cout << "An error has occurred:" << endl;

			// output error message
			cout << e.what() << endl;

			// pause and wait for user to press a key
			system("pause");
		}

		// call userInputCalculations.dataWithDeposits(investmentDataCalculations);
		// use try catch for run-time error handling
		try {
			userInputCalculations.dataWithDeposits(investmentDataCalculations);
		}
		catch (const exception& e) {
			// output an error message
			cout << "An error has occurred:" << endl;

			// output error message
			cout << e.what() << endl;

			// pause and wait for user to press a key
			system("pause");
		}

		cout << endl;

		// ask user if they want to calculate with different inputs
		cout << "Do you want to calculate investment with different values? Enter y or n" << endl;
		cin >> keepLooping;

		// if user input is n or N, set continueLooping to false to stop looping
		if (keepLooping == "n") {
			continueLooping = false;
		}

		// otherwise, set continueLooping to true
		else {
			continueLooping = true;
		}

	} while (continueLooping == true);
}

int main() {
	// call mainInterface
	// use try catch for run-time error handling
	try {
		mainInterface();
	}
	catch (const exception& e) {
		// output an error message
		cout << "An error has occurred:" << endl;

		// output error message
		cout << e.what() << endl;

		// pause and wait for user to press a key
		system("pause");
	}

	// best practice to return 0 if there's no vlaue to be returned
	return 0;
}
//Date: 4/5/2026
//Author: Brian Duong
//Purpose: Create an application that accepts user's input for investments and outputs amounts based on the user's inputs

// include iostream is needed for input and output
#include <iostream>
// include iomanip is needed for manipulating input and output format
#include <iomanip>
// using namespace std is needed for cout without having to use std::cout
using namespace std;

//include UserInputCalculations.h to use from the file
#include "UserInputCalculations.h"

// display without monthly deposits first
void UserInputCalculations::dataWithoutDeposits(InvestmentDataCalculations t_userInvestment) {
	// initialize variables for user input
	double initialInvestment = t_userInvestment.getInitialInvestment();
	int years = t_userInvestment.getNumberOfYears();

	// initialize variables for aligning output message
	string balanceMessage = "Balance and Interest Without Additional Monthly Deposits";
	int screenWidth = 90;
	int halfWidth = screenWidth / 2;
	int center = balanceMessage.length() / 2;
	int distanceToCenter = halfWidth + center;

	// line break
	cout << endl;

	// output header. use built-in functions from iomanip. need to use single quotes for setfill
	cout << setfill(' ') << setw(center) << balanceMessage << setfill(' ') << setw(distanceToCenter) << endl;
	cout << setfill('=') << setw(screenWidth) << " = " << endl;
	cout << setfill(' ') << left << setw(25) << "Year" << "Year End Earned Interest" << right << setw(30) << "Year End Balance" << endl;
	cout << setfill('-') << setw(screenWidth) << " - " << endl;

	// add initial amount to total amount
	t_userInvestment.setTotalWithoutDeposits(initialInvestment);
	double interestYearToDate = 0;

	// initialize variables for yearCount and monthcount
	int yearCount, monthCount;

	// loop to calculate amounts
	for (yearCount = 1; yearCount <= years; yearCount++) {
		for (monthCount = 1; monthCount <= 12; monthCount++) {
			// add to total amount with interest rate
			interestYearToDate += t_userInvestment.calculateInterestWithoutDeposits();
		}

		// add yearly total interest to total amount
		t_userInvestment.setTotalWithoutDeposits(interestYearToDate);

		// format the amounts in table form
		cout << setfill(' ') << left << setw(30) << yearCount;
		cout << "$" << fixed << setprecision(2) << interestYearToDate;
		cout << right << setw(35) << "$" << fixed << setprecision(2) << t_userInvestment.getTotalWithoutDeposits() << endl;

		// reset interest YearToDate after outputting amounts
		interestYearToDate = 0;
	}
}

// display with monthly deposits second
void UserInputCalculations::dataWithDeposits(InvestmentDataCalculations t_userInvestment) {
	// initialize variables for user input
	double initialInvestment = t_userInvestment.getInitialInvestment();
	double monthlyDeposit = t_userInvestment.getMonthlyDeposit();
	int years = t_userInvestment.getNumberOfYears();

	// initialize variables for aligning output message
	string balanceMessage = "Balance and Interest With Additional Monthly Deposits";
	int screenWidth = 90;
	int halfWidth = screenWidth / 2;
	int center = balanceMessage.length() / 2;
	int distanceToCenter = halfWidth + center;

	// line break
	cout << endl;

	// output header. use built-in functions from iomanip
	cout << setfill(' ') << setw(center) << balanceMessage << setfill(' ') << setw(distanceToCenter) << endl;
	cout << setfill('=') << setw(screenWidth) << " = " << endl;
	cout << setfill(' ') << left << setw(25) << "Year" << "Year End Earned Interest" << right << setw(30) << "Year End Balance" << endl;
	cout << setfill('-') << setw(screenWidth) << " - " << endl;

	// add initial amount to total amount
	t_userInvestment.setTotalWithDeposits(initialInvestment);
	double interestYearToDate = 0;

	// initialize variables for yearCount and monthcount
	int yearCount, monthCount;

	// loop to calculate amounts
	for (yearCount = 1; yearCount <= years; yearCount++) {
		for (monthCount = 1; monthCount <= 12; monthCount++) {
			// add monthly deposit to total amount
			t_userInvestment.setTotalWithDeposits(monthlyDeposit);

			// initlaize variable for interest
			double interest = t_userInvestment.calculateInterestWithDeposits();

			// add updated yearly amount with interest to total amount
			t_userInvestment.setTotalWithDeposits(interest);
			interestYearToDate += interest;
		}

		// format the amounts in table form
		cout << setfill(' ') << left << setw(30) << yearCount;
		cout << "$" << fixed << setw(40) << setprecision(2) << interestYearToDate;
		cout << left << "$" << fixed << setprecision(2) << t_userInvestment.getTotalWithDeposits() << endl;

		// reset interest YearToDate after outputting amounts
		interestYearToDate = 0;
	}
}
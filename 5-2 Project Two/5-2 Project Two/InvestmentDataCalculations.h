//Date: 4/5/2026
//Author: Brian Duong
//Purpose: Create an application that accepts user's input for investments and outputs amounts based on the user's inputs

#pragma once

// create class for InvestmentDataCalculations
class InvestmentDataCalculations {
// initialize private variables
private:
	double m_initialInvestment = 0.0;
	double m_monthlyDeposit = 0.0;
	double m_annualInterest = 0;
	int m_numberOfYears = 0;
	double m_totalWithDeposits = 0.0;
	double m_totalWithoutDeposits = 0.0;

// set classes as public for access
public:
	// setters
	void setInitialInvestment(
		double t_initialInvestment
	);

	void setMonthlyDeposit(
		double t_monthlyDeposit
	);

	void setAnnualInterest(
		double t_annualInterest
	);

	void setNumberOfYears(
		int t_years
	);

	void setTotalWithDeposits(
		double t_amount
	);

	void setTotalWithoutDeposits(
		double t_amount
	);

	// getters
	double getInitialInvestment() {
		return m_initialInvestment;
	};

	double getMonthlyDeposit() {
		return m_monthlyDeposit;
	};

	double getAnnualInterest() {
		return m_annualInterest;
	};

	int getNumberOfYears() {
		return m_numberOfYears;
	};

	double getTotalWithDeposits();
	double getTotalWithoutDeposits();

	// calculations with and without deposits
	double calculateInterestWithDeposits();
	double calculateInterestWithoutDeposits();
};
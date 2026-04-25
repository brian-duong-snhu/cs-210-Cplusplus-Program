//Date: 4/5/2026
//Author: Brian Duong
//Purpose: Create an application that accepts user's input for investments and outputs amounts based on the user's inputs

// include InvestmentDataCalculations.h to use from the file
#include "InvestmentDataCalculations.h"

// set initial investment
void InvestmentDataCalculations::setInitialInvestment(double t_initialInvestment) {
	this->m_initialInvestment = t_initialInvestment;
}

// set monthly deposit
void InvestmentDataCalculations::setMonthlyDeposit(double t_monthlyDeposit) {
	this->m_monthlyDeposit = t_monthlyDeposit;
}

// set annual interest
void InvestmentDataCalculations::setAnnualInterest(double t_annualInterest) {
	this->m_annualInterest = t_annualInterest;
}

// set number of years to invest
void InvestmentDataCalculations::setNumberOfYears(int t_numberOfYears) {
	this->m_numberOfYears = t_numberOfYears;
}

// set total without deposits
void InvestmentDataCalculations::setTotalWithoutDeposits(double t_amount) {
	this->m_totalWithoutDeposits += t_amount;
}

// set total with deposits
void InvestmentDataCalculations::setTotalWithDeposits(double t_amount) {
	this->m_totalWithDeposits += t_amount;
}

// calculate interest without deposits
double InvestmentDataCalculations::calculateInterestWithoutDeposits() {
	return ((this->m_totalWithoutDeposits) * ((this->m_annualInterest / 100) / 12));
}

// calculate interest with deposits
double InvestmentDataCalculations::calculateInterestWithDeposits() {
	return ((this->m_totalWithDeposits) * ((this->m_annualInterest / 100) / 12));
}

// get total with deposits
double InvestmentDataCalculations::getTotalWithDeposits() {
	return this->m_totalWithDeposits;
}

// get total without deposits
double InvestmentDataCalculations::getTotalWithoutDeposits() {
	return this->m_totalWithoutDeposits;
}
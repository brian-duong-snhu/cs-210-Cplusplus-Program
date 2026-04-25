//Date: 4/5/2026
//Author: Brian Duong
//Purpose: Create an application that accepts user's input for investments and outputs amounts based on the user's inputs

#pragma once

// include InvestmentDataCalculations.h to use from the file
#include "InvestmentDataCalculations.h"

// create class to calculate user inputs
class UserInputCalculations {
	// set classes as public for access
public:
	void dataWithoutDeposits(InvestmentDataCalculations);
	void dataWithDeposits(InvestmentDataCalculations);
};
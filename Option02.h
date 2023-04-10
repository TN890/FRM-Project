#pragma once

namespace fre {
	//Input data
	int GetInputData(int& N, double& K);
	
	//pricing European option
	double* PriceByCRR(double S0, double U, double D, double R, unsigned int N, double K, double (*Payoff)(double z, double K));

	//computing call payoff
	double CallPayoff(double z, double K);
	
	//computing factorial
	double fact(int n);
	
	//computing put payoff
	double PutPayoff(double z, double K);
	
	//computing digital call payoff
	double DigitCallPayoff(double z, double K);
	
	//computing digital put payoff
	double DigitPutPayoff(double z, double K);
	
}
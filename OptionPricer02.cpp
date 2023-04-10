// OptionPricer01.cpp
//

#include "BinomialTreeModel.h"
#include "Option02.h"
#include <iostream>
#include <iomanip>
using namespace std;
using namespace fre;
    
int main()
{
    double S0 = 0.0, U = 0.0, D = 0.0, R = 0.0;
    if (GetInputData(S0, U, D, R) != 0)
    {    
        return -1;
    }
    double K = 0.0; //strike price
    int N = 0; //steps to expiry
    cout << "Enter call option data:" << endl;
    GetInputData(N, K);
    
    //double S0=106;
    //double U=1.15125;
    //double D=0.86862;
    //double R=1.00545;
    //int N=8;
    //double K=100;
    double* optionPrice = NULL;
    optionPrice = PriceByCRR(S0, U, D, R, N, K, CallPayoff);
    cout << "European Call option price = " << fixed << setprecision(2)<< optionPrice[0] << endl;
    delete [] optionPrice;
    optionPrice = PriceByCRR(S0, U, D, R, N, K, PutPayoff);
    cout << "European Put option price = " << fixed << setprecision(2)<< optionPrice[0] << endl;
    delete [] optionPrice;
    optionPrice = PriceByCRR(S0, U, D, R, N, K, DigitCallPayoff);
    cout << "European Digital Call option price = " << fixed << setprecision(2)<< optionPrice[0] << endl;
    delete [] optionPrice;
    optionPrice = PriceByCRR(S0, U, D, R, N, K, DigitPutPayoff);
    cout << "European Digital Put option price = " << fixed << setprecision(2)<< optionPrice[0] << endl;
    delete [] optionPrice;
    optionPrice = NULL;
    return 0;
}
/*
European call option price = 21.68
*/
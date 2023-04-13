#include "BinomialTreeModel.h"
#include "Option.h"
#include <iostream>
#include <iomanip>
using namespace std;
using namespace fre;
int main()
{ 
    int N = 8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double S0 = 106.00, K = 100.00;
    BinomialTreeModel Model(S0, U, D, R);
    Call call(N, K);
    OptionCalculation callCalculation(&call);
    cout << "European call option price = "<< fixed << setprecision(3) << callCalculation.PriceByCRR(Model) << endl;
    Put put(N, K);
    OptionCalculation putCalculation(&put);
    cout << "European put option price = "<< fixed << setprecision(3) << putCalculation.PriceByCRR(Model) << endl;
    BinLattice<double> CallPriceTree(N);
    BinLattice<bool> CallStoppingTree(N);
    cout << "American call option price = “ << fixed << setprecision(3)"<<callCalculation.PriceBySnell(Model, CallPriceTree, CallStoppingTree) << endl;
    cout << "American call price tree:" << endl << endl;
    CallPriceTree.Display();
    cout << "American call exercise policy:" << endl << endl;
    CallStoppingTree.Display();
    BinLattice<double> PutPriceTree(N);
    BinLattice<bool> PutStoppingTree(N);
    cout << "American put option price = " << fixed << setprecision(3)<<putCalculation.PriceBySnell(Model, PutPriceTree, PutStoppingTree) << endl;
    cout << "American put price tree:" << endl << endl;
    PutPriceTree.Display();
    cout << "American put exercise policy:" << endl << endl;
    PutStoppingTree.Display();
    return 0;
}

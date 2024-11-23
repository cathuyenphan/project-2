#include <iostream>
#include <vector>
#include "search.h"

using namespace std;

int main()  {

    int features = 0;
    int algorithm = 0;

    cout << "Welcome to Cat Phan's Feature Selection Algorithm" << endl;
    cout << endl << "Please select the total number of features: ";
    
    cin >> features;
    cout << endl;
    
    cout << "Type the number of the algorithm you want to run" << endl;
    cout << "[1] Forward Selection" << endl << "[2] Backward Elimination" << endl;

    cin >> algorithm;
    cout << endl;

    if(algorithm == 1)  {
        forwardSelection(features);
    }
    if(algorithm == 2)  {

        backwardElimination(features);
        
    }

}
#ifndef SEARCH_H_
#define SEARCH_H_

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

double evaluate(const vector<int>& featureSet)  {
    double accuracy = static_cast<double>(rand()%1000 + 1);
    accuracy = accuracy / 10.0;
    return accuracy;
}

void printFeatures(const vector<int> featureSet)  {

    for(int i = 0; i < featureSet.size(); i++)  {
        if(i != featureSet.size() - 1)  {
            cout << featureSet[i] << ",";
        }
        else {
            cout << featureSet[i] << "}";
        }
    }
    
}

void forwardSelection(int numFeatures)  {

    double bestAccuracy = 0.0;
    vector<int> bestFeatures;
    vector<int> current;

    for(int i = 1; i <= numFeatures; i++)   {

        double maxAccuracy = 0.0;
        int bestFeature = 0;

        for(int j = 1; j <= numFeatures; j++)   {
            if(count(current.begin(), current.end(), j) == 0)   {
                vector<int> temp = current;
                temp.insert(temp.begin(), j);

                double accuracy = evaluate(temp);
                cout << "\tUsing feature(s) {";
                printFeatures(temp);
                cout << " accuracy is " << accuracy << "%" << endl;

                if(accuracy > maxAccuracy)  {
                    maxAccuracy = accuracy;
                    bestFeature = j;
                }
            }
        }

        if(bestFeature != 0)    {
            
            if(i == numFeatures)    {
                if(bestAccuracy > maxAccuracy)   {
                    cout << endl << "(Warning, Accuracy decreased!)" << endl;
                    cout << "Finished Search!! The best feature subset is {";
                    printFeatures(bestFeatures);
                    cout << ", which has an accuracy of " << bestAccuracy << "%" << endl;
                }
                else    {
                    bestAccuracy = maxAccuracy;
                    bestFeatures = current;
                    cout << "Finished Search!! The best feature subset is {";
                    printFeatures(bestFeatures);
                    cout << ", which has an accuracy of " << bestAccuracy << "%" << endl;
                }
            }
            else    {

                current.insert(current.begin(), bestFeature);
                cout << endl << "Feature set {";
                printFeatures(current);
                cout << " was best, accuracy is " << maxAccuracy << "%" << endl;

                bestAccuracy = maxAccuracy;
                bestFeatures = current;
            }

            
        }
    }

}

#endif

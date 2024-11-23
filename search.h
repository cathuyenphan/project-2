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

vector<int> removeFeature(vector<int> featureSet, int num)  {

    vector<int> newVector;
    for(int i = 0; i < featureSet.size(); i++)  {
        if(featureSet[i] != num)    {
            newVector.push_back(featureSet[i]);
        }
    }

    return newVector;

}

void forwardSelection(int numFeatures)  {

    double bestAccuracy = 0.0;
    vector<int> bestFeatures;
    vector<int> current;

    cout << "Beginning Search." << endl;

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
                cout << endl;

                bestAccuracy = maxAccuracy;
                bestFeatures = current;
            }

            
        }
    }

}

void backwardElimination(int numFeatures)   {
    vector<int> current;
    vector<int> bestFeatures;
    double bestAccuracy = 0.0;
    
    for(int i = 1; i <= numFeatures; i++)   {
        current.push_back(i);
    }


    while(current.size() > 1)   {
        double maxAccuracy = 0.0;
        int worstFeature = 0; 
        int removeIndex = 0;

        for(int i = 1; i <= numFeatures; i++)   {
            vector<int> temp = current;
            if(count(current.begin(), current.end(), i) == 1)   {   // make sure the feature exists in subset
                temp = removeFeature(current, i);
                double accuracy = evaluate(temp);

                cout << "\tUsing feature(s) {"; 
                printFeatures(temp);
                cout << " accuracy is " << accuracy << "%" << endl;

                if(accuracy > maxAccuracy)  {
                    maxAccuracy = accuracy;                         // this subset yields highest accuracy so far
                    worstFeature = i;                               // the feature to be removed
                }
            }

        }

        if(worstFeature != 0)   {

            vector<int> tempCur = removeFeature(current, worstFeature);
            current = tempCur;
            bestAccuracy = maxAccuracy;
            bestFeatures.insert(bestFeatures.begin(), worstFeature);
        }

        cout << endl << "Feature set {";
        printFeatures(current);
        cout << " was best, accuracy is " << maxAccuracy << "%" << endl;
        cout << endl;
        
    }
    
    cout << "Finsihed search!! The best feature subset is {";
    printFeatures(bestFeatures); 
    cout << " which has an accuracy of " << bestAccuracy << "%" << endl;

}

#endif

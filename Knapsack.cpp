#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int knapSack(int W, const vector<int>& weights, const vector<int>& values, int items) {
    vector<vector<int>> table(items + 1, vector<int>(W + 1, 0));

    for (int i = 0; i <= items; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                table[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                table[i][w] = max(values[i - 1] + table[i - 1][w - weights[i - 1]], table[i - 1][w]);
            } else {
                table[i][w] = table[i - 1][w];
            }
        }
    }
    return table[items][W];
}

int main() {
    cout << "Enter values of items (space-separated): ";
    string valuesInput;
    getline(cin, valuesInput);
    istringstream valuesStream(valuesInput);
    vector<int> values;
    int value;
    while (valuesStream >> value) {
        values.push_back(value);
    }

    cout << "Enter weights of items (space-separated): ";
    string weightsInput;
    getline(cin, weightsInput);
    istringstream weightsStream(weightsInput);
    vector<int> weights;
    int weight;
    while (weightsStream >> weight) {
        weights.push_back(weight);
    }

    cout << "Enter Knapsack Capacity: ";
    int W;
    cin >> W;

    int n = values.size();
    int maxProfit = knapSack(W, weights, values, n);
    cout << "Maximum profit that can be achieved: " << maxProfit << endl;

    return 0;
}

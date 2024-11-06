#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Item {
public:
    double weight;
    double value;
    
    Item(double w, double v) : weight(w), value(v) {}
};

bool compare(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

double fractionalKnapsack(vector<double>& weights, vector<double>& values, double capacity) {
    if (weights.size() != values.size()) {
        throw invalid_argument("Weights and values must be of the same length.");
    }

    vector<Item> items;
    for (size_t i = 0; i < weights.size(); i++) {
        items.push_back(Item(weights[i], values[i]));
    }

    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0;

    for (const auto& item : items) {
        if (capacity <= 0) break;

        if (item.weight > capacity) {
            maxValue += capacity * (item.value / item.weight);
            capacity = 0;
        } else {
            maxValue += item.value;
            capacity -= item.weight;
        }
    }

    return maxValue;
}

int main() {
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<double> weights(numItems), values(numItems);

    cout << "Enter the weights (space-separated): ";
    for (int i = 0; i < numItems; i++) {
        cin >> weights[i];
    }

    cout << "Enter the values (space-separated): ";
    for (int i = 0; i < numItems; i++) {
        cin >> values[i];
    }

    double capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(weights, values, capacity);
    cout << fixed << setprecision(2) << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}

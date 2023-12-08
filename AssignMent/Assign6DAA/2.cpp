#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Function to calculate the maximum value using the Fractional Knapsack algorithm
pair<double, vector<double>>
fractional_knapsack(vector<int> weights,
                    vector<int> profits, int capacity, string strategy)
{
    int n = weights.size();
    vector<double> ratios(n);
    for (int i = 0; i < n; i++)
    {
        ratios[i] = (double)profits[i] / weights[i];
    }
    if (strategy == "largest_profit")
    {
        sort(ratios.begin(), ratios.end(), greater<double>());
    }
    else if (strategy == "smallest_weight")
    {
        sort(weights.begin(), weights.end());
    }
    else if (strategy == "largest_ratio")
    {
        sort(ratios.begin(), ratios.end(), greater<double>());
    }
    else
    {
        cout << "Invalid strategy" << endl;
        return make_pair(0, vector<double>());
    }
    double max_profit = 0;
    vector<double> selected_weights(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (weights[i] <= capacity)
        {
            selected_weights[i] = 1;
            max_profit += profits[i];
            capacity -= weights[i];
        }
        else
        {
            selected_weights[i] = (double)capacity / weights[i];
            max_profit += profits[i] * ((double)capacity / weights[i]);
            break;
        }
    }
    return make_pair(max_profit, selected_weights);
}
int main()
{
    // Input data
    vector<int> weights = {18, 15, 10};
    vector<int> profits = {25, 24, 15};
    int capacity = 20;
    // Applying strategies
    auto largest_profit = fractional_knapsack(weights, profits, capacity,
                                              "largest_profit");
    auto smallest_weight = fractional_knapsack(weights, profits, capacity,
                                               "smallest_weight");
    auto largest_ratio = fractional_knapsack(weights, profits, capacity,
                                             "largest_ratio");
    // Printing the results
    cout << "Using largest-profit strategy: " << largest_profit.first << endl;
    cout << "Using smallest-weight strategy: " << smallest_weight.first << endl;
    cout << "Using largest profit-weight ratio strategy: " << largest_ratio.first << endl;
    return 0;
}
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to solve the 0/1 Knapsack problem
pair<int, vector<int>> knapsack(const vector<int>& values, const vector<int>& weights, int capacity) {
    int n = values.size();
    
    // DP table: dp[i][w] represents the maximum value achievable with the first i items and capacity w
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    // Build the DP table
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    // Backtrack to find the selected items
    int w = capacity;
    vector<int> selected_items;
    for (int i = n; i > 0; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected_items.push_back(i - 1); // Item i was included
            w -= weights[i - 1];
        }
    }
    
    
    return {dp[n][capacity], selected_items};
}

int main() {
    // Input data
    vector<string> item_names = {"A", "B", "C", "D", "E", "F", "G", "H"};
    vector<int> values = {60, 100, 120, 80, 50, 140, 70, 30};
    vector<int> weights = {10, 20, 30, 40, 5, 25, 15, 10};
    int capacity = 50;

    // Solve the problem
    auto result = knapsack(values, weights, capacity);
    int max_value = result.first;
    vector<int> selected_indices = result.second;

    // Output results
    cout << "Maximum Value: " << max_value << endl;
    cout << "Selected Items: ";
    for (int index : selected_indices) {
        cout << item_names[index] << " ";
    }
    cout << endl;

    return 0;
}

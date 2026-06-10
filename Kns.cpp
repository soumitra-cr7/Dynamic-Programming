#include <bits/stdc++.h>
using namespace namespace std;

struct Item {
    char name[10];
    int profit;
    int weight;
};

int main() {
    int n;
    cin >> n;

    int cap;
    cin >> cap;

    struct Item items[n];
    for (int i = 0; i < n; i++) {
        cin >> items[i].name >> items[i].profit >> items[i].weight;
    }

    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));

    for (int i = 1; i <= n; i++) {
        int w = items[i - 1].weight;
        int p = items[i - 1].profit;

        for (int j = 0; j <= cap; j++) {
            dp[i][j] = dp[i - 1][j];
            if (w <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w] + p);
            }
        }
    }

    int originalCap = cap;
    vector<string> selected;
    for (int i = n; i > 0; i--) {
        if (dp[i][cap] != dp[i - 1][cap]) {
            selected.push_back(items[i - 1].name);
            cap -= items[i - 1].weight;
        }
    }

    reverse(selected.begin(), selected.end());

    cout << " Max profit : " << dp[n][originalCap] << endl;
    cout << " Total selected : " << selected.size() << endl;

    cout << " Selected items : ";
    for (int i = 0; i < selected.size(); i++) {
        cout << selected[i] << " ";
    }
    cout << endl;
    return 0;
}

#include<iostream>
using namespace std;

int main() {
int item;
cout << "Enter the number of items: ";
cin >> item;

int value[item];
int weight[item];

cout << "Enter the value and weight for each item:" << endl;
for(int i = 0; i < item; i++) {
cin >> value[i] >> weight[i];
}

int capacity;
cout << "Enter the knapsack capacity: ";
cin >> capacity;

int dp[item + 1][capacity + 1];

for(int i = 0; i <= item; i++) {
for(int j = 0; j <= capacity; j++) {
if (i == 0 || j == 0) {
dp[i][j] = 0;
}
else if (weight[i - 1] > j) {
dp[i][j] = dp[i - 1][j];

}
else {
dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
}
}
}

cout << "Maximum Value: " << dp[item][capacity] << endl;

return 0;
}

#include<iostream>
using namespace std;
const int MAX = 500;

int maxDistance(const string & word1, const string & word2)
{
int m = word1.length();
int n = word2.length();
int dp[MAX][MAX];

for (int i = 0; i <= m; ++i) {
for (int j = 0; j <= n; ++j) {
if (i == 0 || j == 0) {
dp[i][j] = 0;
} else if (word1[i - 1] == word2[j - 1]) {
dp[i][j] = dp[i - 1][j - 1] + 1;
} else {
dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
}
}
}
return dp[m][n];
}

int main() {
string word1 = "ABCDGH";
string word2 = "AEDFHR";

int distance = maxDistance(word1, word2);

cout << "Length of LCS: " << distance << endl;

return 0;
}

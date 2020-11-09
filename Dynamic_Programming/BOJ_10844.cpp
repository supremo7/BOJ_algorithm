#include<iostream>
#include<algorithm>

using namespace std;

long long dp[102][10];

int main(void) {
	dp[1][0] = 0;
	for (int i = 1; i <= 8; i++) {
		dp[1][i] = 1;
	}
	dp[1][9] = 1;

	for (int i = 2; i <= 100; i++) {
		dp[i][0] = dp[i - 1][1] % 1000000000;
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i-1][j - 1] + dp[i-1][j + 1]) % 1000000000;
		}
		dp[i][9] = dp[i - 1][8] % 1000000000;
	}

	int N;
	cin >> N;

	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[N][i];
	}

	cout << sum % 1000000000 << '\n';
}
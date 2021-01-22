#include<iostream>
#include<algorithm>
using namespace std;

int box[1005];
int dp[1005];

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> box[i];
	}

	

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (box[j] < box[i]) {
				dp[i] = max(dp[i],  dp[j] + 1);
			}
			
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < dp[i])
			ans = dp[i];
	}

	cout << ans << endl;

}
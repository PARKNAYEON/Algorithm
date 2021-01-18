#include<iostream>
#include<algorithm>
using namespace std;

int A[1005];
int dp[1005];
int main() {

	int S;
	int ans = 0;
	cin >> S;

	for (int i = 1; i <= S; i++) {
		cin >> A[i];
	}
	
	for (int i = 1; i <= S; i++) {
		dp[i] = A[i];
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j]) {
				dp[i] = max(dp[i], dp[j] + A[i]);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
#include<iostream>
using namespace std;
int A;
int num[1001];
int dp[1001] = { 0, };


int main() {

	int max = 0;
	cin >> A;
	for (int i = 0; i < A; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < A; i++) {
		for (int j = 0; j < i; j++) {
			if (num[i] < num[j] && dp[i] < dp[j]+1) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	for (int i = 0; i < A; i++) {
		//cout << dp[i];
		if (max < dp[i])
			max = dp[i];
	}
	
	cout << max+1;


}
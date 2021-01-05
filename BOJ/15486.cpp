#include<iostream>
#include<algorithm>
using namespace std;
int T[51];
int P[1001];
int dp[1001];
int N;
int main() {

	int maxSum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i];
		cin >> P[i];
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (i - j >= T[j]) {
				if(T[i] <= N - i){
					dp[i] = 0;
				}
				dp[i] = P[i] + P[j];
				cout << i <<","<< dp[i] <<","<< P[j];
				//cout << "a" << a << endl;
				//dp[i] = max(a, dp[i]);
				
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		cout << dp[i] << endl;
		if (maxSum < dp[i])
			maxSum = dp[i];
	}

	cout << maxSum;

}
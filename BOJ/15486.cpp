#include<iostream>
#include<algorithm>
using namespace std;
int T[1500005];
int P[1500005];
int dp[150005];
int N;
int main() {

	int maxSum = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i];
		cin >> P[i];
		//dp[i] = P[i];
	}

	for (int i = 1; i <= N; i++) {
		int a = 0;
		for (int j = 1; j < i; j++) {
			if (i - j >= T[j]) {
				if (T[i] > N - i + 1) {
					P[i] = 0;
					continue;
				}

				a = max(a, P[j]);

				//cout << i <<","<< P[i] <<","<< P[j]<< endl;
				//cout << "a" << a << endl;
				//dp[i] = max(a, dp[i]);

			}
		}
		P[i] = a + P[i];
	}

	for (int i = 1; i <= N; i++) {
		//cout << P[i] << endl;
		if (maxSum < P[i])
			maxSum = P[i];
	}

	cout << maxSum;

}

//time over
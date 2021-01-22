#include<iostream>
using namespace std;


int c[1005][15];


int main() {

	int N;
	cin >> N;

	for (int i = 0; i < 10; i++) {
		c[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 9; j >= 0; j--) {
			c[i][j] = c[i - 1][j] + c[i][j + 1];
			c[i][j] = c[i][j] % 10007;
		}
	}

	int answer = 0;

	for (int i = 0; i <= 9; i++) {
		answer += c[N][i];
	}

	cout << answer%10007;
}
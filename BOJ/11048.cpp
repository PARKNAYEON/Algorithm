#include<iostream>
#include<algorithm>
using namespace std;

int map[1005][1005];
int dp[1005][1005];

int main() {

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(max(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + map[i][j];
		}
	}

	cout << dp[N][M] << endl;
}
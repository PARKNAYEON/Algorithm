#include<iostream>
#include<algorithm>
using namespace std;

int map[505][505];
int dp[505][505];
long long H;
int m, n;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int dfs(int x, int y) {
	
	if (x == m && y == n)
		return 1;
	if (dp[x][y] != -1)
		return dp[x][y];

	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 1 && ny >= 1 && nx <= m && ny <= n) {
			//cout << nx << ',' << ny << endl;
			if (map[nx][ny] < map[x][y]) { //더 작은 값 쪽으로 이동해야하니까 
				dp[x][y] = dp[x][y] + dfs(nx, ny);
			}
		}
	}
	return dp[x][y];
}

int main() {
	

	cin >> m >> n;
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		
		}
	}

	cout << dfs(1, 1);
	




}
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int map[100005];
int visited[100005];
int N, K;
int result = 999999999;

void bfs() {

	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));
	visited[N] = 1;
	
	while (!q.empty()) {

		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == K) {
			if (result > cnt) {
				result = cnt;
			}
		}

		if (x + 1 >= 0 && x+1 <= 100000 && visited[x + 1] == 0) {
			q.push(make_pair(x + 1, cnt+1));
			visited[x + 1] = 1;
		}
		if (x - 1 >= 0 && x-1 <= 100000 && visited[x - 1] == 0) {
			q.push(make_pair(x - 1, cnt+1));
			visited[x - 1] = 1;
		}
		if (2 * x <= 100000 && 2 * x >= 0 && visited[2 * x] == 0) {
			q.push(make_pair(2 * x, cnt+1));
			visited[2 * x] = 1;
		}

	}




}


int main() {

	cin >> N >> K;

	bfs();

	cout << result;
}
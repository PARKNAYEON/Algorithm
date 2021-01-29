#include<iostream>
#include<queue>
using namespace std;
int N, M, V;
int map[1005][1005];
int visited[1005];
int visitedBfs[1005];

void dfs(int v) {

	cout << v << ' ';
	visited[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 1 || map[v][i] == 0)
			continue;
		dfs(i);
	}

}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visitedBfs[v] = 1;
	while (!q.empty()) {
		v = q.front();
		cout << q.front() << ' ';
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (visitedBfs[i] == 1 || map[v][i] == 0)
				continue;
			q.push(i);
			visitedBfs[i] = 1;
		}
	}

}

int main() {

	cin >> N >> M >> V;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		map[x][y] = map[y][x] = 1;
	}
	dfs(V);
	cout << endl;
	bfs(V);


}
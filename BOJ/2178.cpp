#include<iostream>
#include<queue>
using namespace std;

char map[105][105];
int checked[105][105] = { 0, };
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };


int main() {

	int h, w;
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		cin >> map[i];
	}

	/*for (int i = 1; i <= h; i++) {
		for(int j = 0; j < w; j++)
			cout <<  map[i][j];
		cout << endl;
	}
	*/
	queue<pair<int, int>> q;

	q.push(make_pair(1, 0));
	checked[1][0] = 1;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		int cx = p.first;
		int cy = p.second;
		
		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];

			if (nx >= 1 && ny >= 0 && nx <= h && ny < w) {
				if (checked[nx][ny] == 0 && map[nx][ny] == '1') {
					q.push(make_pair(nx, ny));
					checked[nx][ny] = checked[cx][cy] + 1;
				}
			}
		}

	}

	cout << checked[h][w-1] << endl;


}
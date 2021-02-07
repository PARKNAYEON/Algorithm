#include<iostream>
#include<queue>
#include<vector>
#define INF 99999999
#define MAX 20005
using namespace std;


int dist[MAX];
int V, E, K;

vector<pair<int, int>> ve[MAX];

void Dij() {
	
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, K));
	dist[K] = 0;
	while (pq.empty() == 0) {
		
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		
		for (int i = 0; i < ve[cur].size(); i++) {
			int next = ve[cur][i].first;
			int nCost = ve[cur][i].second;

			if (dist[next] > cost + nCost) {
				dist[next] = cost + nCost;
				pq.push(make_pair(-dist[next], next));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF" << endl;
		}
		else {
			cout << dist[i] << endl;
		}
	}

}



int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> V >> E >> K;

	for (int i = 1; i <= E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		ve[u].push_back(make_pair(v, w));

		for (int i = 1; i <= V; i++) {
			dist[i] = INF;
		}
	}
	Dij();

	return 0;

}

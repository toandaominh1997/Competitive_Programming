#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;
int n, m;
struct DisjointSets {
	int *parent, *rank;
	DisjointSets(int n) {
		parent = new int [n + 1];
		rank = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			rank[i] = 0;
			parent[i] = i;
		}
	}
	int find(int u) {
		return u == parent[u] ? parent[u] : parent[u] = find(parent[u]);
	}
	void merge(int x, int y) {
		x = find(x), y = find(y);
		if (rank[x] > rank[y]) {
			parent[y] = x;
		}
		else {
			parent[x] = y;
		}
		if (rank[x] == rank[y]) {
			rank[y]++;
		}
	}
};

struct Graph {
	int V, E;
	vector<pair<int, iPair>> edges;

	Graph(int V, int E) {
		this->V = V;
		this->E = E;
	}
	void addEdge(int u, int v, int w) {
		edges.push_back({w, {u, v}});
	}
	int kruskalMST() {
		int mst_wt = 0;
		sort(edges.begin(), edges.end());
		DisjointSets ds(V);
		vector<pair<int, iPair> >::iterator it;
		for (it = edges.begin(); it != edges.end(); it++) {
			int u = it->second.first;
			int v = it->second.second;
			int set_u = ds.find(u);
			int set_v = ds.find(v);
			if (set_u != set_v) {
				cout << u << " - " << v << endl;
				mst_wt += it->first;
				ds.merge(set_u, set_v);
			}
		}
		return mst_wt;
	}
};
int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d %d", &n, &m);
	Graph g(n, m);
	int u, v, w;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}
	cout << "Edges of MST are \n";
	int mst_wt = g.kruskalMST();

	cout << "\nWeight of MST is " << mst_wt;
}

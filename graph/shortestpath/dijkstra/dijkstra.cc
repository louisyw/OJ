/*
 *Dijkstra算法，用邻接表实现的图
 */
#include <vector>
#include <queue>

struct edge{
	int to, cost;
};

typedef pair<int, int> P;   //first代表到源点距离，second代表节点

vector<edge> G[MAX_V];

int d[MAX_V];

void dijkstra(int s){
	
}
void dijkstra(int s){  // s源点
	priority_queue<P, vector<P>, greater<P>> que;
	fill(d, d+V, INF);
	d[s] = 0;
	que.push(P(0, s));

	while(!que.empty()){
		P p = que.top(); que.pop();
		int v = p.second;
		if (d[v] < p.first) continue;
		for (int i = 0; i < G[v].size(); i++){
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

/*
 *Dijkstra算法，利用邻接矩阵实现
 */

int cost[MAX_V][MAX_V];   //cost[u][v]表示边e=(u,v)的权值
int d[MAX_V];             //顶点s出发的距离
bool used[MAX_V];         //已经使用过的图
int V;                    //顶点数

void Dijkstra(int s){
	fill(d, d+V, MAX_INT);
	fill(used, used + V, false);
	d[s] = 0;

	while(true){
		int v = -1;

		//找出距离最小的没有访问过的节点
		for(int u = 0; u < V; u++){
			if (!used[u] && (v == -1 || d[u] < d[v]))
				v = u;
		}

		if (v == -1)  break;
		used[v] = true;
		//根据找出的节点更新剩余的节点的距离
		for (int u = 0; u < V; u++){
			d[u] = min(d[u], d[v] + cost[v][u]);
		}
	}
}

#include <vector>

struct vertex{
	vector<vertex *> edge;
	/*
	 *顶点的属性
	 */
};

vertex G[MAX_V];

int main(){
	int V,E;
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++){
		int s, t;
		scanf("%d %d", &s, &t);
		G[s].edge.push_back(&G[t]);
		G[t].edge.push_back(&G[s]);
	}

	/*
	 *图的操作
	 */
	return 0;
}

/*
 *图的邻接表表示方法
 */

#include <vector>

vector<int> G[MAX_V];
/*
 *边上有属性的情况
 *struct edge {int to; int cost; };
 *vector<edge> G[MAX_V];
 *
 */


int main(){
	int V, E;
	scanf("%d %d", &V, &E)    //顶点数， 边数
	for(int i = 0; i < E; i++){
		//从s到t连边
		int s, t;
		scanf("%d %d", &s, &t);
		G[s].push_back(t);
		//无向图，则从t到s再连边

		/*有向图初始化
		 *for(int i= 0; i < E; i++){
		 *	int s, t, co;
		 *	edge temp;
		 *	scanf("%d %d %d", &s, &t, &co);
		 *	temp.to = t;
		 *	temp.cost = co;
		 *	G[s].push_back(temp);
		 *}
		 */
	}

	//图的操作

	return 0;
}

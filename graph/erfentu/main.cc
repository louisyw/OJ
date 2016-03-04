/*
 *给定一个具有n个顶点的图，要给图上每个顶点染色，并且要使相邻的顶点颜色不
 *相同，问能否最多用两种颜色进行染色
 */
#include <vector>

int V;
int color[MAX_V];       //顶点i的颜色(1 or -1)

bool dfs(int v, int c){
	color[v] = c;
	for (int i = 0; i < G[v].size(); i++){
		if (color(G[v][i]) == c) return false;
		if (color(G[v][i]) == 0 && !dfs(G[v][i], -c))  return false;
	}
	return true;
}

void solve(){
	for (int i = 0; i < V; i++){
		if (color[i] == 0){
			if (!dfs(i , 1)){
				printf("No\n");
				return;
			}
		}
	}
	printf("Yes\n");
} 	

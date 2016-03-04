/*
 *邻接表实现，实现优先队列
 *详见http://www.acmerblog.com/dijkstras-algorithm-adjacency-list-5882.html
 */

#include <cstdio>

//邻接表的节点
struct listNode{
	int to;
	int weight;
	listNode *next;
};
//邻接表  头结点
struct list{
	listNode *head;
};

//二维的邻接表实现
struct graph{
	int V;     //顶点数
	list *array;
};

listNode *createListNode(int dest, int weight){
	listNode * newNode = new listNode;
	newNode->to = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

graph * createGraph(int V){
	graph * g = new graph;
	graph->V = V;

	graph->array = new list[V];

	for(int i = 0; i < V; i++){
		graph->array[i].head = NULL;
	}
	return g;
}

//无向图
void addEdge(graph *g, int src, int dest, int weight){

	listNode *newNode = createListNode(dest, weight);
	newNode->next = g->array[src].head;
	g->array[src].head = newNode;

	newNode = createListNode(src, weight);
	newNode->next = g->array[dest].head;
	g->array[dest].head = newNode;
}

//最小堆的实现


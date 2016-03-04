/*
 *Subsequence(POJ 3061)
 *description:尺取法
 *尺取法的方法是维护一对下标(起点，终点),根据实际情况交替推进两个端点
 *给定长度为n的数列整数a0, a1, a2 .... an-1以及整数S。求出总和不小于S的连
 *续子序列的长度的最小值，如果不存在，则输出0；
 */

#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;
const int MAX_N = 100000;
int a[MAX_N];
int N, S;


//using binary-search
int sum[MAX_N + 1];  //sum[0]为0, sum[i]表示以a[i]结尾的子序列的和
void solve1(){

	for(int i = 0; i < N; i++){
		sum[i+1] = sum[i] +a[i];
	}

	if (sum[N] < S){
		printf("0\n");
		return;
	}
	
	int res = N;
	for(int start = 0; sum[start] + S <= sum[N]; ++start){
		int t = lower_bound(sum+start, sum+N, sum[start] + S) -sum;
		res = min(res, t - start);
	}
	printf("%d\n", res);
}


//使用尺取法
void solve2(){
	int s = 0, t = 0, sum = 0;
	int res = N+1;

	for(int i = 0; i < N; ++i){
		t = i + 1;
		sum += a[i];
		if(sum >= S){
			res = min(res, t -s);
			while(sum >= S)      //弹出队列头部的元素直到 sum<S
				sum -= a[s++];
		}
	}

	if (res > N)
		res = 0;
	
	printf("%d\n", res);
	
}

int main(){
	scanf("%d %d", &N, &S);

	for (int i = 0 ;i < N; ++i){
		scanf("%d", a+i);
	}
	solve1();
	solve2();
	return 1;
}



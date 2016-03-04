#include <cstdio>
#include <iostream>
using namespace std;

const int MAX_N = 40;
//输入
int N = 4;

int a[MAX_N];   //存入对应的行中1的最右边的位置
int M[MAX_N][MAX_N];

			
void solve(){
	int ans = 0;
	//初始化每行中最右边1的位置
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if (M[i][j] == 1) a[i] = j;
		}
	}

	for(int i = 0; i < N; i++){
		int pos = -1;
		for (int j = i; j < N; j++){
			if (a[j] <= i){
				pos = j;
				break;
			}
		}

		for(int j = pos; j > i; j--){
			swap(a[j], a[j-1]);
			ans++;
		}
	}
	printf("%d\n", ans);
}

int main(){
	M[0][0] = 1;
	M[0][1] = 1;
	M[0][2] = 1;
	M[0][3] = 0;
	M[1][0] = 1;
	M[1][1] = 1;
	M[1][2] = 0;
	M[1][3] = 0;
	M[2][0] = 1;
	M[2][1] = 1;
	M[2][2] = 0;
	M[2][3] = 0;
	M[3][0] = 1;
	M[3][1] = 0;
	M[3][2] = 0;
	M[3][3] = 0;
	solve();
	return 0;
}

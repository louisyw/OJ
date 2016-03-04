#include <vector>
#include <cstdio>
#include <map>

using namespace std;

//素性测试
bool test_prime(int n){
	for (int i = 1; i * i <= n; i++){
		if (n % i == 0) return false;
	}
	return n != 1;
}

//约数枚举
vector<int> divisor(int n){
	vector<int> res;

	for(int i = 1; i * i <= n; i++){
		if (n % i == 0){
			res.push_back(i);
			if (i != n/i) res.push_back(n/i);
	printf("\n");
		}
	}
	return res;
}

//这个数除约数的个数
map<int, int> prime_factor(int n){
	map<int, int> res;
	for(int i = 2; i * i < n; i++){
		while(n % i == 0){
			++res[i];
			n/=i;
		}
	}
	if ( n != 1) res[n] = 1;
	return res;
}

//某个数以内素数的个数

const int MAX_N = 100000;
int prime[MAX_N];    //依次记录素数，数组的size反应了素数的个数
bool is_prime[MAX_N];

int sieve(int n){
	int p = 0;
	for(int i = 0; i <= n; i++){
		is_prime[i] = true;
	}
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++){
		if (is_prime[i]){
			for(int j = 2*i; j <= n; j+=i){
				is_prime[j] = false;
			}
			prime[p++] = i;
		}
	}
	return p;
}


//某个区间内素数的个数
typedef long long ll;
const int MAX_L = 1000000;
const int MAX_SORT_B = 1000000;

bool is_prime1[MAX_L];      //存储的是[a,b)
bool is_prime_small[MAX_SORT_B];    //存储的是[2,sqrtb)

// 对区间[a,b)执行筛选，is_prime1[i-a] == true表明i是素数
int segment_sieve(ll a, ll b){
	for(int i = 0; (ll)i * i < b; i++)  is_prime_small[i] = true;
	is_prime_small[0] = is_prime_small[1] = false;

	for(int i = 0; i < b-a; i++) is_prime1[i] = true;

	for(int i = 2; (ll) i * i < b; i++){
		if (is_prime_small[i]){
			for(int j = 2 *i; (ll)j*j< b; j += i )
				is_prime_small[j] = false;
			
			ll num = (ll)2*i;
		  	while(num < a){
		  		num += i;
		  	}
		  	for (int j = num; j < b; j+=i){
		  		is_prime1[j-a] = false;
		  	}
		   //	for(ll j = max(2LL, (a+i-1) / i) * i; j < b; j += i){
		   //		is_prime1[j - a] = false;
		   //	}

		}
	}
	int count = 0;
	for (int i = 0; i < (int)(b-a); i++){
		if(is_prime1[i])
			count++;
	}
	return count;
}

int main(){
	int num = sieve(100);
	printf("number is %d\n", num);
	//for (int m = 0; m < num; m++){
	//	printf("Index %d is %d\n", m, prime[m]);
	//}

	//int number = segment_sieve(22801763489, 22801787297);
	int number = segment_sieve(11,100);
	printf("%d\n", number);
	return 0;
}

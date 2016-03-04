/*
 *计算大数的幂的模
 *
 * 原理：x * y % m = (x % m) * (y % m) % m
 * x^22 = x^16 * x^4 * x^2
 * x^22 % m = (x^16 % m)*(x^4 % m)*(x^2 % m)
 */
typedef long long ll;

ll mod_pow(ll x, ll n, ll mod){
	if ( n == 0) return 1;
	ll res = mod_pow(x * x % mod, n/2, mod);
	if (n&1) res = res * x % mod;
	return res;
}

ll mod_pow1(ll x, ll n, ll mod){
	ll res = 1;
	while(n){
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n>>=1;
	}
	return res;
}



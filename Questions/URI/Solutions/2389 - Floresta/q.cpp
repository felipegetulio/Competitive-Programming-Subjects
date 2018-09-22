
using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);

#define ll long long
#define ii pair<ll, ll>

map<ii, int> mapa;

ll bb(int s, int n, ll x){
	ll lo = s, hi = n, mid;
	while(lo < hi){
		mid = lo + (hi - lo>>1);
		if(x*mid + (x-1)*(mid-1) >= n) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int main(){_
	ll n, cont = 0;
	scanf("%lld", &n);

	for(ll x=2, y; x*x<=n; x++){
		y = bb(2, n, x);

		if((x*y + (x-1)*(y-1) == n) && !mapa[ii(x, y)]){
			mapa[ii(x, y)] = mapa[ii(y, x)] = 1;
			cont++;
		}
	}

	printf("%lld\n", cont);

	return 0;
}

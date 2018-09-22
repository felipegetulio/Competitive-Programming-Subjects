#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 10004

using namespace std;

int v[MAXN];

//Busca Binária Padrão

int	bb(int ini, int fim, int x){
	int lo = ini, hi = fim, mid;

	while(lo < hi){
		mid = lo + (hi - lo>>1);

		if(x <= v[mid]) hi = mid;
		else lo = mid+1;
	}
	return lo;
}

int main(){_
	int n, q, ind, k, t = 1;
	while(cin >> n >> q && (n||q)){
		for(int i=n; i--;)
			cin >> v[i];

		sort(v, v+n);
		cout << "CASE# " << t++ << ":" << endl;
		while(q--){
			cin >> k;
			ind = bb(0, n, k);
			if(v[ind] == k) cout << k << " found at " << ind+1 << endl;
			else cout << k << " not found" << endl;
		}
	}


	return 0;
}


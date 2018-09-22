#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 100005


using namespace std;

int v[MAXN];


int	bb(int ini, int fim, int somaTotal){
	int lo = ini, hi = fim, mid;

	while(lo < hi){
		mid = lo + (hi - lo>>1);

		if(v[mid] >= somaTotal - v[mid]) hi = mid;
		else lo = mid+1;
	}
	return lo;
}

int main(){_
	int n, ind, somaTotal = 0;
	cin >> n;

    for(int i=1; i<=n; i++){
        cin >> v[i];
        somaTotal += v[i];
        v[i] += v[i-1];
    }

    ind = bb(1, n, somaTotal);

    cout << ind << endl;

	return 0;
}

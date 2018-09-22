#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 100004
#define inf 1000000000
using namespace std;

int v[MAXN];

int kadane(int n){
	int soma = -inf;
	for(int i=1; i<=n; i++){
		v[i] = max(v[i-1]+v[i], v[i]);
		soma = max(soma, v[i]);
	}
	return soma;
}

int main(){_
	int n, ans;
	while(scanf("%d", &n) && n){
		for(int i=1; i<=n; i++)
			scanf("%d", v+i);
        ans = kadane(n);

        if(ans>0) cout << "The maximum winning streak is " << ans << ".";
        else cout << "Losing streak.";
        cout << endl;
	}


	return 0;
}

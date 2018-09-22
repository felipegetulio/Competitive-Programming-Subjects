#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 100005


using namespace std;

int v[MAXN];


int	bb(int ini, int fim, int a, int soma){
	int lo = ini, hi = fim, mid;

	while(lo < hi){
		mid = lo + (hi - lo>>1);

		if(a+v[mid] >= soma) hi = mid;
		else lo = mid+1;
	}
	return lo;
}

int main(){_
	int n, achou = 0, ind, soma, a, b;
	cin >> n;
    for(int i=0; i<n; i++)
        cin >> v[i];
    cin >> soma;

    for(int i=0; i<n-1 && !achou; i++){
        ind = bb(i+1, n-1, v[i], soma);
        if(v[i] + v[ind] == soma){
            achou = 1;
            a = v[i]; b = v[ind];
        }
    }
    cout << a << ' ' << b << endl;

	return 0;
}

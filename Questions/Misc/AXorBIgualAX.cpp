#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 100004

using namespace std;

int v[MAXN], freq[MAXN];

//calcula a quantidade de pares i e j tais que v[i]^v[j] == x em O(n)

int main(){_
	int n, x;
	long long cont = 0;
	cin >> n >> x;
	for(int i=0; i<n; i++)
		cin >> v[i];
	
	for(int i=0, j; i<n; i++){
		j = v[i]^x;
		cont += (j<MAXN)*freq[j];
		freq[v[i]]++;
	}
	cout << cont << endl;
		
	return 0;
}

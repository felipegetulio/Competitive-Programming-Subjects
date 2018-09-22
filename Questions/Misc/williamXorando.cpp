#include<iostream>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 1003

using namespace std;

int v[MAXN];

int main(){_
	int n, m, k;
	while( (cin >> n >> m >> k) && (n!=0 || m!=0 || k!=0)){
		for(int i=0; i<n; i++) cin >> v[i];
		cout << v[(((k-1) - m%n)%n + n)%n] << endl;
	}
	return 0; 
}

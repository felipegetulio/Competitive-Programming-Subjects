#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 104
using namespace std;

int v[MAXN];

int main(){_
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> v[i];
	sort(v, v+n);
	cout << v[0];
	for(int i=1; i<n; i++)
		cout << ' ' << v[i];
	cout << endl;

	return 0;
}

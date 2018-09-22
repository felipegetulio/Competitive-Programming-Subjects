#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 1000000000
using namespace std;

typedef unsigned long long ull;

ull maior, n, resp;
bitset<MAXN> freq;
stringstream ss;
string s;

void simula(ull k){
	while(!freq[k]){
		freq[k] = 1;
		maior = max(maior, k);
		ss.clear();
		ss << k*k;
		ss >> s;
		ss.clear();
		ss << (s.substr(0, n));
		ss >> k;
	}
}

int main(){_
	int t;
	ull k;
	cin >> t;
	while(t--){
		freq.reset();
		maior = 0;
		cin >> n >> k;
		simula(k);
		cout << maior << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 10000004
#define ll long long
#define vi vector<int>

using namespace std;

bitset<MAXN> ehprimo;
vi primos;
int tamPrimos, qntprimos[MAXN];

void crivo(int n){
	ehprimo.set();
	ehprimo[0] = ehprimo[1] = 0;
	for(int i=2; i*i<n; i++)
		if(ehprimo[i])
			for(int j = i*i; j<n; j+=i)
				ehprimo[j] = 0;

	for(int i=2; i<n; i++)
		qntprimos[i] = qntprimos[i-1] + ehprimo[i];
}

int pot2(int n){
	int exp = 0;
	for(int i=2; i<=n; i*=2)
		exp+=(n/i);
	return exp;
}

int main(){_
	int a, b;
	int fat, prim;
	int exp1, exp2, exp3;
	crivo(MAXN);

	cin >> a >> b;
	if(a > b) swap(a, b);
	fat = abs(a-b);
	prim = qntprimos[b] - qntprimos[(a != 0)*(a-1)];
	exp1 = pot2(fat + prim -1);
	exp2 = pot2(fat);
	exp3 = pot2(prim-1);
	exp1 -= (exp2 + exp3);
	if(a == b) cout << "?" << endl;
	else if(prim == 0) cout << "Bob" << endl;
	else if(exp1) cout << "Bob" << endl;
	else cout << "Alice" << endl;

	return 0;
}

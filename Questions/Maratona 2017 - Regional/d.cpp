using namespace std;
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 1000004
#define vll vector<ll>
#define ll long long

bitset<MAXN> ehprimo;
vll primos;

void crivo(int n){
	ehprimo.set();
	ehprimo[0] = ehprimo[1] = 0;

	for(int i=2; i*i<n; i++)
		if(ehprimo[i])
			for(int j=i*i; j<n; j+=i)
				ehprimo[j] = 0;

	primos.push_back(2);
	primos.push_back(3);

	for(int i=5; i<n; i+=6){
		if(ehprimo[i])
			primos.push_back(i);
		if(ehprimo[i+2])
			primos.push_back(i+2);
	}
}

int ehDespojado(ll n){
	ll i=0, primo = primos[i], qntPrimos = 0;

	while(primo*primo <= n){

		if(n%primo == 0){
			n/=primo;
			qntPrimos++;
			if(n%primo == 0) return 0;
		}

		primo = primos[++i];
	}

	qntPrimos += (n != 1);
	return qntPrimos > 1;
}

ll qntDivDespojados(ll n){
	ll cont = 0;

	for(ll i=1; i*i<=n; i++){
		if(n%i == 0){
			cont += ehDespojado(i);
			if(i*i != n) cont += ehDespojado(n/i);
		}
	}
	return cont;

}



int main(){
	ll n;
	crivo(MAXN);
	scanf("%lld", &n);
	printf("%lld\n", qntDivDespojados(n));


	return 0;
}

#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define vi vector<int>
#define MAXN 30
#define ll long long
#define firstIdDeNivel(a, n) (ll)(a*(n*pot(a, n+1)-(n+1)*pot(a, n)+1)/((a-1)*(a-1)))

using namespace std;

string sons[MAXN];
int maximos[] = {0, 2, 23, 16, 13, 11, 10, 10, 9, 9, 9, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};


vi decToBase(int base, int n, int nivel){
    vi num;
    if(base == 1)
        num.push_back(n);
    while(n){
        num.push_back(n%base);
        n /= base;
    }
    while(num.size() <= nivel)
        num.push_back(0);
    return num;
}

ll pot(ll base, int exp){
    if(exp == 0) return 1;
    if(base == 0 || base == 1) return base;
    ll ans = 1;
    while(exp){
        if(exp&1) ans *= base;
        base *= base;
        exp >>=1;
    }
    return ans;
}

int buscaBinaria(int n, int x){
    int lo = 0, hi = maximos[n], mid;

    while(lo < hi){
        mid = lo + (hi-lo)/2;
        if(firstIdDeNivel(n, mid) > x)
            hi = mid;
        else lo = mid+1;
    }

    return lo-1;
}

int main(){_
    int n, q, k, indConjunto, nivelDeK, primeiroIndNivelK, indPermutacao, indPalavraDePermutacao;
    vi permutacao;

    while((cin >> n >> q) && (n||q)){
        for(int i=0; i<n; i++)
            cin >> sons[i];
        sort(sons, sons+n);
        while(q--){
            cin >> k;
            k--;
            if(n==1){
                cout << sons[0] << endl;
                continue;
            }
            nivelDeK = buscaBinaria(n, k); cout << "nivel: " << nivelDeK << endl;
            primeiroIndNivelK = firstIdDeNivel(n, nivelDeK); cout << "primeiro: " << primeiroIndNivelK << endl;
            indPermutacao = (k - primeiroIndNivelK)/(nivelDeK+1); cout << "indPerm: " << indPermutacao << endl;
            indPalavraDePermutacao = (k - primeiroIndNivelK)%(nivelDeK+1); cout << "indPalavra: " << indPalavraDePermutacao << endl;
            permutacao = decToBase(n, indPermutacao, nivelDeK); for(int i=permutacao.size(); i--;) cout << permutacao[i] << ' '; cout << endl;
            cout << sons[permutacao[permutacao.size() - indPalavraDePermutacao - 1]] << endl;
        }
        cout << endl;
    }

	return 0;
}

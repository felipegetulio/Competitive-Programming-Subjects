#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 100004

using namespace std;
//1125899906842624 1 50
typedef long long ll;
typedef vector<ll> vi;


int qntBits(ll n){
    if(n == 0) return 0;
    return 1+qntBits(n>>1);
}

ll qntAteS(ll n, ll s){
    ll cont = 0;
    int qntBitsN = qntBits(n);
    for(int i=0; i<qntBitsN && (1LL<<i)<=s; i++)
        if((1LL<<(qntBitsN-i-1)) & n)
            cont += ceil(1.0*(s-(1LL<<i)+1)/(1LL<<(i+1)));
    return cont;
}

int main(){_
    ll n, r, l, cont = 0;
    cin >> n >> l >> r;
    cout << qntAteS(n, r) - qntAteS(n, l-1) << endl;


    return 0;
}

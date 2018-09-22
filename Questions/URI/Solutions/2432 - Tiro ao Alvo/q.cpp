#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 100005
#define inf 1<<30
#define ll long long
#define dist(x, y) (x*x + y*y)

using namespace std;

ll raios[MAXN], x[MAXN], y[MAXN];

int bb(int ini, int fim, ll x, ll y){
    int lo = ini, hi = fim, mid;

    while(lo < hi){
        mid = lo + (hi - lo>>1);
        if(raios[mid]*raios[mid] >= dist(x, y)) hi = mid;
        else lo = mid+1;
    }
    return lo;
}

int main(){
    int c, t, ind;
    ll soma = 0;
    scanf("%d%d", &c, &t);
    for(int i=0; i<c; i++)
        scanf("%lld", raios+i);
    for(int i=0; i<t; i++)
        scanf("%lld%lld", x+i, y+i);

    raios[c] = inf;

    for(int i=0; i<t; i++){
        ind = bb(0, c, x[i], y[i]);
        soma += c-ind;
    }
    printf("%lld\n", soma);

    return 0;
}

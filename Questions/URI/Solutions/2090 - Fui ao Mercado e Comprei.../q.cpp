#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 100004
#define ll long long

#define op(n) ((ll)n*(n+1)>>1)

using namespace std;

string prod[MAXN];

int bb(ll x){
    int lo = 0, hi = 64000, mid;

    while(lo < hi){
        mid = lo + (hi - lo >> 1);

        if(op(mid) > x) hi = mid;
        else lo = mid+1;
    }
    return lo-1;
}

int main(){_
    int n, ind;
    ll k;
    while(cin >> n >> k && (n||k)){
        for(int i=0; i<n; i++)
            cin >> prod[i];
        k--;
        ind = bb(k);
        cout << prod[(k-op(ind))%n] << endl;

    }


    return 0;
}

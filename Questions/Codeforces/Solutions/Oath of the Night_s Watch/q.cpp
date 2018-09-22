#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 100004

using namespace std;

int st[MAXN];


int main(){_
    int n, cont = 0;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> st[i];
    sort(st, st+n);
    for(int i=1; i<n-1; i++)
        cont += (st[i] != st[0] && st[i] != st[n-1]);
    cout << cont << endl;

    return 0;
}

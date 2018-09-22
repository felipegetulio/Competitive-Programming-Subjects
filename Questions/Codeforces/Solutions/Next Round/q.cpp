using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define ll long long
#define MAXN 54

int v[MAXN];

int main(){_
    int n, k, cont = 0;
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> v[i];

    for(int i=1; i<=n && v[i]>=v[k] && v[i]>0; i++) cont++;
    cout << cont << endl;

    return 0;
}

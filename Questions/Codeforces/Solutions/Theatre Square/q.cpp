using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define ll long long

int main(){_
    ll n, m, a, ans;
    cin >> n >> m >> a;
    ans = ((n+a-1)/a)*((m+a-1)/a);
    cout << ans << endl;

    return 0;
}

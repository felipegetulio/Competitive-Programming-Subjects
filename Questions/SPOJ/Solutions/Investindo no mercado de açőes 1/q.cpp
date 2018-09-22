#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 10004

using namespace std;

int n, x;

int solve(int n){
    if(n <= x) return 1;

    if(n%2 == 0)
        return 2*solve(n/2);
    else
        return solve(n/2) + solve(n/2+1);
}

int main(){_
    while( (cin >> n >> x) && (n||x)){
        cout << solve(n) << endl;
    }

    return 0;
}

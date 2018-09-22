using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define pii pair<int, int>
#define INF 1000000000
#define MAXN 10003
#define fi first
#define se second

int n, m ,t;
pii memo[MAXN];


pii maxBurgers(int sum){

	if(memo[sum].first != -1)
		return memo[sum];

	pii left(0, sum), right(0, sum), ans;

	if(sum - n >= 0){
		left = maxBurgers(sum - n);
		++left.fi;
	}  

	if(sum - m >= 0){
		right = maxBurgers(sum - m);
		++right.fi;
	}

	if(left.se == right.se)
		ans = left.fi > right.fi ? left : right;
	else
		ans = left.se < right.se ? left : right;


	return memo[sum] = ans;
}

void init(){
	for(int i=0; i<=t; ++i)
		memo[i].fi = -1;
}


int main(){_
    
    while(cin >> n >> m >> t){
    	init();

    	pii ans = maxBurgers(t);

    	cout << ans.fi;
    	if(ans.se != 0)
    		cout << ' ' << ans.se;
    	cout << endl;

    }


    return 0;
}

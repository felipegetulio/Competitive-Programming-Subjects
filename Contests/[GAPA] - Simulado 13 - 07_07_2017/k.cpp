using namespace std;
#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

int main(){_

	double r, h, v, g, a;
	char ans[] = {'N', 'Y'};

	while(cin >> r >> h >> v >> g){
		a = (v*v + v*sqrt(v*v + 4*g*h))/(2*g);

		cout << ans[a-r>0.001] << endl;
	}
  

    return 0;
}

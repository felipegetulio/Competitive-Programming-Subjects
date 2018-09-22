#include<bits/stdc++.h>
#define _a first
#define _b second
#define _l first
#define _r second.first
#define _index second.second
#define LSB(x) ((x)&-(x))
#define MAXN 200004
#define MAXFT 400004
#define ii pair<int, int>
#define iii pair<int, ii>

#define _ ios_base::sync_with_stdio(0);
using namespace std;

map<int, int> mp;
set<int> numbers;
map<ii, int> memo;
iii ranges[MAXN];
int ans[MAXN];
int ft[MAXFT];
int sizeFT;


void update(int index, int value){

	while(index <= sizeFT){
		ft[index] += value;
		index += LSB(index);
	}
}

int query(int index){

	int ans = 0;

	while(index > 0){
		ans += ft[index];
		index -= LSB(index);
	}

	return ans;
}

bool cmp(iii a, iii b){
	if(a._r - a._l != b._r - b._l){
		return a._r - a._l > b._r - b._l;
	}
	else return a < b;
}


int main(){
	int l, r;
	int n;

	while(scanf("%d", &n) != EOF){

		numbers.clear();
		mp.clear();
		sizeFT = 0;
		memo.clear();

		for(int i=1; i<=n; ++i){
			scanf("%d %d", &l, &r);
			ranges[i]._l = l;
			ranges[i]._r = r;
			ranges[i]._index = i;
			numbers.insert(l);
			numbers.insert(r);
		}

		for(auto v : numbers){
			mp[v] = ++sizeFT;
			ft[sizeFT] = 0;
		}

		sort(ranges+1, ranges+1+n, cmp);

		for(int i=1; i<=n; ++i){
			if(memo.find(ii(ranges[i]._l, ranges[i]._r)) != memo.end()){
				ans[ranges[i]._index] = memo[ii(ranges[i]._l, ranges[i]._r)];
			}
			else{
				memo[ii(ranges[i]._l, ranges[i]._r)] = ans[ranges[i]._index] = min(query(mp[ranges[i]._l]), query(mp[ranges[i]._r]));	
			}
			update(mp[ranges[i]._l], 1);
			update(mp[ranges[i]._r]+1, -1);
		}

		// cout << ans[1];
		// for(int i=2; i<=n; ++i){
		// 	cout << ' ' << ans[i];
		// }
		// cout << endl;

		printf("%d", ans[1]);
		for(int i=2; i<=n; ++i){
			printf(" %d", ans[i]);
		}
		printf("\n");
	}


	return 0;
}
#include<bits/stdc++.h>
#define oo 1000000000
#define OUT -oo
#define left(u) ((u)<<1)
#define right(u) (((u)<<1)+1)
#define mid(l, r) ((r+l)>>1)
#define _ ios_base::sync_with_stdio(0);
#define MAXN 100004
using namespace std;


int v[MAXN], st[MAXN<<2];


void build(int u, int l, int r){

	if(r == l){
		st[u] = v[r];
	}
	else{
		build(left(u), l, mid(r, l));
		build(right(u), mid(r, l)+1, r);	
		st[u] = st[left(u)] + st[right(u)];
	}
}

int query(int u, int i, int j, int l, int r){
	if(r < i || j < l) return OUT;
	
	if(l <= i && j <= r) return st[u];
	
	int lans = query(left(u), i, mid(i, j), l, r);
	int rans = query(right(u), mid(i, j) + 1, j, l, r);

	if(lans == OUT) return rans;
	if(rans == OUT) return lans;
	
	return lans + rans;
}

void update(int u, int l, int r, int index, int value){
	if(l == r && index == l){
		st[u] = v[index] = value;
	}
	else{
		if(index <= mid(l, r)){
			update(left(u), l, mid(l, r), index, value);
		}
		else{
			update(right(u), mid(l,r)+1, r, index, value);
		}
		
		st[u] = st[left(u)] + st[right(u)];
	}
}

//churrascaria da avenida

int main(){_

	int n, q, r, l;
	int op, index, value;
	
	cin >> n;
	
	for(int i=1; i<=n; ++i){
		cin >> v[i];
	}
	
	build(1, 1, n);
	cin >> q;
	
	while(q--){
		cin >> op;
		
		if(op == 1){
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << endl;
		}
		else if(op == 2){
			cin >> index >> value;
			update(1, 1, n, index, value);
		}
		
	}
	
	

	return 0;
}

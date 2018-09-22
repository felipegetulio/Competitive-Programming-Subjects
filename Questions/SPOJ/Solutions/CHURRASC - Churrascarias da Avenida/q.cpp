#include<bits/stdc++.h>
#define MAXN 100005
#define ii pair<int, int>
#define _a first
#define _b second

#define _ ios_base::sync_with_stdio(0);
using namespace std;

struct MinQueue{
	deque<ii> deq;
	
	void push(ii n){
		while(!deq.empty() && deq.front()._b >= n._b){
			deq.pop_front();
		}
		deq.push_front(n);
	}
	
	ii top(int index){
		while(!deq.empty() && deq.back()._a < index){
			deq.pop_back();
		}
		return deq.back();
	}
	
	void pop(){
		deq.pop_back();
	}
	
	void clear(){
		deq.clear();
	}
};


int v[MAXN];
MinQueue mq;


int main(){_
	
	int n, k;
	
	while((cin >> n >> k) && (n || k)){
	
		mq.clear();
		
		for(int i=0; i<n; ++i){
			cin >> v[i];
		}
		
		for(int i=0; i<k; ++i){
			mq.push(ii(i, v[i]));
		}
		
		cout << mq.top(0)._b;
		
		for(int i=k; i<n; ++i){
			mq.push(ii(i, v[i]));
			cout << ' ' << mq.top(i-k+1)._b;
		}
		
		cout << endl;
	}


	return 0;
}

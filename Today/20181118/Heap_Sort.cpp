#include <cstdio>

struct Heap {
	bool (*_comp) (int, int);
	int N;
	int t[100000+5];
	void init(bool (*_cmp) (int, int)) {
		N=0;
		_comp=_cmp;
	}
	inline int top() {
		return t[1];
	}
	inline void push(int x) {
		int j=++N,i=j>>1;
		while(i>0) {
			if(_comp(x,t[i])) {
				t[j]=t[i];
				j=i;
				i>>=1;
			} else {
				break;
			}
		}
		t[j]=x;
	}
	inline void pop() {
		int x=t[N--],i=1,j=i<<1;
		while(j<=N) {
			if(_comp(x,t[j])&&_comp(x,t[j|1])) {
				break;
			} else if(_comp(t[j],t[j|1])) {
				t[i]=t[j];
				i=j;
			} else {
				t[i]=t[j|1];
				i=j|1;
			}
			j=i<<1;
		}
		t[i]=x;
	}
} a;

bool comp(int i1, int i2) {
	return i1<i2;
}

int main() {
	a.init(comp);
	int N,n,x;
	scanf("%d",&N);
	for(n=1;n<=N;n++) {
		scanf("%d",&x);
		a.push(x);
	}
	for(n=1;n<N;n++) {
		printf("%d ",a.top());
		a.pop();
	}
	printf("%d\n",a.top());
	return 0;
}

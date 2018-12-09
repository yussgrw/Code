#include <cstdio>

struct priority_queue {
	int T;
	int t[100000+5];
	bool (*_comp) (int, int);

	inline void push(int *x) {
		register int i,j;
		j=++T;
		i=j>>1;
		while(i) {
			if(!_comp(t[i],*x)) {
				t[j]=t[i];
				j=i;
				i=j>>1;
			} else {
				break;
			}
		}
		t[j]=*x;
	}

	inline int top() {
		return t[1];
	}

	inline void pop() {
		register int i=1,j;
		int x=t[T--];
		j=i<<1;
		while(j<=T) {
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
};

inline bool comp(int x, int y) {
	return x<=y;
}

int main() {
	priority_queue q;
	q.T=0;
	q._comp=comp;
	int N;
	int n;
	int tmp;
	scanf("%d",&N);
	for(n=1;n<=N;n++) {
		scanf("%d",&tmp);
		q.push(&tmp);
	}
	for(n=1;n<N;n++) {
		printf("%d ",q.top());
		q.pop();
	}
	printf("%d\n",q.top());
	return 0;
}

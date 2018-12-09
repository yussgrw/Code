#include <cstdio>

int lowbit(int x) {
	return -x&x;
}

int get(int x) {
	int res=0;
	while(x>0) {
		x-=lowbit(x);
		res++;
	}
	return res;
}

int main() {
	int N,K,res=0;
	scanf("%d%d",&N,&K);
	while(get(N)>K) {
		res+=lowbit(N);
		N+=lowbit(N);
	}
	printf("%d\n",res);
	return 0;
}

#include <cstdio>

int N,ans=0;
int res[15];

void print() {
	int n;
	for(n=1;n<N;n++) {
		printf("%d ",__builtin_ffs(res[n]));
	}
	printf("%d\n",__builtin_ffs(res[N]));
}

void dfs(int depth, int col, int cos1, int cos2) {
	if(col==((1<<N)-1)) {
		ans++;
		if(ans<4) {
			print();
		}
		return;
	}
	int pos=((1<<N)-1)&(~col)&(~cos1)&(~cos2);
	int a;
	while(pos) {
		a=-pos&pos;
		res[depth]=a;
		dfs(depth+1,col|a,(cos1|a)<<1,(cos2|a)>>1);
		pos=pos&(~a);
	}
}

int main() {
	scanf("%d",&N);
	dfs(1,0,0,0);
	printf("%d\n",ans);
	return 0;
}

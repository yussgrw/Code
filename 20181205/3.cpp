#include <cstdio>

int a[10],b[10],N;

struct node {
	int lc,rc;
} t[30];

void read(int* num) {
	char c=getchar();
	int n=1;
	while(c<'A'||c>'Z') {
		c=getchar();
	}
	while(c>='A'&&c<='Z') {
		num[n++]=c-'A'+1;
		c=getchar();
	}
	N=n-1;
}

int build(int l1, int r1, int l2, int r2) {
//	printf("%d %d %d %d\n",l1,r1,l2,r2);
	if(r1==l1) {
		return a[l1];
	}
	if(l1>N||r1>N||l2>N||r2>N) {
		return 0;
	}
	if(l1<1||r1<1||l2<1||r2<1) {
		return 0;
	}
	if(l1>r1||l2>r2) {
		return 0;
	}
	int mid;
	for(mid=l1;a[mid]!=b[r2];mid++);
	t[b[r2]].lc=build(l1,mid-1,l2,l2+mid-l1-1);
	t[b[r2]].rc=build(mid+1,r1,r2-r1+mid,r2-1);
	return a[mid];
}

void search(int n) {
	if(n<1) {
		return ;
	}
	putchar(n+'A'-1);
	search(t[n].lc);
	search(t[n].rc);
}

int main() {
	read(a);
	read(b);
	build(1,N,1,N);
	search(b[N]);
	putchar('\n');
	return 0;
}

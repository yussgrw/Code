#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct {
	int num;
	int v;
} matter;
matter thing[100000+5];

int c[(1<<20)+5]={0};
int N,M;

inline int lowbit(int x) {
	return -x&x;
}

void plus(int p, int x) {
	while(p<=(1<<N)) {
		c[p]+=x;
		p+=lowbit(p);
	}
}

int get(int p) {
	int res=0;
	while(p>0) {
		res+=c[p];
		p-=lowbit(p);
	}
	return res;
}

void plus2(int l, int r, int x) {
	plus(l,x);
	plus(r+1,-x);
}

int readin() {
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') {
		c=getchar();
	}
	while(c>='0'&&c<='1') {
		x=(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}

bool comp(matter m1, matter m2) {
	return m1.num<=m2.num;
}

void run(int n) {
	int i=1,j;
	int a=thing[n].num;
	while(true) {
		while((a&(1<<(i-1)))!=0) {
			i++;
		}
		j=i+1;
		if((1<<(j-1))>a) {
			j=N+1;
		} else {
			while((a&(1<<(j-1)))!=1) {
				j++;
			}
		}
		plus2((1<<(i-1))+a,a|((1<<(j-1))-1),thing[n].v);
		i++;
	}
}

int b[(1<<20)+5]={0};

void run2(int n) {
	int a=n;
	for(a++;a<=(1<<N)-1;a++) {
		if((a&n)==n) {
			b[a]+=b[n];
		}
	}
}

int main() {
	scanf("%d%d",&N,&M);
	int m;
	int i,j;
	for(m=1;m<=M;m++) {
		i=readin();
		scanf("%d",&j);
		b[i]=j*i;
	}
	for(m=1;m<(1<<N)-1;m++) {
		run2(m);
	}
//	printf("%d\n",get((1<<N)-1));
	int res=0;
	int n;
	for(n=0;n<(1<<N)-1;n++) {
		res+=b[n];
	}
	res+=b[(1<<N)-1]*((1<<N)-2);
	printf("%d\n",b[(1<<N)-1]);
	return 0;
}

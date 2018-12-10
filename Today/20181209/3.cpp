#include <cstdio>
#include <algorithm>
using namespace std;

bool vis[100000+5]={false};
int N,nex[100000+5]={0},res[100000+5]={0};
long long a[100000+5];

inline int find(long long x) {
	int l=1,r=N,mid;
	while(l<r) {
		mid=(l+r)>>1;
		if(a[mid+1]==x) {
			return mid+1;
		} else if(a[mid+1]<x) {
			l=mid+1;
		} else {
			r=mid;
		}
	}
	if(a[l]==x) {
		return l;
	} else {
		return 0;
	}
}

void read() {
	scanf("%d",&N);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%lld",&a[n]);
	}
	sort(a+1,a+1+N);
	vis[0]=true;
}

int dfs(int x) {
	if(x==0) {
		return 0;
	}
	int i,j,res1=0,res2=0;
	if(!(a[x]%3)) {
		j=find(a[x]/3);
		if(vis[j]) {
			res2=res[j];
		} else {
			res2=dfs(j);
		}
	}
	i=find(a[x]*2);
	if(vis[i]) {
		res1=res[i];
	} else {
		res1=dfs(i);
	}
	vis[x]=true;
	if(res1==0&&res2==0) {
		res[x]=1;
	} else if(res1==0) {
		res[x]=res2+1;
		nex[x]=j;
	} else if(res2==0) {
		res[x]=res1+1;
		nex[x]=i;
	} else {
		if(res1>res2) {
			res[x]=res1+1;
			nex[x]=i;
		} else {
			res[x]=res2+1;
			nex[x]=j;
		}
	}
	return res[x];
}

int main() {
	read();
	int n;
	int maxx=0,maxn;
	int ret;
	for(n=1;n<=N;n++) {
		if(!vis[n]) {
			ret=dfs(n);
		}
		if(ret>maxx) {
			maxn=n;
			maxx=ret;
		}
	}
	printf("%d\n",maxx);
	for(n=maxn;n!=0;n=nex[n]) {
		printf("%lld ",a[n]);
	}
	putchar('\n');
	return 0;
}

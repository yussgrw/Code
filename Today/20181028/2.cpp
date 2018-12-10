#include <cstdio>

int L,N,M;
int a[50000+5]={0};

int dfs(int now, int l) {
	if(now==(N+1)) {
		return 0;
	}
	int i,tmp,result=-1;
	for(i=now+1;i<=N+1;i++) {
		if((a[i]-a[now])>=l) {
			tmp=dfs(i,l);
			if(tmp>-1) {
				tmp=tmp+i-now-1;
				if(result==-1) {
					result=tmp;
				} else {
					result=result>tmp?tmp:result;
				}
			}
		}
	}
	return result;
}

int main() {
	scanf("%d%d%d",&L,&N,&M);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%d",&a[n]);
	}
	a[N+1]=L;
	int l=1,r=1000000000,mid,tmp;
	while(l<r) {
		mid=(l+r)/2;
		tmp=dfs(0,mid+1);
		printf("%d %d\n",mid+1,tmp);
		if(tmp==-1||tmp>M) {
			r=mid;
		} else {
			l=mid+1;
		}
	}
	printf("%d\n",l);
	return 0;
}

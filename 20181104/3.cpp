#include <cstdio>

int L,N,M;
int a[50000+5]={0};

int judge(int x) {
	int i=0,dis=0,cnt=0;
	while(true) {
		dis+=x;
		while(a[i]<dis) {
			i++;
			cnt++;
		}
		cnt--;
		if(a[i]==L) {
			break;
		}
		if((L-a[i])<x) {
			dis=L-x;
			cnt++;
		} else {
			dis=a[i];
		}
	}
	if(cnt>M) {
		return 0;
	} else {
		return 1;
	}
}

int main() {
	scanf("%d%d%d",&L,&N,&M);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%d",&a[n]);
	}
	a[0]=0;
	a[N+1]=L;
	int l=1,r=L,mid;
	while(l<r) {
		mid=(l+r)/2;
		if(judge(mid+1)==1) {
			l=mid+1;
		} else {
			r=mid;
		}
	}
	printf("%d\n",l);
	return 0;
}

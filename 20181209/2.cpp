#include <cstdio>

long long a[1000000+5],z[1000000+5]={0};
int N;
bool pd[1000000+5]={false};

int main() {
	scanf("%d",&N);
	int n;
	long long cnt,res=0;
	for(n=1;n<=N;n++) {
		scanf("%lld",&a[n]);
		z[n]=a[n]+z[n-1];
	}
	for(n=1;n<=N;n++) {
		if(a[n]*(N-n)>z[N]-z[n]) {
			pd[n]=true;
		}
	}
	cnt=0;
	for(n=1;n<=N;n++) {
		if(!pd[n]) {
			res+=(++cnt)*a[n];
		}
	}
	for(n=N;n>0;n--) {
		if(pd[n]) {
			res+=(++cnt)*a[n];
		}
	}
	printf("%lld\n",res);
	cnt=0;
	for(n=1;n<=N;n++) {
		if(!pd[n]) {
			cnt++;
			if(cnt<N) {
				printf("%lld ",a[n]);
			} else {
				printf("%lld\n",a[n]);
			}
		}
	}
	for(n=N;n>0;n--) {
		if(pd[n]) {
			cnt++;
			if(cnt<N) {
				printf("%lld ",a[n]);
			} else {
				printf("%lld\n",a[n]);
			}
		}
	}
	return 0;
}

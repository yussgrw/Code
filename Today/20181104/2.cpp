#include <cstdio>
#include <algorithm>
using namespace std;

long long a[300+5];
int N;

int main() {
	scanf("%d",&N);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%lld",&a[n]);
	}
	sort(a+1,a+N+1);
	long long res=a[N]*a[N];
	int i=1,j=N;
	int now=j;
	while(i<j) {
		if(now==j) {
			res+=(a[now]-a[i])*(a[now]-a[i]);
			j--;
			now=i;
		} else {
			res+=(a[j]-a[now])*(a[j]-a[now]);
			i++;
			now=j;
		}
	}
	printf("%lld\n",res);
	return 0;
}

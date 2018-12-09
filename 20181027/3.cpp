#include <cstdio>

int a[1000+5],f[1000+5][50000+5]={0};
const int p=25000,P=998244353;

int main() {
	int N,n,tmp,i,result=0;
	scanf("%d",&N);
	for(n=1;n<=N;n++) {
		scanf("%d",&a[n]);
	}
	for(n=1;n<=N;n++) {
		result ++;
		for(i=1;i<n;i++) {
			tmp=a[n]-a[i]+p;
			f[n][tmp]=(f[n][tmp]+f[i][tmp]+1)%P;
			result=(result+f[i][tmp]+1)%P;
		}
	}
	printf("%d\n",result);
	return 0;
}

#include <cstdio>

int a[50000+5],f[50000+5][100+5];
int N,C,MAX;

int max(int x, int y) {
	return x>y?x:y;
}

int min(int x, int y) {
	return x<y?x:y;
}

int abs(int x) {
	return x<0?-x:x;
}

int read() {
	char c=getchar();
	if(c==EOF) {
		return 1;
	}
	while(c<'0'||c>'9') {
		c=getchar();
		if(c==EOF) {
			return 1;
		}
	}
	N=0;
	while(c>='0'&&c<='9') {
		N=N*10+c-'0';
		c=getchar();
	}
	scanf("%d",&C);
	int n;
	MAX=0;
	for(n=1;n<=N;n++) {
		scanf("%d",&a[n]);
		MAX=max(MAX,a[n]);
	}
	return 0;
}

void dp() {
	int i,j,k;
	for(j=a[1];j<=MAX;j++) {
		f[1][j]=(j-a[1])*(j-a[1]);
	}
	for(i=1;i<=N;i++) {
		for(j=a[i];j<=MAX;j++) {
			f[i][j]=0x7fffffff;
			for(k=a[i-1];k<=MAX;k++) {
				f[i][j]=min(f[i][j],f[i-1][k]+C*abs(k-j)+(j-a[i])*(j-a[i]));
			}
		}
	}
	i=0x7fffffff;
	for(j=a[N];j<=MAX;j++) {
		i=min(i,f[N][j]);
	}
	printf("%d\n",i);
}

int main() {
	while(!read()) {
		dp();
	}
	return 0;
}

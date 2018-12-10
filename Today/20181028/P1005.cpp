#include <cstdio>

__int128 a[100];
__int128 f[100][100]={0};
int N,M;

__int128 max(__int128 i1, __int128 i2) {
	return i1>i2?i1:i2;
}

void readin(__int128 *x) {
	*x=0;
	char c=getchar();
	while(c<'0'||c>'9') {
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		*x=*x*10+c-'0';
		c=getchar();
	}
}

void print(__int128 x) {
	if(x>9) {
		print(x/10);
	}
	putchar(x%10+'0');
}

int main() {
	scanf("%d%d",&M,&N);
	int m,n;
	__int128 result=0;
	for(m=1;m<=M;m++) {
		for(n=1;n<=N;n++) {
			readin(&a[n]);
		}
		int i,j;
		__int128 p=1;
		for(i=1;i<=N;i++) {
			p<<=1;
			f[0][i]=f[0][i-1]+a[N-i+1]*p;
			f[i][0]=f[i-1][0]+a[i]*p;
			for(j=1;j<i;j++) {
				f[j][i-j]=max(f[j][i-j-1]+a[N-i+j+1]*p,f[j-1][i-j]+a[j]*p);
			}
		}
		__int128 max=0;
		for(i=0;i<=N;i++) {
			max=max>f[i][N-i]?max:f[i][N-i];
		}
		result+=max;
	}
	print(result);
	putchar('\n');
	return 0;
}

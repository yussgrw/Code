#include <cstdio>
#include <cstdlib>

int a[1000+5][1000+5];
int f[1000+5][1000+5][2];
int N;

void read() {
	scanf("%d",&N);
	int n,m;
	for(n=1;n<=N;n++) {
		for(m=1;m<=n;m++) {
			scanf("%d",&a[n][m]);
			f[n][m][1]=a[n][m];
		}
	}
}

int run() {
	int n,m=1;
	int res=0;
	for(n=1;n<=N;n++) {
		res+=a[n][m];
		if(rand()%2) {
			m++;
		}
	}
	return res;
}

void dp() {
	int n,m;
	for(n=N-1;n>0;n--) {
		for(m=1;m<=n;m++) {
			if(f[n+1][m][1]>f[n+1][m+1][1]) {
				f[n][m][1]+=f[n+1][m][1];
				f[n][m][0]=0;
			} else {
				f[n][m][1]+=f[n+1][m+1][1];
				f[n][m][0]=1;
			}
		}
	}
}

void print() {
	printf("%d\n",f[1][1][1]);
	int n,m=1;
	for(n=1;n<N;n++) {
		printf("%d ",a[n][m]);
		if(f[n][m][0]) {
			m++;
		}
	}
	printf("%d\n",a[n][m]);
}

int main() {
	read();
	dp();
	print();
	return 0;
}

#include <cstdio>

int num[10][5][3]={
	1,1,1,
	1,0,1,
	1,0,1,
	1,0,1,
	1,1,1,

	1,0,0,
	1,0,0,
	1,0,0,
	1,0,0,
	1,0,0,

	1,1,1,
	0,0,1,
	1,1,1,
	1,0,0,
	1,1,1,

	1,1,1,
	0,0,1,
	1,1,1,
	0,0,1,
	1,1,1,

	1,0,1,
	1,0,1,
	1,1,1,
	0,0,1,
	0,0,1,

	1,1,1,
	1,0,0,
	1,1,1,
	0,0,1,
	1,1,1,

	1,1,1,
	1,0,0,
	1,1,1,
	1,0,1,
	1,1,1,

	1,1,1,
	0,0,1,
	0,0,1,
	0,0,1,
	0,0,1,

	1,1,1,
	1,0,1,
	1,1,1,
	1,0,1,
	1,1,1,

	1,1,1,
	1,0,1,
	1,1,1,
	0,0,1,
	1,1,1};
int a[15][100000+5];
int N,M;

void read() {
	scanf("%d%d",&N,&M);
	int n,m;
	char c;
	for(n=1;n<=N;n++) {
		m=0;
		c=getchar();
		while(true) {
			while(c!='.'&&c!='#') {
				c=getchar();
			}
			if(c=='.') {
				a[n][++m]=0;
			} else {
				a[n][++m]=1;
			}
			c=getchar();
			if(m==M) {
				break;
			}
		}
	}
}

int force(int n, int m) {
//	printf("%d %d ",n,m);
	int x,y,k;
	bool flag;
	for(k=0;k<10;k++) {
		if(k==1) {
			continue;
		}
		flag=true;
		for(x=0;x<5;x++) {
			for(y=0;y<3;y++) {
				if(a[n+x][m+y]!=num[k][x][y]) {
					flag=false;
					break;
				}
			}
			if(!flag) {
				break;
			}
		}
		if(flag) {
			return k;
		}
	}
	y=m;
	flag=true;
	for(x=n;x<n+5;x++) {
		if(a[x][y]==0) {
			flag=false;
			break;
		}
	}
	if(flag) {
		return 1;
	}
	return -1;
}

int main() {
	read();
	int i,j,ret;
	for(j=1;j<=M;j++) {
		for(i=1;i<=N;i++) {
			ret=force(i,j);
			if(ret!=-1) {
				if(ret==1) {
					j++;
				} else {
					j+=3;
				}
				putchar(ret+'0');
				break;
			}
		}
	}
	putchar('\n');
	return 0;
}

//P2704
#include <cstdio>

int N,M;
int a[100+5];
bool s[1<<11];
int f[100+5][1<<11]={0};
int g[1<<11];

void read() {
	scanf("%d%d",&N,&M);
	int n,i,j,flag,last,cnt;
	char c=getchar();
	for(n=1;n<=N;n++) {
		a[n]=0;
		while(!(c=='P'||c=='H')) {
			c=getchar();
		}
		while(c=='P'||c=='H') {
			a[n]<<=1;
			if(c=='P') {
				a[n]++;
			}
			c=getchar();
		}
	}
	for(i=0;i<(1<<M);i++) {
		s[i]=true;
		j=i;
		flag=0;
		n=1;
		cnt=0;
		while(j) {
			if(j&1) {
				cnt++;
				if(flag) {
					if((n-last)<3) {
						s[i]=false;
						break;
					}
				}
				flag=1;
				last=n;
			}
			j>>=1;
			n++;
		}
		if(s[i]) {
			g[i]=cnt;
//			printf("%d %d\n",i,g[i]);
		}
		if(s[i]&&((i|a[1])==a[1])) {
			f[1][i]=g[i];
		}
	}
}

int max(int x, int y) {
	return x>y?x:y;
}

void dp2() {
	int n,i,j,k;
	int pos,pos2;
}

void dp() {
	int n,i,j,k;
	int pos,pos2;
	for(n=2;n<=N;n++) {
		for(i=a[n];i;i=a[n]&(i-1)) {
			if(s[i]) {
				pos=((1<<M)-1)&(~i);
				for(j=pos;j;j=pos&(j-1)) {
					if(s[j]&&((j|a[n-1])==a[n-1])) {
						pos2=((1<<M)-1)&(~i)&(~j);
						for(k=pos2;k;k=pos2&(k-1)) {
							if(s[k]&&((k|a[n-2])==a[n-2])) {
								f[n][i]=max(f[n][i],f[n-2][k]+g[i]+g[j]);
							}
						}
						if(s[k]&&((k|a[n-2])==a[n-2])) {
							f[n][i]=max(f[n][i],f[n-2][k]+g[i]+g[j]);
						}
					}
				}
				if(s[j]&&((j|a[n-1])==a[n-1])) {
					pos2=((1<<M)-1)&(~i)&(~j);
					for(k=pos2;k;k=pos2&(k-1)) {
						if(s[k]&&((k|a[n-2])==a[n-2])) {
							f[n][i]=max(f[n][i],f[n-2][k]+g[i]+g[j]);
						}
					}
					if(s[k]&&((k|a[n-2])==a[n-2])) {
						f[n][i]=max(f[n][i],f[n-2][k]+g[i]+g[j]);
					}
				}
			}
			printf("f[%d][%d]=%d\n",n,i,f[n][i]);
		}
		if(s[i]) {
			pos=((1<<M)-1)&(~i);
			for(j=pos;j;j=pos&(j-1)) {
				if(s[j]&&((j|a[n-1])==a[n-1])) {
					pos2=((1<<M)-1)&(~i)&(~j);
					for(k=pos2;k;k=pos2&(k-1)) {
						if(s[k]&&((k|a[n-2])==a[n-2])) {
							f[n][i]=max(f[n][i],f[n-2][k]+g[i]+g[j]);
						}
					}
					if(s[k]&&((k|a[n-2])==a[n-2])) {
						f[n][i]=max(f[n][i],f[n-2][k]+g[i]+g[j]);
					}
				}
			}
			if(s[j]&&((j|a[n-1])==a[n-1])) {
				pos2=((1<<M)-1)&(~i)&(~j);
				for(k=pos2;k;k=pos2&(k-1)) {
					if(s[k]&&((k|a[n-2])==a[n-2])) {
						f[n][i]=max(f[n][i],f[n-2][k]+g[i]+g[j]);
					}
				}
				if(s[k]&&((k|a[n-2])==a[n-2])) {
					f[n][i]=max(f[n][i],f[n-2][k]+g[i]+g[j]);
				}
			}
		}
		printf("f[%d][%d]=%d\n",n,i,f[n][i]);
	}
	int res=0;
	for(i=a[N];i;i=a[N]&(i-1)) {
		res=max(res,f[N][i]);
	}
	res=max(res,f[N][i]);
	printf("%d\n",res);
}

int main() {
	read();
	dp();
	return 0;
}

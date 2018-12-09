#include <cstdio>

int s[1100]={0};
long long f[10][100][600]={0};
int N,M;

void init() {
	scanf("%d%d",&N,&M);
	int i,flag,tmp,cnt;
	for(i=1;i<(1<<9);i++) {
		flag=1;
		tmp=i;
		cnt=0;
		while(tmp) {
			if(tmp&1) {
				cnt++;
			} else {
				cnt=0;
			}
			if(cnt>1) {
				flag=0;
				break;
			}
			tmp>>=1;
		}
		s[i]=flag;
	}
	s[0]=1;
}

int pd(int i, int j) {
	return (i&j)?0:s[i+j];
}

int count(int x) {
	int cnt=0;
	while(x) {
		cnt++;
		x=x&(x-1);
	}
	return cnt;
}

void dp() {
	int n,i,cnt,j,m;
	for(i=0;i<(1<<N);i++) {
		if(s[i]) {
			f[1][count(i)][i]=1;
		}
	}
	for(n=2;n<=N;n++) {
		for(i=0;i<(1<<N);i++) {
			if(s[i]) {
				cnt=count(i);
				for(m=cnt;m<=M;m++) {
					for(j=0;j<(1<<N);j++) {
						if(s[j]) {
							if(pd(i,j)) {
								f[n][m][i]+=f[n-1][m-cnt][j];
							}
						}
					}
	//				printf("f[%d][%d][%d]=%d\n",n,m,i,f[n][m][i]);
				}
			}
		}
	}
	long long res=0;
	for(i=0;i<(1<<N);i++) {
		res+=f[N][M][i];
	}
	printf("%lld\n",res);
}

int main() {
	init();
	dp();
	return 0;
}

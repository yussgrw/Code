//P2704
#include <cstdio>
#include <memory.h>

int N,M;
int a[100+5];
bool s[1<<11];
int arr1[1<<11][1<<11],arr2[1<<11][1<<11];
int g[1<<11];

void read() {
	scanf("%d%d",&N,&M);
	int n,i,j,flag,last,cnt;
	char c=getchar();
	a[0]=0;
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
		}
	}
}

inline int max(int x, int y) {
	return x>y?x:y;
}

inline bool pd(int *i, bool *flag) {
	if(*flag) {
		if(*i==0) {
			*flag=false;
			return true;
		}
	}
	return *flag;
}

void dp() {
	int n,i,j,k;
	int pos,pos2;
	int (*f1)[1<<11],(*f2)[1<<11];
	f1=arr1;
	f2=arr2;
	int (*tmp)[1<<11];
	bool flag,flag2,flag3;
	for(i=a[1],flag=true;pd(&i,&flag);i=a[1]&(i-1)) {
		f1[i][0]=g[i];
	}
	for(n=2;n<=N;n++) {
		if(n%2) {
			memset(arr1,0,sizeof(arr1));
		} else {
			memset(arr2,0,sizeof(arr2));
		}
		for(i=a[n],flag=true;pd(&i,&flag);i=a[n]&(i-1)) {
			if(s[i]) {
				pos=((1<<M)-1)&(~i);
				for(j=pos,flag2=true;pd(&j,&flag2);j=pos&(j-1)) {
					if(s[j]&&((j|a[n-1])==a[n-1])) {
						pos2=pos&(~j);
						for(k=pos2,flag3=true;pd(&k,&flag3);k=pos2&(k-1)) {
							if(s[k]&&((k|a[n-2])==a[n-2])) {
								f2[i][j]=max(f2[i][j],f1[j][k]+g[i]);
							}
						}
					}
				}
			}
		}
		tmp=f1;
		f1=f2;
		f2=tmp;
	}
	int res=0;
	for(i=a[N],flag=true;pd(&i,&flag);i=a[N]&(i-1)) {
		if(s[i]) {
			pos=((1<<M)-1)&(~i);
			for(j=pos,flag2=true;pd(&j,&flag2);j=pos&(j-1)) {
				if(s[j]&&((j|a[N-1])==a[N-1])) {
					res=max(res,f1[i][j]);
				}
			}
		}
	}
	printf("%d\n",res);
}

int main() {
	read();
	dp();
	return 0;
}

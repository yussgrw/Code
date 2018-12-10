#include <cstdio>

int a[100000+5],N;

void read() {
	scanf("%d",&N);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%d",&a[n]);
	}
}

int dfs(int l, int r, int n) {
	if(l==r) {
		return a[l]-n;
	}
	int min=0x7ffffff;
	int i,j;
	for(i=l;i<=r;i++) {
		min=a[i]<min?a[i]:min;
	}
	j=l-1;
	i=j+1;
	int res=min-n;
	while(i<=r&&j<=r) {
		i=j+1;
		while((a[i]-min)==0) {
			i++;
			if(i>r) {
				break;
			}
		}
		if(i>r) {
			break;
		}
		j=i;
		while((a[j]-min)!=0) {
			j++;
			if(j>r) {
				break;
			}
		}
		res+=dfs(i,j-1,min);
	}
	return res;
}		

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read();
	printf("%d\n",dfs(1,N,0));
	return 0;
}

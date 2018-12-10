#include <cstdio>

int a[1000000+5],b[1000000+5];
int N;

inline void readin(int *x) {
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

void read() {
	scanf("%d",&N);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%d",a+n);
	}
}

void write(int x) {
	if(x>9) {
		write(x/10);
	}
	putchar(x%10+'0');
}

void print() {
	int n;
	for(n=1;n<N;n++) {
		printf("%d ",a[n]);
	}
	printf("%d\n",a[N]);
}

void msort(int l, int r, bool (*_comp) (int, int)) {
	if(l==r) {
		return ;
	} else if(r-l==1) {
		if(!_comp(a[l],a[r])) {
			int tmp=a[l];
			a[l]=a[r];
			a[r]=tmp;
		}
	} else {
		int mid=(l+r)/2;
		msort(l,mid,_comp);msort(mid+1,r,_comp);
		int i=l,j=mid+1,k;
		for(k=l;k<=r;k++) {
			if(i>mid) {
				b[k]=a[j++];
			} else if(j>r) {
				b[k]=a[i++];
			} else if(!_comp(a[i],a[j])) {
				b[k]=a[j++];
			} else {
				b[k]=a[i++];
			}
		}
		for(k=l;k<=r;k++) {
			a[k]=b[k];
		}
	}
}

bool comp(int i1, int i2) {
	return i1<=i2;
}

int main() {
	read();
	msort(1,N,comp);
	print();
	return 0;
}

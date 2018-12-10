#include <cstdio>

int a[1000000+5]={0},b[1000000+5]={0};
int N;

int readin() {
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') {
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

void read() {
	N=readin();
	int n;
	for(n=1;n<=N;n++) {
		a[n]=readin();
	}
}

void write(int n) {
	if(n>9) {
		write(n/10);
	}
	putchar(n%10+'0');
}

void print() {
	int n;
	for(n=1;n<=N;n++) {
		write(a[n]);
		putchar(' ');
	}
	putchar('\n');
}

void msort(int l, int r, bool (*_comp) (int, int)) {
	if(r==l) {
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
	return i1>=i2;
}

int main() {
	read();
	msort(1,N,comp);
	print();
	return 0;
}

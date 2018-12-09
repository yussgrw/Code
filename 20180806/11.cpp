#include <cstdio>
#include <thread>
using namespace std;

int a[10000000+5],b[10000000+5];
int N;

FILE *fin,*fout;

inline int readin() {
	register int x=0;
	register char c=fgetc(fin);
	while(c<'0'||c>'9') {
		c=fgetc(fin);
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=fgetc(fin);
	}
	return x;
}

inline void read() {
	N=readin();
	register int n;
	for(n=1;n<=N;n++) {
		a[n]=readin();
	}
}

inline void write(int x) {
	if(x>9) {
		write(x/10);
	}
	fputc(x%10+'0',fout);
//	putchar(x%10+'0');
}

inline void print() {
	register int n;
	for(n=1;n<N;n++) {
		write(a[n]);
		fputc(' ',fout);
	}
	write(a[N]);
	fputc('\n',fout);
}

void msort(int l, int r, bool (*_comp) (int*, int*)) {
	if(l==r) {
		return ;
	} else if(r-l==1) {
		if(!_comp(&a[l],&a[r])) {
			int tmp=a[l];
			a[l]=a[r];
			a[r]=tmp;
		}
	} else {
		int mid=(l+r)/2;
		thread th1,th2;
		th1=thread(msort,1,mid,_comp);th2=thread(msort,mid+1,r,_comp);
		th1.join();
		th2.join();
//		msort(l,mid,_comp);msort(mid+1,r,_comp);
		register int k,i=l,j=mid+1;
		for(k=l;k<=r;k++) {
			if(i>mid) {
				b[k]=a[j++];
			} else if (j>r) {
				b[k]=a[i++];
			} else if(!_comp(&a[i],&a[j])) {
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

bool comp(int *i1, int *i2) {
	return *i1>=*i2;
}

/*void run() {
	if(N<9) {
		msort(1,N,comp);
	} else {
		int n=N/8;
		int i;
		thread threads[8];
		for(i=0;i<7;i++) {
			threads[i]=thread(msort,n*i+1,n*(i+1),comp);
		}
		threads[7]=thread(msort,7*n+1,N,comp);
		for(i=0;i<7;i++) {
			threads[i].join();
		}
*/	

int main() {
	fin=fopen("sort.in","r");
	fout=fopen("sort.out","w");
	read();
	msort(1,N,comp);
	print();
	return 0;
}

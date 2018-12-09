#include <cstdio>

int N,a[1000000+5];

void readin(int *x) {
	char c=getchar();
	int sym=1;
	while(c>'9'||c<'0') {
		if(c=='-') {
			sym=-1;
			c=getchar();
			break;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		*x=*x*10+c-'0';
		c=getchar();
	}
	*x*=sym;
}

void read() {
	readin(&N);
	int n;
	for(n=1;n<=N;n++) {
		readin(&a[n]);
	}
}

void run() {
	int min=a[1];
	int max=a[2]-a[1];
	int n;
	for(n=2;n<=N;n++) {
		max=(a[n]-min)>max?(a[n]-min):max;
		min=min<a[n]?min:a[n];
	}
	printf("%d\n",max);
}

int main() {
	read();
	run();
	return 0;
}

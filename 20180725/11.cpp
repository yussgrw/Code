#include <cstdio>

inline int read() {
	register int x=0;
	register char c=getchar();
	int sym=1;
	while(c<'0'||c>'9') {
		if(c=='-') {
			sym=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sym;
}

inline void write(int x) {
	if(x>9) {
		write(x/10);
	}
	putchar(x%10+'0');
}

int main() {
	int n;
	n=read();
	int N;
	int a,b;
	int c;
	for(N=1;N<=n;N++) {
		a=read();b=read();
		c=a+b;
		if(c<0) {
			putchar('-');
			write(-c);
		} else {
			write(c);
		}
		putchar('\n');
	}
	return 0;
}

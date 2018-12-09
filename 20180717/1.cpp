#include <cstdio>
#include <cstring>
using namespace std;

char numa[550],numb[550];
int a[550],b[550],c[550];

int main() {
	scanf("%s%s",numa,numb);
	int len1=strlen(numa),len2=strlen(numb);
	int i;
	for(i=1;i<=len1;i++) {
		a[len1-i+1]=numa[i-1]-'0';
	}
	for(i=1;i<=len2;i++) {
		b[len2-i+1]=numb[i-1]-'0';
	}
	int len=len1>len2?len1:len2;
	int x=0;

	for(i=1;i<=len;i++) {
		c[i]=a[i]+b[i]+x;
		x=c[i]/10;
		c[i]%=10;
	}
	if(x==1) {
		len++;
		c[len]=x;
	}
	for(i=len;i>0;i--) {
		printf("%d",c[i]);
	}
	putchar('\n');
	return 0;
}

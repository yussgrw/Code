#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	char ch[13]="hello, world";
	int i;
	for(i=0;i<strlen(ch);i++) {
		printf("%d ",ch[i]);
	}
	putchar('\n');
	return 0;
}

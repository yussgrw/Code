#include <cstdio>

int main() {
	int a[3];
	while(true) {
		do {
			printf("Please input RGB in Oct:");
			scanf("%d%d%d",&a[0],&a[1],&a[2]);
		} while (a[0]<0||a[1]<0||a[2]<0||a[0]>255||a[1]>255||a[2]>255);
		printf("Hex Color:");
		int i;
		int x;
		for(i=0;i<3;i++) {
			x=a[i];
			if(x/16==0) {
				putchar('0');
			} else {
				if(x/16>9) {
					putchar(x/16-10+'a');
				} else {
					putchar(x/16+'0');
				}
			}
			x%=16;
				if(x>9) {
				putchar(x-10+'a');
			} else {
				putchar(x+'0');
			}
		}
		putchar('\n');
	}
	return 0;
}

#include <cstdio>

int N,B;
int a[25];

void read() {
	scanf("%d%d",&N,&B);
	int n;
	for(n=1;n<=N;n++) {
		scanf("%d",&a[n]);
	}
}

int search(int height, int last) {
	if(height>=B) {
		return height-B;
	} else {
		int i;
		int tmp;
		int min=-1;
		for(i=last+1;i<=N;i++) {
			tmp=search(height+a[i],i);
			if(tmp!=-1) {
				if(tmp<min||min==-1) {
					min=tmp;
				}
			}
		}
		return min;
	}
}

int main() {
	read();
	printf("%d\n",search(0,0));
	return 0;
}

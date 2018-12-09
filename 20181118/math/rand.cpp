#include <cstdio>
#include <ctime>
#include <cstdlib>

struct Edge {
	int from;
	int to;
	int type;
} t[100000+5];

int head[100000+5]={0},N,M,T;

void rnd(int *a, int *b) {
	*a=rand()%N+1;
	do {
		*b=rand()%N+1;
	} while(*a==*b);
}

void run() {
	srand(time(NULL));
	int ne;
	for(ne=1;ne<=T;ne++) {
		rnd(&t[ne].from,&t[ne].to);
		if((rand()%2)&&(rand()%2)&&(rand()%2)&&(rand()%2)&&(rand()%2)) {
			t[ne].type=3;
		} else {
			t[ne].type=rand()%2+1;
		}
	}
}

void print() {
	int a=1,b=1,x,y;
	while(a<=T||b<=(M-T)) {
//		printf("Mark 1 %d %d\n",a,b);
		if(a>T) {
			rnd(&x,&y);
			printf("2 %d %d\n",x,y);
			b++;
		} else if(b>(M-T)) {
			printf("1 %d %d %d\n",t[a].from,t[a].to,t[a].type);
			a++;
		} else {
			if(rand()%2||rand()%2||rand()%2) {
				printf("1 %d %d %d\n",t[a].from,t[a].to,t[a].type);
				a++;
			} else {
				rnd(&x,&y);
				printf("2 %d %d\n",x,y);
				b++;
			}
		}
	}
}

void print2() {
	int n,a,b;
	for(n=1;n<=T;n++) {
		printf("1 %d %d %d\n",t[n].from,t[n].to,t[n].type);
	}
	for(;n<=M;n++) {
		rnd(&a,&b);
		printf("2 %d %d\n",a,b);
	}
}

int main() {
	freopen("IN","r",stdin);
	scanf("%d%d%d",&N,&M,&T);
	printf("%d %d\n",N,M);
	run();
	print2();
	return 0;
}

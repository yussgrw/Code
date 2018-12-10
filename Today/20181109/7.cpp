#include <cstdio>
#include <vector>
using namespace std;

struct node {
	int num;
	vector<char> c;
} t[128];
int N,vis[128]={0};
char str1[1000],str2[1000];

void read() {
	scanf("%d",&N);
	getchar();
	getchar();
	int n;
	int c1,c2;
	for(n='A';n<='z';n++) {
		t[n].num=0;
	}
	for(n=1;n<=N;n++) {
		c1=getchar();
		c2=getchar();
		getchar();
		getchar();
		t[c1].num++;
		t[c1].c.push_back(c2);
		t[c2].num++;
		t[c2].c.push_back(c1);
	}
}

void dfs(int n, int depth,int frm,char* str) {
//	printf("%c %d %c\n",n,depth,frm);
	int i;
	str[depth]=n;
	char min=127;
	for(i=1;i<=t[n].num;i++) {
		if(t[n].c[i-1]!=frm&&vis[t[n].c[i-1]]<t[t[n].c[i-1]].num) {
			min=min<(t[n].c[i-1])?min:(t[n].c[i-1]);
		}
	}
	if(min==127) {
		return;
	} else {
		vis[min]++;
		dfs(min,depth+1,n,str);
		vis[min]--;
	}
}

void print(char* str) {
	int n;
	for(n=1;n<=N+1;n++) {
		putchar(str[n]);
	}
	putchar('\n');
}

void run() {
	char n1=0,n2=0;
	char n,min=127;
	for(n='A';n<='z';n++) {
		if(t[n].num==0) {
			continue;
		}
		min=min<n?min:n;
		if(t[n].num%2) {
			if(n1==0) {
				n1=n;
			} else if(n2==0) {
				n2=n;
			} else {
				printf("No Solution\n");
				return;
			}
		}
	}
	if(n1==0) {
		dfs(min,1,0,str1);
		print(str1);
		return;
	}
	vis[n1]++;
	dfs(n1,1,0,str1);
	vis[n1]--;
	vis[n2]++;
	dfs(n2,1,0,str2);
	vis[n2]--;
	for(n=1;n<=N+1;n++) {
		if(str1[n]<str2[n]) {
			print(str1);
			return;
		} else if(str1[n]>str2[n]) {
			print(str2);
			return;
		}
	}
	print(str1);
}

int main() {
	read();
	run();
	return 0;
}

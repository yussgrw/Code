#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef struct node;
typedef node* tree;

struct node {
	vector<tree> c;
	int num;
	int v;
	int n;
} t[300+5];
int N,dis[300+5][300+5]={0};

void read() {
	int n,x,y;
	scanf("%d%d",&N,&n);
	for(n=1;n<N;n++) {
		scanf("%d%d",&x,&y);
		dis[x][++dis[x][0]]=y;
		dis[y][++dis[y][0]]=x;
	}
	for(n=1;n<=N;n++) {
		t[n].num=0;
		t[n].n=n;
	}
}

int build(int n, int frm) {
	int m,ret=1;
	for(m=1;m<=dis[n][0];m++) {
		if(dis[n][m]!=frm) {
			t[n].c.push_back(&t[dis[n][m]]);
			t[n].num++;
			ret+=build(dis[n][m],n);
		}
	}
	t[n].v=ret;
	return t[n].v;
}

bool comp(int x, int y) {
	return x>=y;
}

int b[300+5];

void msort(int l, int r, int *a) {
	if(l==r) {
		return ;
	} else if(r-l==1) {
		if(a[l]<a[r]) {
			int tmp=a[l];
			a[l]=a[r];
			a[r]=tmp;
		}
	} else {
		int mid=(l+r)>>1;
		msort(l,mid,a);
		msort(mid+1,r,a);
		int i=l,j=mid+1,k;
		for(k=l;k<=r;k++) {
			if(i>mid) {
				b[k]=a[j++];
			} else if(j>r) {
				b[k]=a[i++];
			} else if(a[i]<a[j]) {
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

void bfs() {
	queue<tree> q,q2;
	q.push(&t[1]);
	tree x;
	int res=0;
	int a[3000+5],cnt;
	bool flag;
	int i;
	while(!q.empty()) {
//		printf("Mark 1\n");
		cnt=0;
		while(!q.empty()) {
			x=q.front();
			q.pop();
			for(i=0;i<x->num;i++) {
				a[++cnt]=x->c[i]->v;
				q2.push(x->c[i]);
			}
		}
		if(cnt==0) {
			break;
		}
/*		printf("Mark 2\n");
		for(i=1;i<=cnt;i++) {
			printf("a[%d]=%d \n",i,a[i]);
		}
*/		msort(1,cnt,a);
//		printf("cnt=%d\n",cnt);
		res+=a[1];
		flag=true;
		while(!q2.empty()) {
			x=q2.front();
			q2.pop();
			if(x->v==a[1]&&flag==true) {
				flag=false;
			} else {
				q.push(x);
			}
		}
	}
	printf("%d\n",N-res);
}

int main() {
	read();
	build(1,0);
	bfs();
	return 0;
}

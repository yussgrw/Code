#include <cstdio>
#include <cstring>
using namespace std;

char str1[10000],str2[10000];
int f1[10000]={0},f2[10000]={0};

int main() {
	scanf("%s %s",str1,str2);
	int len1=strlen(str1),len2=strlen(str2),i,j,*p1=f1,*p2=f2,*tmp,x1=0,y1=0,x2=0,y2=0;
	for(i=0;i<len1;i++) {
		for(j=0;j<len2;j++) {
			if(str1[i]==str2[j]) {
				p2[j+1]=p1[j]+1;
				if(!(x1||y1)) {
					x1=i+1;
					y1=j+1;
				}
				x2=i+1;
				y2=j+1;
			} else {
				p2[j+1]=p2[j]>p1[j+1]?p2[j]:p1[j+1];
			}
		}
		tmp=p1;
		p1=p2;
		p2=tmp;
	}
	int result=(x1>y1?x1:y1)+((len1-x2)>(len2-y2)?(len1-x2):(len2-y2))+((x2-x1)>(y2-y1)?(x2-x1):(y2-y1))-p1[len2];
	printf("%d\n",result>(len1>len2?len1:len2)?(len1>len2?len1:len2):result);
	return 0;
}

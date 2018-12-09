#include <cstdio>
#include <cstring>
using namespace std;

char str1[10000+5],str2[10000+5];
int len1,len2,len;
int num1[10000+5],num2[10000+5],num3[10000+5]={0};

void read() {
	scanf("%s%s",str1,str2);
	len1=strlen(str1);
	len2=strlen(str2);
	len=len1>len2?len1:len2;
	int i;
	for(i=0;i<len1;i++) {
		num1[len1-i]=str1[i]-'0';
	}
	for(i=0;i<len2;i++) {
		num2[len2-i]=str2[i]-'0';
	}
}

void run1() {
	int i;
	for(i=(len1<len2?len1:len2)+1;i<=(len1<len2?len2:len1);i++) {
	}
}

int main() {
	;
	return 0;
}

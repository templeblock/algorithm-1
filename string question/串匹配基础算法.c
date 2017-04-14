#include<stdio.h>
#include<string.h>

//ʱ�临�Ӷ�Ϊ:O(m * n)
int findSubIndex(const char *source, const char *sub);

int findSubIndex(const char *source, const char *sub){
	int i;
	int j;
	int len = strlen(source) - strlen(sub);

	for(i = 0; i <= len; i++){
		for(j = 0; sub[j] && source[i+j] == sub[j]; j++){
			;
		}
		if(sub[j] == 0){
			return i;
		}
	}

	return -1;
}

void main(void){
	char source[80];
	char sub[80];

	puts("������ԭ��: ");
	gets(source);
	puts("�������Ӵ�:");
	gets(sub);

	printf("%d\n", findSubIndex(source, sub));
}
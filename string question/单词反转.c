#include<stdio.h>
#include<string.h>
#include<ctype.h>


void revStr(char *str, int from, int to);
void finalRev(char *str);

void finalRev(char *str){
	int from = 0;
	int to = 0;

	while(str[to]){
		while(isalpha(str[to])){
			to++;
		}
		revStr(str, from, to-1);
		while(isspace(str[to])){
			to++;
		}
		from = to;
	}
}

void revStr(char *str, int from, int to){
	char tmp;

	while(from < to){
		tmp = str[from];
		str[from++] = str[to];
		str[to--] = tmp;
	}
}

void main(void){
	char str[80];
	int strLen;
	int count = 0;
	int i = 0;

	//gets�ڽ����ַ���ʱ,���Խ��տո�,�м�Ŀո񶼽�����������;
	//scanf�ڽ����ַ���ʱ,�����ո񡢻س���Tab��������Ϊ������������������ܽ��տո�;
	printf("�������ַ���:\n");
	gets(str);
	strLen = strlen(str);
	revStr(str, 0, strLen-1);
	finalRev(str);

	puts(str);	
}
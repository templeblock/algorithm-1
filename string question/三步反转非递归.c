#include<stdio.h>
#include<string.h>

void revStr(char *str, int from, int to);

void revStr(char *str, int from, int to){
	 int tmp;

	 while(from < to){
		tmp = str[from];
		str[from++] = str[to];
		str[to--] = tmp;
	 }
}

void main(void){
	char str[80];
	int number;
	int strLen;

	printf("�������ַ���:\n");
	gets(str);
	strLen = strlen(str);
	printf("������Ҫ�ŵ������ַ����ĸ���: ");
	scanf("%d", &number);
	revStr(str, 0, number-1);
	revStr(str, number, strLen-1);
	revStr(str, 0, strLen-1);
	printf("%s\n", str);

}

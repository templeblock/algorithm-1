#include<stdio.h>
#include<string.h>

//ʱ�临�Ӷ�Ϊ��O(n),�ռ临�Ӷ�Ϊ��O(1);
//abcdefg----->cdefgab
void revStr(char *str, int length);

void revStr(char *str, int length){
	char tmp;
	
	if(length > 1){
		tmp = str[0];
		str[0] = str[length-1];
		str[length-1] = tmp;
		revStr(str+1, length-2);
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
	revStr(str, number);
	revStr(str+number, strLen-number); 
	revStr(str, strLen);
	printf("%s\n", str);

}

#include<stdio.h>
#include<assert.h>

//�ַ����Ŀ�����������ͬ0������־һ����п���;

char *myStrcpy(char *strD, const char *strS);

char *myStrcpy(char *strD, const char *strS){
	char *ptmpD = strD;
	const char *ptmpS = strS;

	assert(ptmpD != NULL && ptmpS != NULL);
	while(*ptmpS){
		*ptmpD++ = *ptmpS++;
	}
	*ptmpD = 0;  //��ͬ0��־һͬ���п���;

	return strD;	
}

int main(void){
	char s1[20] = "hello"; //��֤Ҫ�����Ŀռ��㹻;
	char *s2 = "wor";

	printf("%s\n", myStrcpy(s1, s2));
	return 0;
}
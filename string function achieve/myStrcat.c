#include<stdio.h>
#include<assert.h>

char *myStrcat(char *strD, const char *strS);

char *myStrcat(char *strD, const char *strS){  //���ص��ǵ�һ���ַ����ĵ�ַ:s1 += s2;
	char *ptmpD = strD;   //1����ԭ�����ı�������
	const char *ptmpS = strS;

	assert(strD != NULL && strS != NULL); //����,��ֹ����;

	while(*ptmpD){  //Ŀ������ߵ���һ���ַ�����ĩβ
		ptmpD++;
	}

	while(*ptmpS){ //ԭ�Ĳ�Ϊ��,��ԭ��һ��һ���ַ��Ŀ���Ŀ����ַ�����
		*ptmpD++ = *ptmpS++;
	}
	*ptmpD = 0; //���һ���ַ��Ŀռ���븳ֵΪ0��

	return strD;
}

int main(void){
	char s1[20] = "hello";  //�����㹻�Ŀռ乻���ӵ�;
	char *s2 = "world";

	printf("%s\n", myStrcat(s1, s2));
	return 0;
}
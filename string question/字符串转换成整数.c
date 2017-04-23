#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define TRUE	1
#define FALSE	0
#define MAX_NUM	2147483647	
#define MIN_NUM 2147483648

char islegal = TRUE;  //����һ��ȫ�ֱ���,�����ж�������Ƿ�Ϸ�;

int strToInt(char *str);
int strToInt(char *str){
	int sign = 1;   //��������
	int i;
	unsigned int num = 0;  //Ҫ��֤num�������,�����Ƚϵ�ʱ��
//int�ķ�Χ:-2147483648---2147483647
//unsigned int�ķ�Χ��0-4294967296,��ʱ�ڱ�֤������������,����ֵ�����ж�;

	if(NULL == str){  //�ж������Ƿ�Ϊ��
		islegal = FALSE;
		return -1;
	}

	while(isspace(*str)){
		++str;
	}
	if(*str == '+' || *str == '-'){
		if(*str++ == '-'){
			sign = -1;
		}
		if(*str == 0){  //�ַ���ֻ������һ��+/-���ǷǷ�����;
			islegal = FALSE;
			return -1;
		}
	}
	
	for(i = 0; str[i]; i++){
		if(isdigit(str[i])){
			;
		}else{
			islegal = FALSE;
			return -1;
		}
	}

	while(isdigit(*str)){  //�ж��Ƿ�Ϊ0-9,�ǵĻ����ط�0,���Ƿ���0
		//��ʱ���ѵ����ж��������;
		num = num * 10 + *str - '0';
		++str;

		if(sign == 1 && num > MAX_NUM){
			islegal = FALSE;
			return -1;			
		}
		if(sign == -1 && num > MIN_NUM){
			islegal = FALSE;
			return -1;				
		}
	}
	return (sign > 0 ? (int)num : (int)-num);
}

void main(void){
	char str[80] = {0};
	int num;

	printf("str : ");
	gets(str);
	num = strToInt(str);
	if(islegal == TRUE){
		printf("%d\n", num);
	}else{
		printf("������ǷǷ���\n");
	}
}
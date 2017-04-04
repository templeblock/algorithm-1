#include<stdio.h>
#include<assert.h>

int myStrcmp_1(const char *str1, const char *str2);
int myStrcmp_1(const char *str1, const char *str2){
	const char *s1 = str1;
	const char *s2 = str2;
	int result = 0;

	//�����㷨
	assert(str1 != NULL && str2 != NULL);
	while(*s1 || *s2){
		result = *s1 - *s2;
		if(result){
			break;
		}
		s1++;
		s2++;
	}
	if(result > 0){
		result = 1;
	}else if(result < 0){
		result = -1;
	}
	
	return result;
}


//�ַ��������Ӻ͸���һ��Ҫ��ס������һ���ַ��ռ丳ֵΪ0;
int myStrcmp(const char *str1, const char *str2);

int myStrcmp(const char *str1, const char *str2){
	const char *s1 = str1;
	const char *s2 = str2;

	assert(str1 != NULL && str2 != NULL);
	while(*s1 && *s2){
		if(*s1 > *s2){
			return 1;
		}else if(*s1 < *s2){
			return -1;
		}else{
			s1++;
			s2++;
		}
	}
	if(*s1 && *s2 == NULL){
		return 1;
	}else if(*s1 == NULL && *s2){
		return -1;
	}

	return 0;

}

int main(void){
	char *s1 = "hello";
	char *s2 = "hello";
	int result;

	result = myStrcmp_1(s1, s2);
	if(result == 0){
		printf("s1 == s2\n");
	}else if(result > 0){
		printf("s1 > s2\n");
	}else{
		printf("s1 < s2\n");
	}
	return 0;
}
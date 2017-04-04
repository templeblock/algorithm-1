#include<stdio.h>
#include<assert.h>

 //���粻����ʹ�ñ������м���,��ʱ�͵ý��еݹ����,��һ�ֵ��żӻ�ȥ��˼��;
size_t myStrlen_1(const char *str);
size_t myStrlen_1(const char *str){
	assert(str != NULL);	

	if(*str == 0){
		return 0;
	}else{
		return myStrlen_1(str+1)+1;
	}
}

//typedef unsigned int size_t;  
size_t myStrlen(const char *str);
size_t myStrlen(const char *str){
	const char *ptmp = str;  //1���Բ������б�������
	size_t count = 0;		

	assert(str != NULL);  //2���Բ����ĺϷ��Խ��ж���
	while(*ptmp++){  //�˴���++����������ȼ�����*,�����Ǻ�++,�����Ƚ���ָ�����㣬�ڽ���++;
		count++;
	}

	return count;
}

int main(void){
	char *str = "Hello C";

	printf("%d\n", myStrlen_1(str));
	return 0;
}
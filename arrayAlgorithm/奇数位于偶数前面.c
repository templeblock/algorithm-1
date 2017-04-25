#include<stdio.h>

//������ż˳�򲻱�Ļ�,�͵ÿ����µĿռ�,��һ�����ֻ������,�������ĺ���,�ڶ������ֻ��ż��;
void adjustArray(int *a, int count);
void swap(int *a, int *b);

void swap(int *a, int *b){
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void adjustArray(int *a, int count){
	int front = 0;
	int back = count-1;

	if(a == NULL || count < 2){  //�����³���Ե���֤
		return;
	}

	while(front < back){
		if(a[front]%2 == 1){
			front++;
		}else if(a[back] % 2 == 0){
			back--;
		}else{
			swap(&a[front], &a[back]);
		}
	}

}

void main(void){
	int a[] = {4, 3, 5, 2, 7, 1, 9};
	int count = sizeof(a)/sizeof(int);
	int i;

	adjustArray(a, count);
	for(i = 0; i < count; i++){
		printf("%d ", a[i]);
	}
	printf("\n");

}
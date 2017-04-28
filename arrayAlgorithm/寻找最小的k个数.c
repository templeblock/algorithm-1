#include<stdio.h>
 
void findKSmall(int *a, int start, int end, int key);
 //��С��k��������С�ĵ�k����
void findKSmall(int *a, int start, int end, int key){
    int i = start;
    int j = end;
    int tmp = a[i];
//�����е�����
    while(i < j){
        while(i < j && a[j] > tmp){
            j--;
        }
        if(i < j){
            a[i++] = a[j];
        }
        while(i < j && a[i] < tmp){
            i++;
        }
        if(i < j){
            a[j--] = a[i];
        }
    }
    a[i] = tmp;
 
    if(key-1 < i){
        findKSmall(a, 0, i-1, key);
    }else if(key-1 > i){
        findKSmall(a, i+1, end, key);
    }else{
        return;
    }
}
 
void main(void){
    int a[] = {8, 4, 6, 9, 2, 3, 7, 9, 11, 10};
    int count = sizeof(a)/sizeof(int);
    int k;
    int i;
 
    printf("������Ҫ���ҵĵ�kС������");
    scanf("%d", &k);
    findKSmall(a, 0, count-1, k);
    for(i = 0; i < count; i++){
        printf("%d ", a[i]);
    }
 
	printf("\n");
	for(i = 0; i < k; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
 
}
#include<stdio.h>
 
//��������ֺͣ�̰���㷨,ʱ�临�Ӷ�Ϊ��O(n)
int maxSubArray(int *a, int n);
int maxSubArray(int *a, int n){
    int i;
    int ans = -10000000;
    int sum = 0;
 
    for(i = 0; i < n; i++){
        sum += a[i];
        if(sum > ans){
            ans = sum;  //������ǰ�����ֵ
        }
        if(sum < 0){
            sum = 0; //��һ���ֺ�<0��ֱ��ɾȥ
        }
    }
 
    return ans;
}
 
void main(void){
    int a[] = {-1, -2, 3, 6, -6, 3, 3, 2, -3};
    int count = sizeof(a)/sizeof(int);
    int maxNumber;
 
    maxNumber = maxSubArray(a, count);
    printf("%d\n", maxNumber);
}
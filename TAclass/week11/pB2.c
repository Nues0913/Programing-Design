#include <stdio.h>

void swap(int *pa,int *pb ){
    int tem = *pa;
    *pa = *pb;
    *pb = tem;

}

void QSORT(int *nums, int left, int right){  
    if(right <= left) return;   // 停止條件:右邊界小於等於左邊界
    int l = left - 1;
    int r = left;
    int key = nums[right];
    while(1){
        if(nums[r] <= key){
            l++;
            swap(&nums[l],&nums[r]);
            r++;
        } else if (nums[r] > key){
            r++;
        }
        if(r == right)break;
    }
    swap(&nums[l+1],&nums[r]);

    QSORT(nums,left,l);     //處理右邊
    QSORT(nums,l+1,right);  //處理左邊
}

int main(void){
    
    int array[10];
    int len = sizeof(array) / sizeof(int);
    
    for(int i = 0; i < len; i++){
        scanf("%d",&array[i]);
    }
    
    QSORT(&array[0],0,len-1);

    for(int i=0; i<10; i++){
        printf("%d ",array[i]);
    }
}
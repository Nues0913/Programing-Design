#include <stdio.h>

void swap(int *pa,int *pb ){
    int tem = *pa;
    *pa = *pb;
    *pb = tem;

}

void QSORT(int *nums, int left, int right){  
    
    if(left>=right) return;
    int l = left + 1;
    int r = right;
    int key = nums[left];
    while(1){
        while(l<=right){
            if(nums[l] > key)break;
            l++;
        }
        while(r>left){
            if(nums[r] <= key)break;
            r--;
        }
        if(l>r)break;
        swap(&nums[r],&nums[l]);
    }
    swap(&nums[left],&nums[r]);
    QSORT(nums,left,r-1);
    QSORT(nums,r+1,right);
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
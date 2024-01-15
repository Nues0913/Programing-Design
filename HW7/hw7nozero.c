#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int options = 0;
int hardDriveOfFileName[21] = {-1};
int hardDriveOfFileSize[21] = {-1};
int fileAmount = 0;
int fileName;
int fileSize;

void arraprint(int arra[]){    //for debug
    for(int i = 0;i<= 20;i++){
        printf("%d ",arra[i]);
    }
}

void rearrange(){
    int temp[21] = {-1};
    int i = 0;
    for(int j = 0;j <= 20;j++){
        if(hardDriveOfFileName[j] != -1){
            temp[i] = hardDriveOfFileName[j];
            i++;
        }
    }
    for(int j = 0;j <= 20;j++){
        if(temp[j] != -1){
            hardDriveOfFileName[j] = temp[j];
        } else {
            hardDriveOfFileName[j] = -1;
        }
    }
    int temp2[21] = {-1};
    i = 0;
    for(int j = 0;j <= 20;j++){
        if(hardDriveOfFileSize[j] != -1){
            temp2[i] = hardDriveOfFileSize[j];
            i++;
        }
    }
    for(int j = 0;j <= 20;j++){
        if(temp2[j] != -1){
            hardDriveOfFileSize[j] = temp2[j];
        } else {
            hardDriveOfFileSize[j] = -1;
        }
    }
    
}

int bestSum = 100000000;
int bestCombinationIndex[21];
/*
*@param k               欲刪除k個檔案
*@param m               欲刪除大小總和
*@param currentSum      起始加總，調用時應設0
*@param startIndex      起始索引，調用時應設0
*@param combination     儲存當前組合
*@param combinationSize 當前組合已加總元素數量，最大為k
*/
void getBestCombination(int k, int m, int currentSum, int startIndex, int combination[], int combinationSize){
    if (k == 0) {
        // printf("%d ", currentSum);
        // 這裡塞接近m回傳最佳解combination的函式
        if( abs(m - currentSum) < bestSum ){
            bestSum = abs(m -currentSum);
            for(int j = 0;j < combinationSize;j++){
                for(int index = 0;index < 21;index++){
                    if(hardDriveOfFileSize[index] == combination[j]){
                        bestCombinationIndex[j] = index;
                    }
                }
            }
        }
        return;
    }
    for (int i = startIndex; i <= 20; i++) {
        combination[combinationSize] = hardDriveOfFileSize[i];
        getBestCombination(k - 1, m, currentSum + hardDriveOfFileSize[i], i + 1, combination, combinationSize + 1);
    }
}

int main(){
    while(options != 3){
        printf("Options: ");
        scanf("%d",&options);
        switch (options){
            case 1:
                printf("Please input file name and file size: ");
                scanf("%d %d",&fileName,&fileSize);
                if(fileAmount <= 19){   //20 is the redundant one
                    hardDriveOfFileName[fileAmount] = fileName;
                    hardDriveOfFileSize[fileAmount] = fileSize;
                    fileAmount += 1;
                } else {
                    hardDriveOfFileName[fileAmount] = fileName;
                    hardDriveOfFileSize[fileAmount] = fileSize;
                    int k,m;
                    printf("Hard drive exceeds its capacity, please enter the number of files to be deleted: ");
                    scanf("%d %d",&k,&m);
                    int combination[k];
                    bestSum = 100000000;
                    getBestCombination(k, m, 0, 0, combination, 0);
                    for(int i = 0;i < k;i++){
                        printf("%d",hardDriveOfFileName[bestCombinationIndex[i]]);
                        hardDriveOfFileName[bestCombinationIndex[i]] = -1;
                        hardDriveOfFileSize[bestCombinationIndex[i]] = -1;
                        if(i != k-1)printf(" ");
                    }
                    fileAmount -= k-1;
                    printf("\n");
                    rearrange();
                }
                break;
            case 2:
                printf("Please input the file name: ");
                int FileName;
                int No = 1;
                scanf("%d",&fileName);
                for(int i = 0;i <= 20;i++){
                    if(fileName == hardDriveOfFileName[i]){
                        printf("YES\n");
                        No = 0;
                        break;
                    }
                }
                if(No)printf("NO\n");
                break;
            case 3:
                break;
            default:
                break;
        }
    }
    
    return 0;
}
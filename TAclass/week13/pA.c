#include<stdio.h>

void SpiralMatrix(int n,  int (*matrix)[n]){
	int circle = (n+1)/2;
    int order = 1;
    for(int i = 0;i<circle;i++){
        int position = 1;
        for(int _ = 0;_<4;_++){
            if(order > n*n) break;
            switch (position){
                case 1: //top
                    for(int k = 0;k<n-i*2;k++){
                        matrix[i][i+k] = order++;
                    }
                    position++;
                    break;
                case 2: //right
                    for(int k = 0;k<n-1-i*2;k++){
                        matrix[i+k+1][(n-1)-i] = order++;
                    }
                    position++;
                    break;
                case 3: //button
                    for(int k = 0;k<n-1-i*2;k++){
                        matrix[(n-1)-i][(n-1)-i-k-1] = order++;
                    }
                    position++;
                    break;
                case 4: //left
                    for(int k = 0;k<n-2-i*2;k++){
                        matrix[(n-1)-k-1-i][i] = order++;
                    }
                    position++;
                    break;
            }
        }
        
    }
}


int main(){
	int n;
	
	scanf("%d", &n);
	
	int matrix[n][n];

	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++)
			matrix[i][j] = 0;
	
	SpiralMatrix(n, matrix);
    
	for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) 
                printf("%3d ", matrix[i][j]);
            printf("\n");
	}
    
	return 0;
}
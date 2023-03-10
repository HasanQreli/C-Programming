#include <stdio.h>
#define W_INDEX 0
#define H_INDEX 1
#define T_INDEX 2
#define P_INDEX 3
#define S_INDEX 4
#define A_INDEX 5
#define N_INDEX 6

int main() {
    
    int r,arr[100000], tribecount, i,width, height, time, position, speed, interval, numattack, j,k;
    
    scanf("%d", &r);
    
    for(i=0;i<r+1;i++)
        arr[i]=1;
    
    scanf("%d", &tribecount);
    
    for(i=0;i<tribecount;i++){
        
        scanf("%d %d %d %d %d %d %d",&width, &height, &time, &position, &speed, &interval, &numattack);
        
        for(j=0;j<numattack;j++){
            
            for(k=0;k<width;k++){
                if(0<=position+k && position+k<200000){
                if(arr[position+k]<height)
                    arr[position+k]=height;}
                
            }
            position+=speed*interval;
        }
        
    }
    
    for(i=0;i<r+1;i++){
        printf("%d",arr[i]);
        if(i!=r)
            printf(" ");
        
    }
    printf("\n");
    return 0;
}
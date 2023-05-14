#include<stdio.h>
void main(){
    int allocated[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,2,2}};
    int max[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    int avail[3]={3,3,2};
    int sequence[5];
    int s=-1;
    int need[5][3];
    int complite[100];
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            need[i][j]=max[i][j]-allocated[i][j];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            //need[i][j]=max[i][j]-allocated[i][j];
            printf("%d ",need[i][j]);
        }
        printf("\n"); 
    }
    int y=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(complite[j]!=1){
                int f=0;
            for(int k=0;k<3;k++){
                if(need[j][k]>avail[k]){
                    f=1;
                    break;         
                }
            }
            if(f==0){
                s++;
                sequence[s]=j+1;
                complite[j]=1;
                for(y=0;y<3;y++){
                    avail[y]=avail[y]+allocated[j][y];
                }
            }
            }
            
        }
    }
    printf("the safty sequence is=");
    for(int i=0;i<5;i++){
        printf("p%d ",sequence[i]);
    } 
}
#include<stdio.h>
    int external[10];
    int external[10];
int pn[]={1,2,3,4,5},pSize[]={40,10,30,60,130},bN[]={1,2,3,4,5,6},bSize[]={100,50,30,120,35,125},allocated[10],complete[10],external[10],internalFrage=0;
int k=0,externalFrage=0;
void blockFinder(int pn,int pSize){
    int minMemoryWastage=100000,a,bn=-1,c;
    for(int i=0;i<6;i++){
        a=bSize[i]-pSize;
        if(a<minMemoryWastage && a>=0 && complete[i]!=1){
            minMemoryWastage=a;
            bn=bN[i];
            c=i;
        }
        //printf("%d\n",bn);
    }
    if(bn!=-1){
        complete[c]=1;
        allocated[pn]=bn;
        internalFrage+=minMemoryWastage;
        //printf("%d",allocated[pn]);
    }
    else{
        allocated[pn]=-1;
        for(int i=0;i<6;i++){
            if(complete[i]!=1){
                externalFrage=externalFrage+bSize[i];

            }
        }
        if(pSize<=externalFrage){
                external[k]=externalFrage;
                k++;
        }
    }




}
int main(){

    for(int i=0;i<5;i++){
    blockFinder(pn[i],pSize[i]);
    }
    for(int i=0;i<5;i++){
        printf("%d is allocate to %d\n",pn[i],allocated[i+1]);

    }
    printf("total internal fragmentation is=%d",internalFrage);
    int max=0;
    for(int i=0;i<k;i++){
        if(external[i]>max){
            max=external[i];
        }
    }
    printf("total external fragmentation is=%d",max);
return 0;
}

#include<stdio.h>
int pn[10]={1,2,3,4,5,6},at[10]={5,8,3,6,2,4},bt[10]={3,6,3,1,2,5},ctime[10],tat[10],wt[10],ct=0,complete[10];
void ganchatfind(){
    int min=1000,j;
    for(int i=0;i<6;i++){
        if(at[i]<=ct && complete[i]!=1){
            if(bt[i]<min){
                min=bt[i];
                j=i;
            }
        }
    }
    printf("p%d  ",pn[j]);
    ct=ct+bt[j];
    ctime[j]=ct;
    complete[j]=1;
}
int main(){
//FOR IDEAL TIME 
for(int i=0;i<6;i++){
    int min=10000;
    for(int i=0;i<6;i++){
        if(at[i]<min && complete[i]!=1){
            min=at[i];
        }
    }
    if(ct<min){
        while(ct<min){
            ct++;
        }
    printf("ideal");
    }
    ganchatfind();
}
//FOR TAT AND WT
    for(int i=0;i<6;i++){
        tat[i]=ctime[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }
printf("\npno\tat\tbt\tct\ttat\twt\n");
for(int i=0;i<6;i++){
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",pn[i],at[i],bt[i],ctime[i],tat[i],wt[i]);
}

return 0;
}
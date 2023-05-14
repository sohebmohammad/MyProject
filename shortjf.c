#include<stdio.h>
#include<limits.h>

void swap(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}



int findminburst(int bt[],int visited[],int n,int at[],int arrival){
       int min=INT_MAX;
       int x,i;
      for(i=0;i<n;i++){
        if(bt[i]<min && visited[i]==0&&at[i]<=arrival) {    
            min=bt[i];
            x=i;
        }
      }
      visited[x]=1;
      return x;
}


int main(){
   int n,i,j;
   scanf("%d",&n);
    int pn[n];
   int at[n];
   int bt[n];
   int ct[n];
   int visited[n];
   memset(visited,0,sizeof(visited));
   for(i=0;i<n;i++){
      scanf("%d",&pn[i]);
      scanf("%d",&at[i]);
      scanf("%d",&bt[i]);
   } 
   printf("before sorting\n");  
    for(i=0;i<n;i++){
      printf("%d %d %d\n",pn[i],at[i],bt[i]);
   } 
   for(i=0;i<n-1;i++){
      for(j=0;j<n-i-1;j++){
           if(at[j]>at[j+1]){
                  swap(&at[j+1],&at[j]);
                  swap(&bt[j+1],&bt[j]);
                  swap(&pn[j+1],&pn[j]);
           }
      }
   }
   int arrival=0;
    for(i=0;i<n;i++){
        if(at[i]<=arrival){
             int z=findminburst(bt,visited,n,at,arrival);
             ct[z]=arrival+bt[z];
             int k=arrival;
             arrival=ct[z];
             printf("processid%d(%d- %d)->",pn[z],k,ct[z]);
             
        }
        else{
            int x=arrival;
            arrival=arrival+(at[i]-arrival);
            printf("IDLE (%d-%d)->",x,arrival);
            i--;
        }
    
    }
    printf("\n");
  /* printf("after sorting \n"); 
    for(int i=0;i<n;i++){
      printf("%d %d %d\n",pn[i],at[i],bt[i]);
   } */
   int tat[n];
    int wt[n];
    printf("PN AT BT CT TAT WT \n");
    for(i=0;i<n;i++){
       tat[i]=ct[i]-at[i];
       wt[i]=tat[i]-bt[i];
      printf("%d %d %d %d %d %d \n",pn[i],at[i],bt[i],ct[i],tat[i],wt[i]);
   } 
  return 0;
}

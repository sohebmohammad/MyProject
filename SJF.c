#include <stdio.h>


int main(){
    int Pname[]={1,2,3,4,5};
    int AT[]={2,4,6,7,9};
    int BT[]={1,1,2,5,4};
    int n=5;
    int arr[10],g=0,CT[10],TAT[10],WT[10],Ganttchat[10];
    //FIND MINIMUM ARRIVAL OF TIME BCZ IT COMES IN GANTT CHAT FIRST
    int min=9999,p;
    for (int i=1; i<=n; i++)
    {
        if(AT[i]<min)
        {
            min=AT[i];
            p=i;
        }
    }
    int f=0;
    for(int ct=1;ct<min;ct++){
        f=1;

    }
    if(f==1){
        //printf("IDEAL TIME");
        Ganttchat[g++]=-1;
    }
    Ganttchat[g++]=p;
    CT[0]=AT[p];
    int ct=CT[0];
    for(int i=2;i<=n;i++){
        for(int j=0;j<n;j++){
                            
        }

    }






    for(int i=0;i<n;i++){
        printf("%d    ",Ganttchat[i]);
    }
    
    

}

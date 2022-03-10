#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE* lotto;
int num[7]={0};
void lottery(){
    int array,a,n=0;
    for (int i=1;i<7;i++){
        num[i]=0;
    }
    while (n<6){
        array=rand()%69+1;
        a=0;
        for(int i=1;i<=n;i++){
            if (num[i]==array){
                a=1;
            }
        }
        if(a==0){
            num[n]=array;
            n++;
        }
    }
    int b=0,c=0,temp=0;
    for (b=0;b<6;b++){
        for(c=b;c<6;c++){
            if(num[c]<num[b]){
                temp=num[c];
                num[c]=num[b];
                num[b]=temp;
            }
        }
    }
    num[6]=rand()%10+1;
    for(int i=0;i<7;i++){
        fprintf(lotto,"%02d ",num[i]);
    }
}
FILE* operator_id;
int id[4]={0};
void operator_id(){
    for(int i=0;i<5;i++){
        id[i]={i+=1};
    }
}
int main(){
    int n =0;
    int k =0;
    lotto=fopen("lotto.txt","w+");
    printf("hwo many?");
    scanf("%d",&n);
    srand((unsigned)time(NULL));
    time_t curtime;
    time(&curtime);
    fprintf(lotto,"======== lotto649 ========\n%s",ctime(&curtime));
    for (int i=0;i<n;i++){
        fprintf(lotto,"[%d] : ",i+1);
        lottery();
        fprintf(lotto,"\n");
    }
    for (int m=0;m<(6-n);m++){
        fprintf(lotto,"[%d] : ",n+m+1);
        for (int j=0;j<7;j++){
            fprintf(lotto,"-- ");
        }fprintf(lotto,"\n");
    }
    printf("user id");
    scanf("%d",&k);
    printf("========*");
    fprintf(operator_id,"0000%d",id[k]);
    printf("*========\n");
    fclose(operator_id);
    fprintf(lotto,"======== csie@cgu ========");
    fclose(lotto);
}
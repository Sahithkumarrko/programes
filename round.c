#include<stdio.h>
#include<stdlib.h>
main(){
int i,n,bt[20],pos=0,tpos[20],loop=0,k,temp,j,count,rr[20],wt[20],tt[20],pp[20],tq;
printf("enter number of processes : ");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("enter the burst time for procees %d : ",i+1);
scanf("%d",&bt[i]);
wt[i]=0;
}
printf("enter time quantum : ");
scanf("%d",&tq);
i=0;
j=0;
temp=0;
count=n;
while(count!=0){
for(i=0;i<n;i++){
if(bt[i]<=tq && bt[i]!=0){
count--;
temp+=bt[i];
bt[i]=0;
rr[j]=temp;
pp[j]=i+1;
j++;
}

if(bt[i]>tq){
temp+=tq;
rr[j]=temp;
pp[j]=i+1;
j++;
bt[i]=bt[i]-tq;
}
}

if(loop==0){
for(i=0;i<n;i++){
tpos[i]=rr[i];

}
for(i=1;i<n;i++){
wt[i]=rr[i];
}
}
if(loop>=1){
pos=pos+n;
pp[pos + (j-pos) + 1]=0;
printf("\n%d  %d  %d",loop,pos,j);
for(i=0;i<n;i++){

for(k=pos;k<(j);k++){
printf("k=%d\n ",k);
if(pp[k]==(i+1) && pp[k+1]!=(i+1)){
wt[i]=wt[i]+(rr[k]-tpos[i]);
printf("\n%d  %d\n",pp[k],i+1);
//printf("\n%d  %d",loop,wt[i]);
tpos[i]=rr[k];
}
}
printf("%d\n",tpos[i]);
}
}
loop++;
}
for(i=0;i<j;i++){
printf("%d\t%d\n",pp[i],rr[i]);
}
for(i=0;i<n;i++){
printf("%d\n",wt[i]);
}
}


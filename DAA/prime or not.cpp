#include<stdio.h>
int main(){
int n,count=0;
printf("enter the number ");
scanf("%d",&n);
for(int i = 2 ;i<n; i++){
if(n%i==0){
count++;
}
}
if (count>=1){
printf("it is not a prime number");
}
else
printf("it is a prime number");
return 0;
}

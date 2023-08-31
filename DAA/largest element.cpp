#include<stdio.h>
int main(){
int n1,n2,gcd=0;
printf("enter the numbers ");
scanf("%d %d",&n1,&n2);
for(int i =1 ; i<=n1 && i<=n2; i++){
if(n1%i == 0 && n2%i == 0){
gcd = i ;
}
}
printf("The gcd of the entered numberis %d",gcd);
return 0;
}


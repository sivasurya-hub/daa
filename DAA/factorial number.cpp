#include<stdio.h>
int main() {
int n ; double arr[100];
printf("enter the number of elements enter in the array");
scanf("%d",&n);
printf("enter the numbers");
for(int i =0 ;i<n;i++){
scanf("%d",&arr[i]);
}
for(int i =0 ;i<n;i++){
if(arr[0]<arr[i]){
arr[0]=arr[i];
}
}
printf("The largest element in the array is %d",arr[0]);
return 0;
}

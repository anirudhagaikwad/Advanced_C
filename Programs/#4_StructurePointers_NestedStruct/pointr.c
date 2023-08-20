#include<stdio.h>
int main(){
int *ptr1;
int **ptr2;
int x=10;
ptr1=&x;
printf("X Memory : %d\n",&x);
printf("ptr1 holding value : %d\n",ptr1);
printf("ptr1 point value of x : %d\n",*ptr1);
ptr2=&ptr1;
printf("Access value of X using ptr2 : %d \n",**ptr2);
printf("ptr1 size  : %d\n",sizeof(ptr1));
printf("ptr1 Memory before increment : %d\n",&ptr1);
printf("ptr1 holding value before increment : %d\n",ptr1);
ptr1++;
printf("ptr1 Memory after increment : %d\n",&ptr1);
printf("ptr1 holding value after increment : %d\n",ptr1);
printf("ptr1 memory address in Hexadecimal format : %p \n",&ptr1);
int arr[5]={1,2,3,4,5};
printf("1 index element of array %d",arr[1]);
arr[5]=77; //update element of array index 5
for(int i=0;i<=*(&arr + 1) - arr;i++){
printf("\nArray Element of index %d with value %d ",i,arr[i]);
}
}
/*
for (int i = 0; i <= *(&arr + 1) - arr; i++) {: This is a for loop that iterates through the array elements.

*(&arr + 1) calculates the memory address of the element immediately after the last element of the array.
Subtracting arr from this address gives the number of elements in the array.
So, the loop iterates from index 0 to the number of elements in the array minus 1.
*/


















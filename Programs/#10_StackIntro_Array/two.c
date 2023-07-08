/*
Given a stack of integers, sort it in ascending order using another temporary stack.

Input:
No. of elements in array are: 5
Enter array elements: 1
3
67
89
65

Output:
1 3 65 67 89

*/

#include <stdio.h>
#define ll long long
void sortStack(int input[],int size)
{
  int tmpStack[size];
  int top=-1;
  while (size>=0)
  {
      int tmp = input[size];
      size--;
      // while temporary stack is not empty and top
      // of stack is greater than temp
      while (top>=0 && tmpStack[top] < tmp)
      {
          // pop from temporary stack and push
          // it to the input stack
          input[++size]=tmpStack[top];
          top--;
      }
      // push temp in tempory of stack
      tmpStack[++top]=(tmp);
  }
  while (top>=0)
  {
      printf("%d ",tmpStack[top]);
      top--;
  }
}
int main()
{

    int n,x;
    printf("No. of elements in array are: ");
    scanf("%d",&n);

    int input[n];int top=-1;

    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
      scanf("%d",&x);
      input[++top]=x;

    }
    // This is the temporary stack
    sortStack(input,top);
    printf("\n");


  return 0;
 }

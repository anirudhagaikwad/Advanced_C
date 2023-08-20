//Structure-Typedef-NestedStructure

#include<stdio.h>
#include<string.h>
typedef struct Address{
char addre[20];
}a;
struct Emp{
char name[10];
int id;
a add;
};

int main(){
struct Emp e1,e2,e3;
//e1.name="Rajiv";
strcpy(e1.name,"Rajiv");
e1.id=102;
printf("Size of Structure EMP is : %d\n",sizeof(e1));
printf("e1 name : %s\n",e1.name);
printf("e1 id : %d\n",e1.id);
strcpy(e1.add.addre,"Punjab");
printf("Address of e1 :%s\n",e1.add.addre);
}








//Structure Pointer

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Emp{
char name[10];
int id;
};

void displayEmpDetails(struct Emp *ptr, int totalEmp) {
    printf("\nEmployee Details : ");
    for (int j = 0; j < totalEmp; j++) {
        printf("\nEmployee Name : %s ID : %d", (ptr + j)->name, (ptr + j)->id);
    }
}

int main(){
struct Emp *e4Ptr;
int totalEmp;
printf("Enter number of employee : \n");
scanf("%d",&totalEmp);
while (getchar() != '\n'); // Clear the input buffer
e4Ptr=(struct Emp*) malloc(totalEmp*sizeof(struct Emp));
for(int i=0;i<totalEmp;++i){
printf("\nEnter Employee%d Name : ",i);
scanf("%s",(e4Ptr+i)->name);
printf("\nEnter Employee%d id : ",i);
scanf("%d",&(e4Ptr+i)->id);
while (getchar() != '\n'); // Clear the input buffer
}
displayEmpDetails(e4Ptr,totalEmp);
free(e4Ptr);
}








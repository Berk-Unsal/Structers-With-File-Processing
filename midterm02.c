#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Account{
    int age;
    char name[50];
    int ID;
    float balance;
}acc;



void insert(int n){
    FILE* fp = fopen("C:\\Users\\user\\Desktop\\cprogramminmidterm\\midterm02.txt","r+");
    for(int i=0;i<n;i++){
        printf("Insert ID for %d. account: \n",i+1);
        int inputID;
        scanf("%d",&inputID);
        char buffer[300];
        fgets(buffer,sizeof(acc),fp); // to skip the first line
        int isExists = 0;
        acc newacc;
        while(!feof(fp)){
            fscanf(fp,"%d %s %d %f",newacc.age,newacc.name,newacc.ID,newacc.balance);
            if(inputID == newacc.ID){
                printf("ID already exists! \n");
                isExists = 1;
            }
        }
        if(isExists){
            break;
        }
        fprintf(fp,"%d %s %d %f",newacc.ID,newacc.name,newacc.balance);
    }

    printf("Account inserting function has ended successfully!\n");
}


void list(){
    FILE* fp = fopen("C:\\Users\\user\\Desktop\\cprogramminmidterm\\midterm02.txt","r");

    while(!feof(fp)){
        acc newacc;
        fscanf(fp,"%d %s %d %f",newacc.ID,newacc.name,newacc.age,newacc.balance);
        if(newacc.balance !=0){
            printf("Name: %s\tAge: %d\tID:%d\tBalance:%f\n",newacc.name,newacc.age,newacc.ID,newacc.balance);
        }
    }

    printf("Account listing function has ended successfully!\n");
}








int main(){

    int a = 5;
    switch (a)
    {
    case 5:{
        FILE fp;
        fopen("C:\\Users\\user\\Desktop\\cprogramminmidterm\\midterm02.txt","r+");
        break;
    }
        
    
    default:
        break;
    }







    return 0;
}
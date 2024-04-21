#include <stdio.h>
#include <string.h>


struct Account{
    double balance;
    char name[50];
    char adress[150];
    char phone[50];
};


void binsert(FILE* fptr){
    int n;
    printf("Enter the number of accounts to enter.\n");
    scanf("%d",&n);
    struct Account array[n];
    for(int i=0;i<n;i++){
        printf("Enter the name of the client %d:\n",i+1);
        scanf("%s",array[i].name);
        printf("Enter the balance of the client %d:\n",i+1);
        scanf("%lf",&array[i].balance);
        printf("Enter the adress of the client %d:\n",i+1);
        scanf("%s",array[i].adress);
        printf("Enter the phone of the client %d:\n",i+1);
        scanf("%s",array[i].phone);

        fwrite(&array,sizeof(struct Account),1,fptr);
        fclose(fptr);
    }
}

void blist(FILE* fptr){
    rewind(fptr);
    struct Account acc;
    while(!feof(fptr)){
        fread(&acc,sizeof(acc),1,fptr);
        if(acc.balance != 0){
            printf("%s %s %s %lf",acc.name,acc.adress,acc.phone,acc.balance);
            fclose(fptr);
        }
    }


}

void bsearch(FILE* fptr){
    struct Account acc;
    char name_to_find[50];
    int found = 0;

    printf("Enter the name to search: \n");
    scanf("%s",name_to_find);
    
    while(fread(&acc,sizeof(struct Account),1,fptr) == 1){
        if(strcmp(acc.name,name_to_find)== 0){
            printf("name : %s\n",acc.name);
            printf("adress: %s\n",acc.adress);
            printf("phone: %s\n",acc.phone);
            printf("balance: %lf\n",acc.balance);
            found = 1;
        }
    }
    if(!found){
        printf("name did not found!\n");
        return;
    }

}

void bupdate(FILE* fptr){
    struct Account acc;
    char name_to_find[50];
    int found = 0;
    char newadress[150];
    printf("Enter the name to search: \n");
    scanf("%s",name_to_find);
    while(!feof(fptr)){
        if(strcmp(acc.name,name_to_find) == 0){
            printf("Enter the new adress: \n");
            scanf("%s",newadress);
            fseek(fptr, -sizeof(struct Account),SEEK_CUR);
            fwrite(&acc,sizeof(struct Account),1,fptr);
            printf("Adress updated succesfully.");
        }
    }

}

void bdelete(FILE* fptr){
    struct Account acc;
    char name_to_delete[50];
    int found = 0;
    printf("Enter the name to delete:\n");
    scanf("%s",name_to_delete);
    while(!feof(fptr)){
        if(strcmp(acc.name,name_to_delete) == 0){
            
        }
    }
}

void binsertnew(FILE* fptr){
    struct Account acc;
    printf("Enter the name:\n");
    scanf("%s",acc.name);
    printf("Enter the adresss: \n");
    scanf("%s",acc.adress);
    printf("Enter the phone: \n");
    scanf("%s",acc.phone);
    printf("Enter the balance: \n");
    scanf("%lf",acc.balance);

    fseek(fptr, 0 , SEEK_END);
    fwrite(&acc,sizeof(struct Account),1,fptr);
    fclose(fptr);
}

int main(){
    FILE* fp;
    printf("Please enter your choice: \n");
    printf("1.Insert the info of n clients\n2.Listing\n3.Search\n4.Update the adress\n5.Delete\n6.Insert new\nOr any other number to exit\n");

    int choice;

    while(scanf("%d",&choice)!= 7){
        switch(choice){
            case 1:
                fp = fopen("C:\\Users\\user\\Desktop\\file_processing_c\\basic_bank.c","w");
                binsert(fp);
                break;
            case 2:
                fp = fopen("C:\\Users\\user\\Desktop\\file_processing_c\\basic_bank.c","rb");
                blist(fp);
                break;
            case 3:
                fp = fopen("C:\\Users\\user\\Desktop\\file_processing_c\\basic_bank.c","rb");
                bsearch(fp);
                break;
            case 4:
                fp = fopen("C:\\Users\\user\\Desktop\\file_processing_c\\basic_bank.c","rb");
                bupdate(fp);
            case 5:
                fp = fopen("C:\\Users\\user\\Desktop\\file_processing_c\\basic_bank.c","rb");
                bdelete(fp);
                break;
            case 6:
                fp = fopen("C:\\Users\\user\\Desktop\\file_processing_c\\basic_bank.c","w");
            default:
                break;
        }
    }





    return 0;
}
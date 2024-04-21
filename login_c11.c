#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Account{
    char nickname[50];
    char password[50];
};


int __checkPassword(char* __password){
    if(strlen(__password) < 8 || strlen(__password) > 50){
        printf("Password length must be greater than 8 and less then 50!\n");
        return 0;
    }

    char map[] = {'@','#','*','$','%','!','-','_','{','}','+'};
    int __INT = 0;
    int __EXCHAR = 0;
    int __UPPER = 0;
    for(int i=0;*(__password+i)!='\0';i++){
        if(!__INT){
            if(*(__password+i) >= '0' && *(__password+i)<='9'){
            __INT = 1;
            }
        }
        
        if(!__EXCHAR){
            for(int y=0;y<sizeof(map)/sizeof(map[0]);y++){
                if(*(__password+i) == map[y]){
                    __EXCHAR = 1;
                }
            }
        }
        if(!__UPPER){
            if(*(__password+i)>='A' && *(__password) <= 'Z'){
                __UPPER = 1;
            }
        }
    }

    if((!__INT || !__EXCHAR || !__UPPER)){
        return 0;
    }
    return 1;
}

int __register(struct Account acc){
    char name[50];
    printf("Enter a nickname: \n");
    scanf("%s",name);
    
    FILE* fp = fopen("C:\\Users\\user\\Desktop\\c_fileprocess2\\mydatabase.txt","r+");

    char buffer[100]; // to skip the first line

    fread(buffer,sizeof(struct Account),1,fp);

    char fName[50];
    char fPassword[50];

    while(!feof(fp)){
        fscanf(fp,"%s %s", &fName, &fPassword);
        if(!strcmp(fName,name)){
            printf("Nickname already exists!\n");
            return 0;
        }
    }

    char password[50];
    printf("Enter password: \n");
    scanf("%s",password);

    if(__checkPassword(password)){
        char check[50];
        printf("Enter the password again:\n");
        scanf("%s",check);
        if(strcmp(check,password)){
            printf("Passwords do not match!\n");
            return 0;
        }
    }

   





    fprintf(fp,"%s\t\t%s\n",name,password);
    fclose(fp);

    return 1;
    
}


int __login(const char nickname[50]){
    FILE* fp = fopen("C:\\Users\\user\\Desktop\\c_fileprocess2\\mydatabase.txt","r");
    int found = 0;
    while(!feof(fp)){
        char __name[50];
        char __password[50];
        fscanf(fp,"%s %s",__name,__password);

        if(!strcmp(__name,nickname)){
            found = 1;
            printf("Enter the password: \n");
            char password[50];
            scanf("%s",password);
            if(!strcmp(__password,password)){
                printf("Login successful!\n");
                return 1;
            }else{
                printf("Password is not correct!\n");
                break;
            }
        }
    }

    return 0;
}









int main(){

    struct Account acc;
    __register(acc);

    printf("\n#############->DEBUG<-############3\n");


    __login("berkvibritannia");









    return 0;
}
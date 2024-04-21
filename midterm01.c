#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct Book{
    char ID[50];
    char title[50];
    char name[50];
    char genre[50];
    int copies;
}book;


int badd(){
    book newbook;
    
    FILE* fp = fopen("C:\\Users\\user\\Desktop\\cprogramminmidterm\\midterm01.txt","r+");
    printf("Enter the ID number: \n");
    scanf("%s",newbook.ID);
    printf("Enter the title of the book\n");
    scanf("%s",newbook.title);
    printf("Enter the name of the book\n");
    scanf("%s",newbook.name);
    printf("Enter the genre of the book\n");
    scanf("%s",newbook.genre);
    printf("Enter how many copies that this book has made");
    scanf("%d",&newbook.copies);

    char ctrlID[50];
    char ctrltitle[50];
    char ctrlname[50];
    char ctrlgenre[50];
    int ctrlCop;



    while(!feof(fp)){
        fscanf(fp,"%s %s %s %s %d",ctrlID,ctrltitle,ctrlname,ctrlgenre,&ctrlCop);
        if(!strcmp(newbook.ID,ctrlID)){
            printf("This ID exists");
            fclose(fp);
            return 0;
        }
    }

    fprintf(fp,"%s\t\t%s\t\t%s\t\t%s\t\t%d",newbook.ID,newbook.title,newbook.name,newbook.genre,newbook.copies);

    return 1;

}

void list(){
    FILE* fp = fopen("C:\\Users\\user\\Desktop\\cprogramminmidterm\\midterm01.txt","rb");
    

    char buffer[200];

    fgets(buffer,sizeof(book),fp);


    while(!feof(fp)){
        book sbook;
        fscanf(fp,"%s %s %s %s %d",sbook.ID,sbook.title,sbook.name,sbook.genre,&sbook.copies);
        if(sbook.copies != 0){
            printf("ID: %s\nTitle: %s\nAuthor: %s\nGenre: %s\nCopies: %d\n",sbook.ID,sbook.title,sbook.name,sbook.genre,sbook.copies);
        }
    }

    fclose(fp);



}


void search() {
    printf("Enter the ID to search\n");
    char inputID[50];
    scanf("%s", inputID);


    char buffer[200];
    
    FILE* fp = fopen("C:\\Users\\user\\Desktop\\cprogramminmidterm\\midterm01.txt", "rb");
    
    fgets(buffer,sizeof(book),fp);


    if (fp == NULL) {
        printf("File couldn't open\n");
        return;
    }

    book temp;
    while (fscanf(fp, "%49s %49s %49s %49s %d", temp.ID, temp.title, temp.name, temp.genre, &temp.copies) == 5) {
        if (!strcmp(inputID, temp.ID)) {
            printf("ID : %s\nTitle: %s\nAuthor: %s\nGenre: %s\nCopies: %d\n", temp.ID, temp.title, temp.name, temp.genre, temp.copies);
            fclose(fp);
            return;
        }
    }

    printf("ID has not been found!\n");
    fclose(fp);
}


void delete(){

    FILE *fp = fopen("C:\\Users\\user\\Desktop\\cprogramminmidterm\\midterm01.txt", "r+");

    char inputID[50];
    printf("Enter the ID for delete book:");
    scanf("%s",inputID);

    book delb;
    
    while(feof(fp)!=1){
        fscanf(fp,"%s %s %s %s %d",delb.ID,delb.title,delb.name,delb.genre,&delb.copies);

        if(!strcmp(delb.ID,inputID)){
            strcpy(delb.ID,"");
            strcpy(delb.title,"");
            strcpy(delb.name,"");
            strcpy(delb.genre,"");
            delb.copies = 0;
        }
    }
    fclose(fp);


}

int main(){

    





    return 0;
}
#include <string.h>
#include<stdio.h>
int main(){
    // Declare the file pointer
    FILE *filePointer;
    char c;
    char info[50] = "Welcome to  World";
    filePointer = fopen("Assign.c", "w");

    if (filePointer == NULL){
        printf("Assign.c file failed to open.");
    }
    else{
        printf("The file is now opened.\n");
        if (strlen(info) > 0){
            fputs(info, filePointer);
            fputs("\n", filePointer);
        }

        printf("Data successfully written in file Assign.c\n");
        printf("The file is now closed.");
    }

    fclose(filePointer);

    printf("\n");
    filePointer=fopen("Assign.c","r");
    while( c != EOF){
        c= fgetc(filePointer);
        
        printf("%c",c);
    }
    fclose(filePointer);
    
    return 0;
}

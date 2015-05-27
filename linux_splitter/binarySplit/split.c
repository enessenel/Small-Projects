//Arman Garip - Enes Şenel 
//CS350 Project - Spring 2015

#include<stdio.h>
#include<stdlib.h>

int main(){
    char fileName[250], newFileName[250];
    int ch;
    long int size, n, k;
    int i;
    FILE *file, *tempFile;

    printf("Enter the file name to split (full path): ");
    scanf("%s", fileName);
    printf("How many parts: ");
    scanf("%ld", &n);

    file=fopen(fileName, "rb");
    if (file==NULL){
        printf("Can't open file");
        exit(0);
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);

    i = 1;
    k = size/n;
    rewind(file);
    sprintf(newFileName, "%s.%d", fileName, i);
    tempFile = fopen(newFileName, "wb");

    while(1){
        ch = fgetc(file);
        if (ch==EOF)
            break;
        fputc(ch, tempFile);
        if (ftell(file)==(i*(k+1))){
            i = i+1;
            fclose(tempFile);
            sprintf(newFileName, "%s.%d", fileName, i);
            tempFile=fopen(newFileName, "wb");
        }
    }
}
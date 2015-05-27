//Arman Garip - Enes Şenel 
//CS350 Project - Spring 2015

#include <stdio.h>
#include <stdlib.h>
 
int main(){
    char fileName[250], partName[250];
    int ch;
    long int size, k;
    int i;
    FILE *file, *tempFile; //file and temp file

    printf("Enter the file name to combine: ");
    scanf("%s", fileName);

    file=fopen(fileName, "wb");
    if (file==NULL){
        printf("Can't open file");
        exit(0);
    }

    i = 1;
    sprintf(partName, "%s.%d", fileName, i);
    tempFile = fopen(partName, "rb");

    while(1){
      if(tempFile == NULL) break;   
      ch = fgetc(tempFile);
      if(ch == EOF) {
         fclose(tempFile);
         i++;
         sprintf(partName, "%s.%d", fileName, i);
         tempFile = fopen(partName, "rb");
      }
      else {
         fputc(ch, file);
      }
    }

    fclose(file);

   return 0;
}
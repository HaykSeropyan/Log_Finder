#include <stdio.h>
#include <string.h>
#include <glob.h>


FILE *file;
char* words;
char sentence[500];
char *search_word;
char** found;
int r;
glob_t gstruct;

int main(int argc, char* argv[]){
    search_word = argv[1];

    r = glob("*.txt",GLOB_ERR, NULL, &gstruct);


    if(r != 0){
        if(r == GLOB_NOMATCH) {
            fprintf(stderr,"No Match./n");
        } else {
            fprintf(stderr,"Some Kind of glob error");
        }
        return -1;
    }

    printf("Found %zu file matches\n", gstruct.gl_pathc);
    
    found = gstruct.gl_pathv;


    while(*found){
        printf("looking in file: %s\n", *found);


        file = fopen(*found, "r");

         if(file == NULL) 
        {
            printf("could not open file, please try again\n"); 
            return -1;
        }
        while (fgets(sentence, 30, file) != NULL)
    {
            words = strtok(sentence," ");
            while(words)
        {
            if(strcmp(words,search_word) == 0)
            
                printf("found a match on %s in the file %s \n", words, *found);
                words = strtok(NULL, " ");
        }
        
        
    }
    found++;
    }

    fclose(file);



    


    

   
    





    return 0;
}
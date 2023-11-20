#include <stdio.h>
#include <stdlib.h>

int main(void){

    char projectName[20];
    char cmd[32];

    printf("Input project name: ");
    scanf("%[^\n]c", projectName);

    sprintf(cmd, "mkdir %s\\src", projectName);
    system(cmd);

    sprintf(cmd, "mkdir %s\\build", projectName);
    system(cmd);

    sprintf(cmd, "%s/src/main.cpp", projectName);

    FILE *file;
    file = fopen(cmd, "w");

    if(file == NULL){
        perror("Error creating file");
        return 1;
    }

    fprintf(file, "#include <stdio.h>\n\nint main(void){\n\n\n\n\treturn 0;\n}");
    fclose(file);
    
    sprintf(cmd, "%s/bnr.bat", projectName);

    file = fopen(cmd, "w");
        if(file == NULL){
        perror("Error creating bnr script");
        return 1;
    }

    fprintf(file, "cls\ngcc src/main.cpp -obuild/app.exe\ncd build\napp.exe\ncd ..");
    fclose(file);


    sprintf(cmd, "%s/bld.bat", projectName);

    file = fopen(cmd, "w");
        if(file == NULL){
        perror("Error creating build script");
        return 1;
    }

    fprintf(file, "cls\ngcc src/main.cpp -obuild/app.exe\n");
    fclose(file);

    return 0;
}

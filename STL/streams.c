#include <stdio.h>

int main(void)
{
    FILE* f = fopen("file.txt","w+" );

    fprintf(f, "Hello from write\n");

    fclose(f);



    // stdout
    printf("Hello from uart\n"); // define a FILE and let it point to your put char function





    return 0;
}
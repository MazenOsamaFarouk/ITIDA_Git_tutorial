#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

FILE *fp1, *fp2;

void print_usage()
{
    printf("Usage: hex -i <input.txt> -o <output.txt> \n");
    exit(2);
}

void read_input_file(char fileName[])
{
    fp1 = fopen(fileName, "r");
    if (fp1 == NULL) {
        printf("Error opening file %s\n", fileName);
        exit(1);
    }
}

void write_output_file(char fileName[])
{
    char c;
     fp2 = fopen(fileName, "w");
    if (fp2 == NULL) {
        printf("Error opening file %s\n", fileName);
        exit(1);
    }
    while ((c = fgetc(fp1)) != EOF) {
        fprintf(fp2, "%02X ", c);
    }
}

int main(int argc, char* argv[]) 
{
    if (argc<5)
    {
        print_usage();
    }
    int option;
    while ((option = getopt(argc,argv,"i:o:")) != -1)
    {
        switch (option)
        {
        case 'i':
            read_input_file(optarg);
            break;
        
        case 'o':
            write_output_file(optarg);
            break;
        
        default:
            print_usage();
            break;
        }
    }
    printf("File converted successfully.\n");

    fclose(fp1);
    fclose(fp2);
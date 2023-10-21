#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>

#define XFLAG 1
#define DFLAG 2

void PrintHelp(void);
void parse_input_file(FILE *input_file, FILE *output_file, int flag);
void parse_input_string(FILE *output_file, char input_string[], int flag);
void check_errors(short int iflag, short int oflag, short int operation_count);

int main(int argc, char *argv[])
{
    /*variables to parse my arguments and to hold what operation should be done*/
    int arguments = 0, operation_flag = 0;

    /*bunch of flags*/
    short int iflag = 0, oflag = 0, xflag = 0, dflag = 0;

    /*pointers to files that Iam gonna work with*/
    FILE *input_file = NULL, *output_file = NULL;

    /*if no valid input file provided just a buffer hold the optional argument as an array of chars*/
    char input_string[1024];

    while ((arguments = getopt(argc, argv, "i:o:hxd")) != -1)
    {
        switch (arguments)
        {
        case 'h':
            PrintHelp();
            exit(0);
            break;
        case 'i':
            input_file = fopen(optarg, "r"); /*open for read only file "must exist"*/
            /*if no valid file and string is provided save it in a char array*/
            if (input_file == NULL)
            {
                strcpy(input_string, optarg);
            }
            iflag++;
            break;
        case 'o':
            /*w+ opens an empty file for reading and writing if file exists its contents get destroyed*/
            output_file = fopen(optarg, "w+");
            oflag++;
            break;
        case 'x':
            xflag = XFLAG;
            break;
        case 'd':
            dflag = DFLAG;
            break;
        default:
            fprintf(stderr, "Error no valid arguments passed \n");
            exit(1);
            break;
        }
    }

    /*error check*/
    operation_flag = xflag + dflag;
    check_errors(iflag, oflag, operation_flag);

    /****************************************user input handling****************************************/
    /*There is two modes to work in here if user provided input file or input string user must provide one
    then if he passed an output file or not if the user provided input_file and output_file all is good
    if the user only provided input_file and no output_file the program will create an output file
    if the user provided input_string and no output_file will just print to stdout
    if the user provided input_string and output_file will convert and store in the output_file provided*/
    if (input_file)
    {
        parse_input_file(input_file, output_file, operation_flag);
    }
    else
    {
        parse_input_string(output_file, input_string, operation_flag);
    }

    if (input_file)  fclose(input_file);
    if (output_file) fclose(output_file);
    return 0;
}

void PrintHelp(void)
{
    printf("\n**************************Help**************************\n\n");

    printf("\n-i [input_file] you must provide an input file to be converted or an input string argument.\n");
    printf("\n-o [output_file] you can provide a file or not if u provide one it will be overwritten.\n");

    printf("\n-x to convert from ascii to hex.\n");
    printf("\n-d to convert from ascii to decimal.\n\n");
}

void parse_input_file(FILE *input_file, FILE *output_file, int flag)
{
    char c = 0;
    if (!output_file) output_file = fopen("output.txt", "w+");
    while ((c = fgetc(input_file)) != EOF)
    {
        if (c == '\n')
        {
            fprintf(output_file, "\n");
        }
        else if (flag == DFLAG)
        {
            fprintf(output_file, "%d ", c);
        }
        else if (flag == XFLAG)
        {
            fprintf(output_file, "%.2X ", c);
        }
    }
}

void parse_input_string(FILE *output_file, char input_string[], int flag)
{
    short int i = 0;
    while (input_string[i] != '\0')
    {
        if (output_file)
        {
            if (flag == DFLAG)
            {
                fprintf(output_file, "%d ", input_string[i]);
            }
            else if (flag == XFLAG)
            {
                fprintf(output_file, "%.2X ", input_string[i]);
            }
        }
        else
        {
            if (flag == DFLAG)
            {
                printf("%d ", input_string[i]);
            }
            else if (flag == XFLAG)
            {
                printf("%.2X ", input_string[i]);
            }
        }
        i++;
    }
}

void check_errors(short int iflag, short int oflag, short int operation_flag)
{
    if (operation_flag > 2 || operation_flag == 0) /*if more than one operations is provided or none > error*/
    {
        if (operation_flag)
        {
            fprintf(stderr, "\nCan only do one operation at a time you selected both operations can't be done at once, -h for help.\n\n");
        }
        else
        {
            fprintf(stderr, "\nYou didn't select any operation, -h for help.\n\n");
        }
        exit(1);
    }
    else if (iflag != 1) /*if no input is provided or more than one input > error*/
    {
        fprintf(stderr, "\nYou must provide one input and only one -h for help\n\n");
        exit(1);
    }
    else if (oflag > 1) /*if more than one output is given >> error*/
    {
        fprintf(stderr, "\nYou can only provide one output file or none. -h for help\n\n");
        exit(1);
    }
} /*175 lines xD*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>


int main(int argc, char *argv[]) 
{
    char *input_file;
    char *output_file;
    char c1,c2;	
    const char *short_options = "i:o:";
    int option;
    
    while ((option = getopt(argc, argv, short_options)) != -1)
	{
        switch (option) 
		{
            case 'i':
            {    input_file = optarg;
                break;
			}	
            case 'o':
			{
                output_file = optarg;
                break;
			}	
            case '?':
			{
				fprintf(stderr,"Wrong Format");
			}
        }
    }
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");   
   while ((c1 = fgetc(input)) != EOF)    
{
    char Hex_to_ASCII;
    char s1[2] = { '\0','\0' },
		 s2[2] = { '\0','\0' };

    c2 = fgetc(input);

    s1[0] = c1;
    s2[0] = c2;     

    Hex_to_ASCII = 16 * strtol(s1,NULL,16) + strtol(s2, NULL,16);

    fprintf(output, "%c", Hex_to_ASCII);
}
   
    fclose(input);
    fclose(output);
    return 0;
}
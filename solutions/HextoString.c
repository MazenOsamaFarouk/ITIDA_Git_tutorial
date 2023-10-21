#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>


int main(int argc, char *argv[]) 
{
    char *input;
    char *output;
    char c1,c2;	
    const char *options = "i:o:";
    int option;
    
    while ((option = getopt(argc, argv, options)) != -1)
	{
        switch (option) 
		{
            case 'i':
            {    input = optarg;
                break;
			}	
            case 'o':
			{
                output = optarg;
                break;
			}	
            case '?':
			{
				fprintf(stderr,"Wrong Format");
			}
        }
    }
    FILE *input1 = fopen(input, "r");
    FILE *output1 = fopen(output, "w");   
   while ((c1 = fgetc(input1)) != EOF)    
{
    char convert;
    char s1[2] = { '\0','\0' },
		 s2[2] = { '\0','\0' };

    c2 = fgetc(input1);

    s1[0] = c1;
    s2[0] = c2;     

    convert = 16 * strtol(s1,NULL,16) + strtol(s2, NULL,16);

    fprintf(output1, "%c", convert);
}
   
    fclose(input1);
    fclose(output1);
    return 0;
}
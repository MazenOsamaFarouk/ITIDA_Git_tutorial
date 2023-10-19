#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

void hex2alpha (FILE *input, FILE *output)
{
    int j = 0;
    char input_string[200];
    fgets(input_string, sizeof(input_string), input);
    int input_length = strlen(input_string);
    int length = input_length / 2;
    char out_str[length];
    for (int i = 0; i < length; i++)
	{
        char c[3];
        c[0] = input_string[i * 2];
        c[1] = input_string[i * 2 + 1];
        c[2] = '\0';
        char ch;
        sscanf(c,"%hhx", &ch); 
        out_str[j] = ch;
        j++;
    }
    out_str[j] = '\0';
    fprintf(output, "%s", out_str);
}


int main(int argc, char *argv[]) 
{
	//printf("Entered main\n");
	int option;
	char *c_input;
	char *c_output;
	const char *ch_option = "i:o:";

	while(option != -1)
	{
		option = getopt(argc, argv , ch_option);
		switch (option)
		{
			case 'i' :
			//printf("you want input\n");
			c_input = optarg;
			break;

			case 'o':
			//printf("you want output\n"); 
			c_output = optarg;
			break;

			case '?':
			fprintf(stderr, "Wrong Flag\n");
			break;
		}
	}

	FILE *f_input = fopen(c_input, "r");
	FILE *f_output = fopen(c_output, "w");
	hex2alpha (f_input, f_output);
   	fclose(f_input);
	fclose(f_output);


	return 0;
}

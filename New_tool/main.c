#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

void conv ( FILE *in , FILE *out )
{
  int j = 0 ;
  char Hstring [100];
  fgets(Hstring, sizeof(Hstring),in);
  int Lenght = strlen (Hstring);
  if (Lenght % 2 != 0)
  {
     fprintf(stderr,"The number is not in Hexa");
  }
  int string_length = Lenght / 2; 
  char new_string[string_length];
  for (int i = 0 ; i < string_length ; i++ )
  {
   char Temp [3];
   Temp[0]=Hstring[i*2];
   Temp[1]=Hstring[i*2+1];
   Temp[2]='\0';
   char character ; 
   sscanf (character , "%hxx",&character);
   new_string[j]=character;
   j++;
  
  } 
  new_string[j]= '\0';
  fprintf(out,"%s",new_string);

}



int main (int argc , char * argv[])
{
	char *input ;
	char *output ;
	const char *s_option = "i:o:";
	int option;
	
	while ((option = getopt(argc,argv,s_option)) != -1);
	{
	  switch (option)
	  {
	    case 'i' : 
	    {
	     input = optarg;
	     break;
	    }
	    case 'o' : 
	    {
	     output = optarg;
	     break;
	    }
	    case '?' : 
	    {
	     fprintf (stderr,"undifined flag");
	     break;
	    }
	  }
	}
  FILE *in  = fopen (input,"r");
  FILE *out = fopen (output,"w");
  conv (in ,out);
  fclose (in);
  fclose (out);

  return 0 ;
}	

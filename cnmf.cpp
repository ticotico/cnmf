#include <stdio.h> 
#include <string.h>

#define size_getline 4096

main(int argc, char *argv[])
{
	FILE *popennmf;
	char getline[size_getline];
	int len_argv;
	
	printf("-------------------------------------------------------------\n");
	printf("cnmf v1.00 test version.\n");
	printf("Useage: cnmf [filename] match pattern 1 match pattern 2...etc\n");
	printf("-------------------------------------------------------------\n");
	
	if(argc != 1)
	{
		popennmf = fopen(argv[1], "r");
		if(popennmf == NULL)
		{
			printf("Open %s fail.", argv[1]);
		}
		else
		{
			printf("Open: %s\n", argv[1]);
			while(!feof(popennmf))
			{
				fgets(getline, size_getline, popennmf);
				for(int i = 2; i < argc; i++)
				{
					len_argv = 0;
					while(argv[i][++len_argv] != NULL);
					if(strncmp(getline, argv[i], len_argv) == 0)
					{
						printf("%s", getline);
					}
				}
			}
			fclose(popennmf);
		}
	}
	
	
	return 0;
}

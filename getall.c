#include "cnmf.h"

int getall(int argc, char *argv[])
{
	printf("call getall\n");
	FILE *popennmf;
	char read_line[size_read_line];
	int len_argv;
	int i;
	
	
	if(argc > 3)
	{
		popennmf = fopen(argv[2], "r");
		if(popennmf == NULL)
		{
			printf("Open %s fail.", argv[2]);
		}
		else
		{
			printf("Open: %s\n", argv[2]);
			while(!feof(popennmf))
			{
				fgets(read_line, size_read_line, popennmf);
				for(i = 3; i < argc; i++)
				{
					len_argv = 0;
					while(argv[i][++len_argv] != NULL);
					if(strncmp(read_line, argv[i], len_argv) == 0)
					{
						printf("%s", read_line);
					}
				}
			}
			fclose(popennmf);
			

		}
	}
	
	return 0;
}

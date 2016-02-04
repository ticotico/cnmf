#include <stdio.h>
#include <string.h>

#define size_read_line 8000

int getnll(int argc, char *argv[])
{
	//printf("call getnll\n");
	FILE *popennmf;
	char read_line[size_read_line];
	int len_argv;
	int i;
	int is_print;
	
	
	if(argc > 3)
	{
		popennmf = fopen(argv[2], "r");
		if(popennmf == NULL)
		{
			printf("Open %s fail.", argv[2]);
		}
		else
		{
			//printf("Open: %s\n", argv[2]);
			while(!feof(popennmf))
			{
				fgets(read_line, size_read_line, popennmf);
				is_print = 1;
				for(i = 3; i < argc; i++)
				{
					len_argv = 0;
					while(argv[i][++len_argv] != '\0');
					if(strncmp(read_line, argv[i], len_argv) == 0)
					{
						is_print = 0;
					}
				}
				
				if(is_print) {
					printf("%s", read_line);
				}
			}
			fclose(popennmf);
			

		}
	}
	
	return 0;
}

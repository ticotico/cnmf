#include <stdio.h>
#include <string.h>

#define size_read_line 8000
#define no_match 0
#define find 1

int cnmflost(int argc, char *argv[])
{
	//printf("call cnmflost\n");
	FILE *popennmf;
	char read_line[size_read_line];
	int len_argv, flag;
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
			//printf("Open: %s\n", argv[2]);
			for(i = 3; i < argc; i++)
			{
				flag = no_match;
				len_argv = 0;
				while(argv[i][++len_argv] != '\0');
				
				while(!feof(popennmf))
				{
					fgets(read_line, size_read_line, popennmf);
					if(flag == no_match && strncmp(read_line, argv[i], len_argv) == 0)
					{
						flag = find;
					}
					
				}
				
				if(flag == no_match)
				{
					printf("No %s line.\n", argv[i]);
				}
				rewind(popennmf);
				
			}
			
			fclose(popennmf);
			

		}
	}
	
	return 0;
}

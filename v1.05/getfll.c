#include <stdio.h>
#include <string.h>

#define size_read_line 8000
#define size_output_buf 8000

int getfll(int argc, char *argv[])
{
	//printf("call getfll\n");
	FILE *popennmf;
	char read_line[size_read_line], output_buf[size_output_buf];
	char *poutput_buf[argc];
	int len_argv, len_output_buf = 0;
	int i;
	
	for(i = 0; i < argc; i++)
	{
		poutput_buf[i] = NULL;
	}
	
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
				for(i = 3; i < argc; i++)
				{
					len_argv = 0;
					while(argv[i][++len_argv] != '\0');
					if(poutput_buf[i] == NULL && strncmp(read_line, argv[i], len_argv) == 0)
					{
						poutput_buf[i] = output_buf + len_output_buf;
						strcat(output_buf + len_output_buf, read_line);
						len_output_buf += strlen(read_line) + 1;
					}
				}
			}
			fclose(popennmf);
			
			for(i = 3; i < argc; i++)
			{
				if(poutput_buf[i] != NULL)
					printf("%s", poutput_buf[i]);
				else
					printf("There is no %s\n", argv[i]);
			}
		}
	}
	
	return 0;
}

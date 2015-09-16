#include "cnmf.h"

int getfll(int argc, char *argv[])
{
	printf("call getfll\n");
	FILE *popennmf;
	char read_line[size_read_line], output_buf[size_output_buf];
	char *poutput_buf[argc];
	int len_argv, len_output_buf = 0;
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
						poutput_buf[i] = output_buf + len_output_buf;
						strcat(output_buf + len_output_buf, read_line);
						len_output_buf += strlen(read_line) + 1;
					}
				}
			}
			fclose(popennmf);
			
			for(i = 3; i < argc; i++)
			{
				printf("%s", poutput_buf[i]);
			}
		}
	}
	
	return 0;
}

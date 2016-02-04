#include <stdio.h>
#include <string.h>

#define size_read_line 8000
#define size_output_buf 8000

int getlll(int argc, char *argv[])
{
	//printf("call getlll\n");
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
			//printf("Open: %s\n", argv[2]);
			for(i = 3; i < argc; i++)
			{
				len_argv = 0;
				while(argv[i][++len_argv] != '\0');
				
				while(!feof(popennmf))
				{
					fgets(read_line, size_read_line, popennmf);
					if(strncmp(read_line, argv[i], len_argv) == 0)
					{
						strcpy(output_buf, read_line);
					}
					
				}
				if(output_buf[0] != '\0')
					printf("%s", output_buf);
				else
					printf("There is no %s.\n", argv[i]);
				rewind(popennmf);
				output_buf[0] = '\0';
			}
			
			fclose(popennmf);
			
		}
	}
	return 0;
} 

#include <stdio.h> 
#include <string.h>

main(int argc, char *argv[])
{	
	if (argc != 1)
	{
		if(strcmp(argv[1], "getfll") == 0)
		{
			getfll(argc, argv);
		}
		else if(strcmp (argv[1], "getall") == 0)
		{
			getall(argc, argv);
		}
		else if(strcmp (argv[1], "getlll") == 0)
		{
			getlll(argc, argv);
		}
		else if(strcmp (argv[1], "lost") == 0)
		{
			cnmflost(argc, argv);
		}
		else if(strcmp (argv[1], "getnll") == 0)
		{
			getnll(argc, argv);
		}
	}
	else
	{
		useage();
	}
	
	
	return 0;
}

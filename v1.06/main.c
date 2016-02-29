#include <stdio.h>
#include <string.h>
#include "cnmf.h"
void useage();

int main(int argc, char *argv[])
{
	int count = -1;
	
	if (argc < 4) {
		useage();
		return 0;
	}
	else {
		if (strncmp(argv[1], "getfll", 6) == 0)
			count = cnmf_fun(argv[2], argv[3], NULL, print_fll);
		else if (strncmp(argv[1], "getall", 6) == 0)
			count = cnmf_fun(argv[2], argv[3], NULL, print_all);
		else if (strncmp(argv[1], "getnll", 6) == 0)
			count = cnmf_fun(argv[2], argv[3], NULL, print_nll);
		else if (strncmp(argv[1], "getlll", 6) == 0)
			count = cnmf_fun(argv[2], argv[3], NULL, print_lll);
	}
	//printf("count = %d\n", count);
	return 0;
}

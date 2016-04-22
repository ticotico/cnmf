/*
105/04/22 v10601 把 argv 抓進來的指令字串 (cnmf_fun_str ) 
	 與 對應的函式指標 (cnmf_fun_mode mode) 用陣列引數連結 
	 增加程式可讀擴充性 
*/

#include <stdio.h>
#include <string.h>
#include "cnmf.h"

void useage();



int main(int argc, char *argv[])
{
	enum{cnmf_fun_count = 4};
	const char cnmf_fun_str[cnmf_fun_count][7] = 
		{"getfll", "getall", "getall", "getlll"};
	cnmf_fun_mode mode[cnmf_fun_count] = 
		{print_fll, print_all, print_nll, print_lll};

	int count = -1;
	
	if (argc < 4) {
		useage();
		return 0;
	}
	else {
		int i;
		for (i = 0; i < cnmf_fun_count; i++)
			if (strcmp(argv[1], cnmf_fun_str[i]) == 0) {
				count = cnmf_fun(argv[2], argv[3], NULL, mode[i]);
				break;
			}
	}
	//printf("count = %d\n", count);
	return 0;
}

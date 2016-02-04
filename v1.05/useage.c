#include <stdio.h> 

void useage()
{
	printf("-------------------------------------------------------------\n");
	printf("cnmf v1.05\n");
	printf("If you find any bug, contect auther by send mail to beranabus@hsing-yard.com\n\n");
	printf("Useage: cnmf <command> <filename> <lines1> <lines2> ...\n");
	printf("\n<commands>\n");
	printf("getfll\t\tget first specific lines in logfile.\n");
	printf("getall\t\tget all specific lines in logfile.\n");
	printf("getlll\t\tget last specific lines in logfile.\n");
	printf("lost\t\tfind if sepcific lines in logfile.\n");
	printf("getnll\t\tget all exclude specific lines in logfile.\n");

	printf("-------------------------------------------------------------\n");
}

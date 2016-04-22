#include <stdio.h>
#include <stdlib.h> //for exit
#include <string.h> //for strlen strncmp
#define LOG_LINE_MAX_LEN 10000

int print_fll(const char *log_line_buf, int equal_to_message , FILE *fp_out)
{
	static int flag = 0;
	if (equal_to_message && flag == 0) {
		fputs(log_line_buf, fp_out);
		flag = 1;
		return 1;
	}
	else return 0;
}

int print_all(const char *log_line_buf, int equal_to_message , FILE *fp_out)
{
	if (equal_to_message)
		fputs(log_line_buf, fp_out);
	return equal_to_message;
}

int print_nll(const char *log_line_buf, int equal_to_message , FILE *fp_out)
{
	if (!equal_to_message) {
		fputs(log_line_buf, fp_out);
		return 1;
	}
	else return 0;
}

int print_lll(const char *log_line_buf, int equal_to_message , FILE *fp_out)
{
	static int flag = 0;
	if (equal_to_message == 0) return 0;
	else if(equal_to_message == 1) {
		if (flag == 1) return 0;
		if (flag == 0) {
			flag = 1;
			return 1;
		}
	}
	else if (equal_to_message == -1) {
		fputs(log_line_buf, fp_out);
		return 0;
	}
	else return -1;
}

int cnmf_fun (const char *filename_in, const char *message, const char *filename_out,
  int(*mode)(const char *, int , FILE *))
{
	int match_count = 0, message_len = strlen(message), equal_to_message;
	FILE *fp_in, *fp_out;
	char log_line_buf[LOG_LINE_MAX_LEN];
	long match_pos = 0, cur_pos = 0;
	//open input and output files
	fp_in = fopen(filename_in, "rb");
	if (fp_in == NULL) {
		printf("open fail: %s\n", filename_in);
		exit(-1);
	}
	if (filename_out == NULL)
		fp_out = stdout;
	else fp_out = fopen(filename_in, "wb");
	if (fp_out == NULL) {
		printf("open fail: %s\n", filename_out);
		exit(-1);
	}
	//read log and do output
	fgets(log_line_buf, LOG_LINE_MAX_LEN, fp_in);
	while (!feof(fp_in)) {
		equal_to_message = (strncmp(log_line_buf, message, message_len) == 0);
		if (equal_to_message) match_pos = cur_pos;
		match_count += mode(log_line_buf, equal_to_message, fp_out);
		cur_pos = ftell(fp_in);
		fgets(log_line_buf, LOG_LINE_MAX_LEN, fp_in);
	}
	if (mode == print_lll && match_count == 1) {
		fseek(fp_in, match_pos, SEEK_SET);
		fgets(log_line_buf, LOG_LINE_MAX_LEN, fp_in);
		print_lll(log_line_buf, -1, fp_out);
	}
	
	//close input and output files
	if (filename_out != NULL)
		fclose(fp_out);
	fclose(fp_in);
  	return match_count;
}

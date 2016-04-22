#ifndef CNMF_H
#define CNMF_H
typedef int (*cnmf_fun_mode) (const char *, int , FILE *) ;

int print_fll(const char *log_line_buf, int equal_to_message , FILE *fp_out);
int print_all(const char *log_line_buf, int equal_to_message , FILE *fp_out);
int print_nll(const char *log_line_buf, int equal_to_message , FILE *fp_out);
int print_lll(const char *log_line_buf, int equal_to_message , FILE *fp_out);
int cnmf_fun (const char *filename_in, const char *message, const char *filename_out,
  cnmf_fun_mode);
#endif

#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define buf_size_for_tok 128
#define delim_for_tok " \t\r\n\a"

extern char **environ;

/**
 * struct data - abcd
 * @av: a
 * @input: b
 * @arg_list: c
 * @status: d
 * @keep_count: e
 * @cus_env: f
 * @pid: g
 */
typedef struct data
{
	char **av;
	char *input;
	char **arg_list;
	int status;
	int keep_count;
	char **cus_env;
	char *pid;
} my_struct;

/**
 * struct div_all_list_s - a linked list
 * @divider: a
 * @next: b
 * Description: abc
 */
typedef struct div_all_list_s
{
	char divider;
	struct div_all_list_s *next;
} div_all_list;

/**
 * struct list_of_all_lines_s - list
 * @line: a
 * @next: b
 * Description: abc
 */
typedef struct list_of_all_lines_s
{
	char *line;
	struct list_of_all_lines_s *next;
} list_of_all_lines;

/**
 * struct len_of_var_list - list
 * @len_var: a
 * @val: b
 * @len_val: c
 * @next: d
 * Description: abc
 */
typedef struct len_of_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct len_of_var_list *next;
} len_of_var;

/**
 * struct struct_for_buit_str - cmd
 * @name: name
 * @f: type
 * Description: no description
 */
typedef struct struct_for_buit_str
{
	char *name;
	int (*f)(my_struct *placeholder);
} struct_for_buit;

div_all_list *join_node_at_end(div_all_list **head, char sep);
void call_free_on_list(div_all_list **head);
list_of_all_lines *add_line_node_end(list_of_all_lines **head, char *line);
void call_free_on_all_lines(list_of_all_lines **head);
len_of_var *var_join_node(len_of_var **head, int lvar, char *var, int lval);
void release_all_rvar_list(len_of_var **head);
char *custom_cat(char *dest, const char *src);
char *custom_cpy(char *dest, char *src);
int custom_cmp(char *s1, char *s2);
char *custom_chr(char *s, char c);
int custom_spn(char *s, char *accept);
void custom_mem_cpy(void *newptr, const void *ptr, unsigned int size);
void *custom_reallocate(void *ptr, unsigned int o, unsigned int n);
char **cus_re_dp(char **ptr, unsigned int o, unsigned int n);
char *custom_dup(const char *s);
int custom_len(const char *s);
int cmp_chars(char str[], const char *delim);
char *custom_tok(char str[], const char *delim);
int check_digit(const char *s);
void custom_string_rev(char *s);
int err_chech_rep(char *input, int i);
int err_separate_ops(char *input, int i, char last);
int find_first_character(char *input, int *i);
void custom_perror_1(my_struct *placeholder, char *input, int i, int bool);
int custom_perror_0(my_struct *placeholder, char *input);
char *shell_loop_2_1(char *in);
void shell_loop_2(my_struct *placeholder);
char *line_reading_cmd(int *i_eof);
char *exchange_char(char *input, int bool);
void node_join_new(div_all_list **hs, list_of_all_lines **hl, char *in);
void n_m_t_n(div_all_list **s, list_of_all_lines **l, my_struct *pl);
int div_inputed_cmd(my_struct *placeholder, char *input);
char **tokenize_a_line(char *input);
void check_in_en(len_of_var **h, char *in, my_struct *data);
int check_in_vars(len_of_var **h, char *in, char *st, my_struct *data);
char *sub_input_with_another(len_of_var **h, char *i, char *ne, int n);
char *sub_value(char *input, my_struct *placeholder);
void carrier(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
int custom_execveee(my_struct *placeholder);
int check_is_cmd(char *path, int *i);
char *check_which(char *cmd, char **cus_env);
int check_execute(my_struct *placeholder);
int check_cmd_error(char *dir, my_struct *placeholder);
int custom_exe(my_struct *placeholder);
char *custom_getcustom_enviroment_var(const char *n, char **c);
int custom_enviroment(my_struct *placeholder);
char *info_cpy(char *name, char *value);
void setcustom_enviroment(char *name, char *value, my_struct *placeholder);
int custome_set_env(my_struct *placeholder);
int custome_unset_env(my_struct *placeholder);
void cmd_cd_present(my_struct *placeholder);
void cmd_cd_future(my_struct *placeholder);
void cd_previous(my_struct *placeholder);
void cmd_cd_future_home(my_struct *placeholder);
int cmd_cchange_shell(my_struct *placeholder);
int (*func_get_builtin(char *cmd))(my_struct *placeholder);
int func_quit(my_struct *placeholder);
int func_len_get(int n);
char *func_a_to_i(int n);
int func_a_to_i_2(char *s);
char *abc1(my_struct *, char *, char *, char *);
char *abc2(my_struct *placeholder);
char *abc3(my_struct *placeholder);
char *abc4(my_struct *placeholder);
char *abc5(char **arg_list);
char *abc6(my_struct *placeholder);
char *abc7(char **arg_list);
char *abc8(char **arg_list);
char *abc9(my_struct *placeholder);
int abc10(my_struct *placeholder, int eval);
void abc11(int sig);
void ay1(void);
void ay2(void);
void ay3(void);
void ay4(void);
void ay5(void);
void ay6(void);
void ay7(void);
void ay8(void);
int custom_helper_func(my_struct *placeholder);
void bring_line(char **lineptr, size_t *n, char *buf, size_t j);
int cmpcustom_enviroment_name(const char *t, const char *p);
#endif

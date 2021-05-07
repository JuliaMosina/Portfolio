/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 00:05:26 by alanora           #+#    #+#             */
/*   Updated: 2021/01/27 00:11:39 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct			s_command
{
	char				*one_command;
	int					pipe;
	int					stdin;
	int					stdout;
	int					stderr;
	struct s_command	*before;
	struct s_command	*next;
}						t_command;

typedef struct			s_array
{
	unsigned int		key_length;
	char				*key;
	void				*value;
	short int			flag;
	struct s_array		*before;
	struct s_array		*next;
}						t_array;

typedef struct			s_system
{
	int					exit;
	short int			pipe;
	int					argc;
	char				**argv;
	int					is_keyboard;
	int					status;
	int					status_in_str;
	char				*status_str;
	char				*status_message;
	char				*home;
	char				*local;
	t_array				*commands;
	t_array				*environ;
	int					stdin;
	int					stdin_mine;
	int					stdout;
	int					stdout_mine;
	int					stderr;
	int					stderr_mine;
}						t_system;

int						minishell_run(int argc, char **argv, char **env);
void					set_default(t_system *minishell, char **env);
void					set_env(t_system *minishell, char **env);
int						set_str_to_array(t_array **array, char *key,
						char *value);
void					set_commands(t_array **array);
int						set_commands_to_array(t_array **array, char *key,
								int (*function)(t_system *, char *));
t_array					*set_null_to_array(t_array **array, char *key);
void					main_parser(t_system *minishell, char *str);
t_array					*find_in_array(t_array *array, char *key);
int						to_start_array(t_array **array);
int						to_end_array(t_array **array);
void					*get_from_array(t_array *array, char *key);
int						destroy_array(t_array **array);
int						drop_elem_in_array(t_array *array);
int						incoming_echo(t_system *minishell, char *str);
int						incoming_env(t_system *minishell, char *str);
void					main_reader(t_system *minishell);
void					sys_destroy(t_system *minishell);
int						get_next_input(t_system *minishell, char **str);
int						skip_space(char **str);
int						char_in_array(char c, char *str);
int						is_work_sym(char *str, size_t i);
char					*get_word(char **str, char *divider);
int						word_and_env(t_system *minishell, char **str);
void					dell_slash(char **str, char ignore);
int						set_fd(int old_fd, int def_fd, int new_fd);
void					set_std_default(t_system *minishell);
int						set_status(t_system *minishell, int status);
char					*get_status(t_system *minishell);
char					*get_from_env_array(t_system *minishell, char *key);
int						check_env_key(char *str);
int						write_env_unit(t_system *minishell, char *str);
int						put_env(t_system *minishell, char *str);
int						incoming_export(t_system *minishell, char *str);
int						incoming_pwd(t_system *minishell, char *str);
int						incoming_unset(t_system *minishell, char *str);
int						delete_in_array(t_array **array, char *key);
char					*get_pwd(void);
void					set_env_value(t_system *minishell, char *key,
					char *value);
int						incoming_exec(t_system *minishell, char *str);
int						is_keyboard(t_system *minishell);
size_t					count_in_array(t_array *array);
char					*check_in_dir(char *path, char *command,
					int command_len);
char					**environ_value_to_array(t_system *minishell);
void					string_to_words(t_system *minishell, char **str,
							char ***array, int count);
void					free_words(char ***array);
int						exec_run(t_system *minishell, char *path, char *str);
int						incoming_exec(t_system *minishell, char *str);
char					*get_key_command(t_system *minishell, char **str);
void					system_error_message(t_system *minishell, char *str1,
								char *str2, char *str3);
int						incoming_cd(t_system *minishell, char *str);
int						path_router(t_system *minishell, char *word);
int						goto_path(t_system *minishell, char *path);
int						incoming_exit(t_system *minishell, char *str);
void					set_std_in_variable(t_system *minishell, char type,
							int fd);
int						syntax_error(t_system *minishell, char c, char *syntax,
						int pos);
int						check_file_and_access(t_system *minishell, char *path,
								char type);
char					*homework(t_system *minishell, char *str, int i);
char					*get_next_word(t_system *minishell, char **str);
int						open_std_file(t_system *minishell, char *filename,
					char type);
int						get_next_line_buffer(t_system *minishell, int fd,
							char **str);
void					handler_c(int sig);
t_command				*create_comm_struct(t_system *minishell,
								t_command *command);
void					close_fd_comm_struct(t_system *minishell,
							t_command **command);
void					del_comm_struct(t_system *minishell,
						t_command **command);
int						set_std_from_command(t_system *minishell,
							t_command *command);
void					run_comm_struct(t_system *minishell,
						t_command *command);
int						parse_str_to_command(t_system *minishell, char *str,
							t_command **command, char *divider);
void					parse_str_and_run(t_system *minishell, char *str);
int						parse_str_skip_words(char *str, int i, char *c,
							char *divider);
int						check_c(t_system *minishell, char c);
char					get_type_from_str(char **str, int *i, int *fd);
char					*get_path_from_str(char **str, int i);
int						router_parse_command(t_system *minishell, char **str,
							int *i, t_command **command);
int						is_hash(t_system *minishell, char **str, int *i,
				t_command **command);
int						is_semicolon(t_system *minishell, char **str,
					int *i, t_command **command);
int						is_pipe(t_system *minishell, char **str,
				int *i, t_command **command);
short int				if_text(char c);
void					get_next_word_add(t_system *minishell, char **str,
						char **word, int step);
size_t					set_env_to_str(t_system *minishell, char **str,
						size_t i);
char					*get_env_key(char *str, size_t *length);
void					error_code_output(t_system *minishell, int ret);
int						put_export(t_system *minishell);
char					**environ_key_to_array(t_system *minishell);
char					**environ_to_array(t_system *minishell, int type);
#endif

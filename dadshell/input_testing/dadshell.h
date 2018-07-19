/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dadshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:07:51 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/18 15:16:39 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef DADSHELL_H
#	define DADSHELL_H

#include <libft.h>
#include <ft_printf.h>
#include <get_next_line.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <dirent.h>

#define STD_ENV 2
#define BUILTINS 7
#define LINE_IN_CAP 50

const char		*g_quotes = "\'\"`";

void			dad_loop(int fd);
int				dadsh_launch(char **args);
int				dadsh_exec(char **args);
void			put_help_msg(void);

/*
** Process Execution
*/
int				dadsh_exec(char **args);
int				delta_exec(char *path, char **args);
static int		dadsh_run(char *path, char **args);

/*
** Helper
*/

int				print_env(void);
void			init_envv(char **env);
int				find_envv(char *var);
char			**realloc_envv(int new_size);
char			*ft_prepend_str(char *prefix, char *suffix);
char			*get_envv_val(char *envv_str);
char			*split_envv_key(char *envv_str);
int				inside_cwd(char *path);
char			*ft_prepend_str(char *prefix, char *suffix);
/*
** Signal Handling
*/
void			dad_signal(int sig);
void			dad_psignal(int sig);

/*
** Built-Ins
*/
int				dad_cd(t_vector *args);
int				dad_echo(t_vector *args);
void			echo_out(t_vector *args);
int				dad_env(t_vector *args);
int				dad_setenv(t_vector *args);
int				dad_unsetenv(t_vector *args);
int				dad_help(t_vector *args);
int				dad_exit(t_vector *args);

typedef	int		(*t_dadfunc)(t_vector *args);

static struct	s_builtin
{
	char		*name;
	size_t		tokenlen;
	t_dadfunc	dadfunc;
}
t_builtin[BUILTINS] = {
	{"cd", 2, &dad_cd},
	{"echo", 4, &dad_echo},
	{"env", 3, &dad_env},
	{"setenv", 6, &dad_setenv},
	{"unsetenv", 8, &dad_unsetenv},
	{"help", 4, &dad_help},
	{"exit", 4, &dad_exit}
};

#	endif

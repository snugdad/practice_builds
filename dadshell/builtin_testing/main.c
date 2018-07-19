/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 11:17:20 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/18 13:21:57 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dadshell.h"

int		dad_help(t_vector *v)
{
	ft_printf("help_function\n");
	return(1);
}

int		dad_setenv(t_vector *args)
{
	ft_printf("setenv_function\n");
	return(1);
}

int		dad_echo(t_vector *args)
{
	ft_printf("echo_function\n");
	return(1);
}

int		dad_unsetenv(t_vector *args)
{
	ft_printf("unset_function\n");
	return(1);
}

int		dad_exit(t_vector *args)
{
	ft_printf("exit_function\n");
	return(1);
}

int 	dad_cd(t_vector *args)
{
	ft_printf("cd_function\n");
	return(1);
}

int				dad_env(t_vector *args)
{
	ft_printf("env_function\n");
	return (1);
}

int main(int ac, char **av)
{
	
	t_vector	v;
	int			i;

	if ((ac == 2) && ~ft_vector_init(&v, ft_strlen(av[1] + 50)))
	{
		ft_vector_append(&v, av[1]);
		for(i = 0; i < BUILTINS; i++) {
			if(ft_strncmp(v.data, t_builtin[i].name, t_builtin[i].tokenlen) == 0)
				t_builtin[i].dadfunc(normalize(v.data));
		}
		
	}
	return 0;	
}
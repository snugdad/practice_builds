/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:27:15 by egoodale          #+#    #+#             */
/*   Updated: 2018/07/18 19:45:29 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dadshell.h"


void		quote_mismatch_message(char quote)
{
	char *msg;

	if (quote == '\'')
		ft_printf("\nsquote> ");
	else if (quote == '\"')
		ft_printf("\ndquote> ");
	else
		ft_printf("\nbquote> ");
}

char		*normalize_arguments(t_vector *linev, char *opnq, size_t app)
{
	if (!opnq)
		return (NULL);
	if (!clsq)
		return (opnq);
	if (opnq > concat)
	{
		if(concat == linev->data)
			ft_subvector_slide(linev, opnq, concat, 1);
		else
			ft_subvector_slide(linev, opnq, concat + 1, 1);
	}
	if (clsq < (concat + app) - 1)
	{
		if(opnq = find_next_any((clsq + 1), g_quotes)
			ft_subvector_slide(linev, opnq, (clsq + 1), 1);
		else
		{
			ft_subvector_slide(linev, clsq, clsq + app, 1);
			return(clsq + app)
		}
	}
	return (clsq);
}

char	*dad_input(int fd)
{
	t_vector	linev;
	size_t		mismatch;
	char		*line;
	size_t		len;
	char *		nextq;
	int first = 1;
	mismatch = 0;
	clsq = linev.data
	if (~ft_vector_init(&linev, LINE_IN_CAP))
	{
		clsq = linev.data;
		while (~(get_next_line(fd, &line)))
		{
			
			len = ft_strlen(line);
			ft_vector_append(&linev, line);
			opnq = find_next_any(clsq, g_quotes)
			clsq = opnq ? ft_strchr(opnq + 1, *opnq) : opnq;
			opnq = normalize_arguments(&linev, opnq, app);
			if(!*(opnq) || !opnq)
				break ;
			quote_mismatch_message(*(find_next_any(line, g_quotes)));

		
		}
	}
	return (linev.data);
}

int main(void)
{
	char	*args;
	int		fd;

	fd = open("/dev/ttys001", O_RDONLY);
	args = dad_input(fd);
	ft_printf("%s", args);
}
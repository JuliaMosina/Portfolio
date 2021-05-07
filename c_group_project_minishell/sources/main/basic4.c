/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:01:29 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 17:14:33 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** outputs mistake in appropriate fd
*/

void			system_error_message(t_system *minishell, char *str1,
									char *str2, char *str3)
{
	ft_putstr_fd("minishell: ", minishell->stderr);
	if (str1)
		ft_putstr_fd(str1, minishell->stderr);
	if (str2)
		ft_putstr_fd(str2, minishell->stderr);
	if (str3)
		ft_putstr_fd(str3, minishell->stderr);
	ft_putchar_fd('\n', minishell->stderr);
}

/*
** outputs syntax errors
*/

int				syntax_error(t_system *minishell, char c, char *syntax, int pos)
{
	if (!pos || syntax[pos + 1] == c)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `",
					minishell->stderr);
		while (syntax[pos] && (syntax[pos] == c))
		{
			if (syntax[pos] == c)
				ft_putchar_fd(c, minishell->stderr);
			pos++;
		}
		ft_putstr_fd("'\n", minishell->stderr);
		set_std_default(minishell);
		set_status(minishell, 2);
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 05:29:16 by student           #+#    #+#             */
/*   Updated: 2020/05/16 20:49:40 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*n_s(char *str, size_t mem_f, size_t step)
{
	size_t	step_loc;
	char	*new_str;

	if (!*str)
		mem_f = step + 1;
	new_str = (char *)malloc(sizeof(char) * ((step - mem_f) + 2));
	if (!new_str)
		return (0);
	step_loc = 0;
	while (mem_f <= step)
	{
		new_str[step_loc] = str[mem_f];
		step_loc++;
		mem_f++;
	}
	new_str[step_loc] = '\0';
	return (new_str);
}

static int	search_sym(char part_str, char *sym)
{
	while (*sym)
	{
		if (part_str == *sym)
			return (1);
		sym++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*sym;
	size_t	mem_f;
	size_t	step;

	if (!s1 || !set)
		return (0);
	str = (char *)s1;
	sym = (char *)set;
	step = 0;
	while (str[step] && search_sym(str[step], sym))
		step++;
	mem_f = step;
	while (str[step])
		step++;
	if (step)
		step--;
	while (step > mem_f && search_sym(str[step], sym))
		step--;
	return (n_s(str, mem_f, step));
}

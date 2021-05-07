/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 09:27:33 by student           #+#    #+#             */
/*   Updated: 2020/05/17 23:10:47 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		make_substr(char ***rez, size_t targ, char *str, size_t len)
{
	size_t		step;

	(*rez)[targ] = (char *)malloc(sizeof(char) * (len + 1));
	if (!(*rez)[targ])
	{
		(*rez)[targ] = 0;
		return (0);
	}
	(*rez)[targ][len] = '\0';
	step = 0;
	while (step < len)
	{
		(*rez)[targ][step] = str[step];
		step++;
	}
	return (1);
}

static int		make_arr(char const *s, char ***rez, char c)
{
	size_t		count_str;
	char		*str;
	size_t		step;

	str = (char *)s;
	count_str = 0;
	step = 0;
	while (str[step])
	{
		if (str[step] == c && step)
		{
			if (!make_substr(rez, count_str, str, step))
				return (0);
			count_str++;
			str = str + step + 1;
			step = 0;
		}
		else if (str[step] != c)
			step++;
		else
			str++;
	}
	if (step)
		return (make_substr(rez, count_str, str, step));
	return (1);
}

static size_t	count_st(char *str, char c)
{
	size_t		count_str;
	int			is_zero;

	count_str = 1;
	is_zero = 1;
	while (*str)
	{
		if (*str == c && !is_zero)
		{
			count_str++;
			is_zero = 1;
		}
		else if (*str != c)
			is_zero = 0;
		str++;
	}
	if (count_str > 0 && is_zero)
		count_str--;
	return (count_str);
}

static void		clean_make_arr(char ***rez)
{
	char **loc;

	loc = *rez;
	while (*loc)
	{
		free(*loc);
		loc++;
	}
	free(*rez);
	*rez = 0;
}

char			**ft_split(char const *s, char c)
{
	size_t		count_str;
	char		*str;
	char		**rez;

	if (!s)
		return (0);
	str = (char *)s;
	count_str = count_st(str, c);
	rez = (char **)malloc(sizeof(char *) * (count_str + 1));
	if (!rez)
		return (0);
	rez[count_str] = 0;
	if (count_str)
		if (!make_arr(s, &rez, c))
			clean_make_arr(&rez);
	return (rez);
}

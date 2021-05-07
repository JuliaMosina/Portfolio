/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:30:27 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 16:31:19 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** cleans the array of strings where the arguments
** which were used for launching exec are saved
*/

void				free_words(char ***array)
{
	char			**temp;
	char			**temp2;

	temp = *array;
	while (*temp)
	{
		temp2 = temp + 1;
		free(*temp);
		temp = temp2;
	}
	free(*array);
	*array = NULL;
}

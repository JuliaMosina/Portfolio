/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:44:07 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 16:58:22 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** transition to the end of the succession
*/

int					to_end_array(t_array **array)
{
	if (array && *array && (*array)->next)
	{
		while ((*array)->next)
			*array = (*array)->next;
		return (1);
	}
	return (0);
}

/*
** transition to the beginning of the succession
*/

int					to_start_array(t_array **array)
{
	if (array && *array && (*array)->before)
	{
		while ((*array)->before)
			*array = (*array)->before;
		return (1);
	}
	return (0);
}

/*
** searches and returns specified element of the succession
*/

t_array				*find_in_array(t_array *array, char *key)
{
	t_array			*temp;
	unsigned int	key_length;

	to_start_array(&array);
	temp = array;
	key_length = ft_strlen(key);
	while (temp)
	{
		if (temp->key_length == key_length && !ft_strncmp(temp->key,
													key, key_length))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

/*
** creates an element of the succession and nulls its value
*/

t_array				*set_null_to_array(t_array **array, char *key)
{
	t_array			*temp;

	temp = find_in_array(*array, key);
	if (!temp)
	{
		if (!(temp = (t_array *)malloc(sizeof(t_array))))
			return (0);
		temp->key = ft_strdup(key);
		temp->key_length = ft_strlen(key);
		temp->value = NULL;
		temp->next = *array;
		temp->before = NULL;
		if (temp->next)
			temp->next->before = temp;
		*array = temp;
		temp->flag = 0;
	}
	if (temp->flag && temp->value)
		free(temp->value);
	temp->value = NULL;
	return (temp);
}

/*
** using appropriate functions searches or creates element of succession
** and and sets duplicate of string transmitted as value
*/

int					set_str_to_array(t_array **array, char *key, char *value)
{
	t_array			*temp;

	if (!key)
		key = "";
	if (!value)
		value = "";
	temp = set_null_to_array(array, key);
	temp->value = ft_strdup(value);
	temp->flag = 1;
	return (1);
}

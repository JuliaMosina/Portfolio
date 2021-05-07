/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:44:07 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 16:58:22 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** searches an element of the succession and returns the value saved in it
*/

void				*get_from_array(t_array *array, char *key)
{
	t_array			*temp;

	temp = find_in_array(array, key);
	if (temp)
		return (temp->value);
	return (NULL);
}

/*
** counts elements in succession (from the very beginning to the end)
*/

size_t				count_in_array(t_array *array)
{
	size_t			count;

	to_start_array(&array);
	count = 0;
	while (array)
	{
		array = array->next;
		count++;
	}
	return (count);
}

/*
** searches and deletes specified element in the succession
*/

int					delete_in_array(t_array **array, char *key)
{
	t_array			*temp;

	temp = find_in_array(*array, key);
	if (temp)
	{
		if (temp->before)
		{
			temp->before->next = temp->next;
			if (temp->next)
				temp->next->before = temp->before;
		}
		else
		{
			temp->next->before = NULL;
			*array = temp->next;
		}
		return (drop_elem_in_array(temp));
	}
	return (0);
}

/*
** deletes specified element of the succession
*/

int					drop_elem_in_array(t_array *array)
{
	if (array->key)
		free(array->key);
	if (array->flag && array->value)
		free(array->value);
	free(array);
	return (1);
}

/*
** destroys the succession
*/

int					destroy_array(t_array **array)
{
	t_array			*temp;
	t_array			*temp1;

	to_start_array(array);
	temp = *array;
	while (temp)
	{
		temp1 = temp->next;
		drop_elem_in_array(temp);
		temp = temp1;
	}
	*array = NULL;
	return (0);
}

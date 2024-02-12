/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortmann <aortmann@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 06:26:31 by aortmann          #+#    #+#             */
/*   Updated: 2024/01/19 07:16:13 by aortmann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.*/

#include "libft.h"

char	**ft_helper(char **str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	ft_skip_characters(const char *s, char c, int index, int flag)
{
	if (flag == 0)
	{
		while (s[index] != '\0')
		{
			if (s[index] != c)
				return (index);
			index++;
		}
		return (index);
	}
	else
	{
		while (s[index] != '\0')
		{
			if (s[index] == c)
				return (index);
			index++;
		}
		return (index);
	}
}

static char	**create_arr_strings(const char *s, char c, int i)
{
	char	**str;
	int		size;

	i = ft_skip_characters(s, c, i, 0);
	if (s[i] == '\0')
		return (str = ft_calloc(1, sizeof(char *)));
	size = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i = ft_skip_characters(s, c, i, 0);
		if (s[i] != c && s[i] != '\0')
		{
			i = ft_skip_characters(s, c, i, 1);
			size++;
		}
	}
	return (str = ft_calloc(size + 1, sizeof(char *)));
}

static char	**delimeter(const char *s, char c, char **str, int index)
{
	int	i;
	int	size;

	i = 0;
	str = create_arr_strings(s, c, i);
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i = ft_skip_characters(s, c, i, 0);
		if (s[i] != c && s[i] != '\0')
		{
			size = ft_skip_characters(s, c, i, 1) - i;
			str[index] = ft_substr(s, i, size);
			if (!str[index])
				return (ft_helper(str, index));
			index++;
			i += size;
		}
	}
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**temp;
	char	**ret;
	int		index;

	index = 0;
	temp = (char **)malloc(sizeof(char *));
	if (temp == NULL)
	{
		return (NULL);
	}
	temp[0] = 0;
	if (s[0] == '\0')
		return (temp);
	ret = delimeter(s, c, temp, index);
	free(temp);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:16:08 by fbily             #+#    #+#             */
/*   Updated: 2022/09/20 17:44:54 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	count(char const *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == 0)
		return (0);
	if (str[i] != c)
		j++;
	i++;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			j++;
		i++;
	}
	return (j);
}

static char	**ft_free(char **back, int i)
{
	int	j;

	j = 0;
	while (j < i && back[j] != 0)
	{
		free(back[j]);
		j++;
	}
	free(back);
	return (0);
}

static char	**ft_alloc(char **back, char const *str, char c, int count)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (k < (count - 1))
	{
		j = 0;
		while (str[i] != '\0' && str[i] == c)
			i++;
		while (str[i] != '\0' && str[i] != c)
		{
			i++;
			j++;
		}
		back[k] = ft_calloc((j + 1), sizeof(char));
		if (back[k] == NULL)
			ft_free (back, k);
		k++;
		i++;
	}
	return (back);
}

static char	**ft_cpy(char **back, char const *str, char c, int count)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (k < (count - 1))
	{
		j = 0;
		while (str[i] != '\0' && str[i] == c)
			i++;
		while (str[i] != '\0' && str[i] != c)
		{
			back[k][j] = str[i];
			i++;
			j++;
		}
		back[k][j] = '\0';
		k++;
		i++;
	}
	back[count - 1] = NULL;
	return (back);
}

char	**ft_split(char const *s, char c)
{
	char	**back;
	int		words;

	if (s == NULL)
		return (NULL);
	words = count(s, c);
	words++;
	back = malloc(sizeof(char *) * words);
	if (back == NULL)
		return (NULL);
	ft_alloc(back, s, c, words);
	ft_cpy(back, s, c, words);
	return (back);
}

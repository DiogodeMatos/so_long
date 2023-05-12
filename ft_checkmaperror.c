/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmaperror.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:29:25 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/05/03 11:29:27 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_checkber(char **argv)
{
	static int	a;
	char	*str;
	int	b;

	str = ".ber";
	while (argv[1][a])
	{
		b = 0;
		while (argv[1][a] == str[b])
		{
				a++;
				b++;
				if (argv[1][a] == '\0' && str[b] == '\0')
					return (1);
				else if ((argv[1][a] == '\0' && str[b] != '\0') || (argv[1][a] != '\0' && str[b] == '\0'))
					a--;
		}
		a++;
	}
	write(1,"Error: Map need end in .ber to open", 28);
	return (0);
}

void	ft_checkmaperror(char **argv)
{
	ft_checkber(argv);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:46:41 by dcarrilh          #+#    #+#             */
/*   Updated: 2023/05/03 10:46:42 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_printf("%s", "Error: Invalid number of arguments"));
	ft_checkmaperror(argv);
	return (0);
}

/*int	main()
{
	ft_printf("so_long");
}*/

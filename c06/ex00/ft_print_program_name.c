/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongele <seongele@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 21:34:24 by seongele          #+#    #+#             */
/*   Updated: 2021/04/06 13:23:38 by seongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	while (*argv[argc - argc] != '\0')
		write(1, argv[argc - argc]++, 1);
	write(1, "\n", 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:22:19 by aabel             #+#    #+#             */
/*   Updated: 2023/05/09 15:10:40 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "../inc/libft_printf/libft.h"

void	ft_reception(int sig, siginfo_t *info, void *context);
void	send_bit(int pid, char str);
void	recep_len(int *bit_len, int sig, int *u, char *str);
#endif
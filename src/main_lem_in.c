/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lem_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:05:46 by arosset           #+#    #+#             */
/*   Updated: 2017/09/11 15:05:48 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int main()
{
	t_spec	*lem_param;

	lem_param = ft_init_struct_parser();
	ft_parser(lem_param);
    return (0);
}

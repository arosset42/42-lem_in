/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:50:51 by cjacques          #+#    #+#             */
/*   Updated: 2015/11/30 14:12:27 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = *alst;
	if (*alst == NULL || alst == NULL || new == NULL)
		return ;
	*alst = new;
	(*alst)->next = tmp;
}

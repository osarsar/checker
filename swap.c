/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:07:10 by osarsar           #+#    #+#             */
/*   Updated: 2023/02/18 17:32:22 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	t_list	*head;
	int		tmp;

	head = *stack_a;
	tmp = head->content;
	head->content = head->next->content;
	head->next->content = tmp;
}

void	sb(t_list **stack_b)
{
	t_list	*head;
	int		tmp;

	head = *stack_b;
	tmp = head->content;
	head->content = head->next->content;
	head->next->content = tmp;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

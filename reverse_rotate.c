/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:07:39 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/20 02:36:33 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*head;

	//printf("head = %d\n",(*stack_a)->content);
	head = *stack_a;
	while (head->next->next)
		head = head->next;
	ft_lstadd_front(stack_a, head->next);
	head->next = NULL;
}

void	rrb(t_list **stack_b)
{
	t_list	*head;

	head = *stack_b;
	while (head->next->next)
		head = head->next;
	ft_lstadd_front(stack_b, head->next);
	head->next = NULL;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

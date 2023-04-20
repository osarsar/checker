/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:07:31 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/17 21:11:08 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*head_next;

	head = *stack_b;
	head_next = head->next;
	ft_lstadd_front(stack_a, head);
	*stack_b = head_next;
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	t_list	*head_1;
	t_list	*head_2;

	head_1 = *stack_a;
	head_2 = head_1->next;
	ft_lstadd_front(stack_b, head_1);
	*stack_a = head_2;
}

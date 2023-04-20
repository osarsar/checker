/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:07:15 by osarsar           #+#    #+#             */
/*   Updated: 2023/02/18 17:33:38 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack_a;
	tmp = head->next;
	ft_lstadd_back(stack_a, head);
	*stack_a = tmp;
}

void	rb(t_list **stack_b)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack_b;
	tmp = head->next;
	ft_lstadd_back(stack_b, head);
	*stack_b = tmp;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

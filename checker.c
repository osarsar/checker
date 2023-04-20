#include "push_swap.h"

char	**split_stack(char **av)
{
	int		i;
	char	*string;
	char	**split;

	string = ft_strdup("");
	i = 1;
	while (av[i])
	{
		string = ft_strjoin(string, av[i]);
		string = ft_strjoin(string, " ");
		i++;
	}
	i = 0;
	split = ft_split(string, ' ');
	while (split[i])
	{
		check_valid_stack(split[i]);
		i++;
	}
	return (split);
}

int	creat_stack(t_list	*stack_a, char **split)
{
	t_list	*tab;
	int		i;

	i = 0;
	while (split[i])
	{
		tab = ft_lstnew(ft_atoi(split[i]));
		ft_lstadd_back(&stack_a, tab);
		i++;
	}
	free(stack_a);
	return (i);
}

void	check_same_number(t_list	*stack_a)
{
	t_list	*head;
	t_list	*head_1;

	head = stack_a;
	head_1 = stack_a->next;
	while (head->next)
	{
		head_1 = head->next;
		while (head_1)
		{
			if (head->content == head_1->content)
			{
				ft_putstr_fd("Error2", 2);
				exit(1);
			}
			head_1 = head_1->next;
		}
		head = head->next;
	}
}

int	check_valid_stack(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			if (str[i] <= '0' || str[i] >= '9')
				message_error();
		}
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] != ' ' && str[i])
			message_error();
		i++;
	}
	return (1);
}

void    parssing(char **av, t_list *stack_a)
{
    char **split; 
    split = split_stack(av);
	creat_stack(stack_a, split);
	check_same_number(stack_a);
}

int	size_stack(t_list *stack_a)
{
	t_list	*head;
	int		i;

	i = 0;
	head = stack_a;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	check_sort(t_list *stack_a)
{
	t_list	*head;
	int		i;

	i = 0;
	head = stack_a;
	size_stack(stack_a);
	head = stack_a;
	while (head->next)
	{
		if (head->content < head->next->content)
			i++;
		head = head->next;
	}
	if (i == size_stack(stack_a) - 1)
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 2);
}

int	ft_strcmp(char *s1, char *s2)
{
	char	*p1;
	char	*p2;
	size_t			i;

	i = 0;
	p1 = s1;
	p2 = s2;
	while ((p1[i] != '\0' || p2[i] != '\0') && p1[i] != '\n')
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	t_list  *stack_a;
	t_list  *stack_b;
	t_list	*head;
	char  *input;

	(void)ac;
	stack_a = ft_lstnew(42);
	stack_b = ft_lstnew(1337);
	parssing(av, stack_a);
	head = stack_a;
	input = get_next_line(0);
	//while (input != 'x')
	if (!ft_strcmp(input, "rra\n"))
		rra(&stack_a);
	if (!ft_strcmp(input, "ra\n"))
		ra(&stack_a);
	if (!ft_strcmp(input, "sa\n"))
		sa(&stack_a);
	//check_sort(stack_a);
	while(stack_a)
	{
		printf("sa = %d\n",stack_a->content);
		stack_a =stack_a->next;
	}

}

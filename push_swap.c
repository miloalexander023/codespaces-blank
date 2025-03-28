/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milalexa <milalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:21:47 by milalexa          #+#    #+#             */
/*   Updated: 2025/03/20 21:48:50 by milalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_node *stack_a)
{
	if (!stack_a || !stack_a->next)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	stack_len(t_node *stack)
{
  t_node *temp;
  int length;

  temp = stack;
	length = 0;
	if (temp == NULL)
		return (0);
  while (temp != NULL)
	{
    length++;
    temp = temp->next;
  }
  return (length);
}

int smallest_number(t_node *stack)
{	
	t_node *temp;
  int smallest;

	temp = stack;
	smallest = INT_MAX;
  while (temp != NULL)
	{	
		if (smallest > temp->value)
			smallest = temp->value;
    temp = temp->next;
  }
	printf("smallest = %d\n", smallest);
  return (smallest);
}

int	main(int argc, char**argv)
{
	t_node	*stack_a = NULL;
	int		num;
	int		i;

	i = 1;
	if (argc == 1 || argc == 2)
		return (1);
	while (i < argc)
	{
		num = atoi(argv[i]);
		insert_at_tail(&stack_a, num);
		i++;
	}
	printlist(stack_a);
	if (!stack_sorted(stack_a))
	{
		printf("not sorted\n");
		if (stack_len(stack_a) == 2)
		{
			stack_a = swap_1_2(stack_a);
			printlist(stack_a);
			printf("sorted\n");
		}
		if (stack_len(stack_a) == 3)
		{
			stack_a = sort_stack_of_3(stack_a);
			printlist(stack_a);
			printf("sorted\n");
		}
		else turk_sort(stack_a);
	}
	// else
	// 	printf("sorted\n");
	return (0);
}

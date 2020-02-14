/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <aruiz-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:36:47 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/02/07 13:01:38 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_list		*reverse(t_list *head)
{
	t_list	*next;
	t_list	*prev;

	prev = NULL;
	while (head != NULL)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}
	return (prev);
}

t_list		*sub_parse_file(int ret, int *dt, t_list *node, t_list *head)
{
	if (ret < 0)
		return (0);
	*dt = node->content_size;
	head = reverse(head);
	return (head);
}

void		set_parse_var(t_parse *prs, int *ln, char *root)
{
	prs->ret = 0;
	*ln = 0;
	prs->fd = open(root, O_RDONLY);
}

t_list		*ft_parse_file(char *root, int *ln, int *dt)
{
	t_parse	prs;
	t_list	*head;
	t_list	*node;

	head = NULL;
	set_parse_var(&prs, ln, root);
	while ((prs.ret = get_next_line(prs.fd, &prs.buff)) > 0)
	{
		prs.wrds = ft_strlen(prs.buff);
		node = ft_lstnew(prs.buff, prs.wrds + 1);
		if ((node->content_size = ft_countwords(prs.buff, ' ')) < 2)
			exit(0);
		if (head)
			ft_lstadd(&head, node);
		else
			node->next = NULL;
		head = node;
		*ln += 1;
		free(prs.buff);
	}
	if (*ln < 2)
		exit(0);
	if ((head = sub_parse_file(prs.ret, dt, node, head)) == NULL)
		return (NULL);
	return (head);
}

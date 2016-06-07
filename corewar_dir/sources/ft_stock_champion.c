/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_champion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:58:16 by ssicard           #+#    #+#             */
/*   Updated: 2016/05/31 09:38:20 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	ft_stock_magic(int fd, char *buff, t_bin *plr)
{
	int ret;

	if (!(ret = read(fd, buff, 4)))
		ft_error("error READ magic");
	buff[ret] = '\0';
	memrev(buff, 4);
	plr->magic = (*((int *)buff));
	if (plr->magic ^ COREWAR_EXEC_MAGIC)
		ft_error("error wrong magic");
}

void	ft_stock_name(int fd, t_bin *plr)
{
	int ret;

	if (!(ret = read(fd, plr->prog_name, PROG_NAME_LENGTH)))
		ft_error("error READ name");
	plr->prog_name[ret] = '\0';
	plr->name = ft_strdup(plr->prog_name);
}

void	ft_stock_prog_size(int fd, char *buff, t_bin *plr)
{
	int ret;

	if ((ret = read(fd, buff, 4) == -1))
		ft_error("error READ prog_size");
	buff[ret] = '\0';
	plr->prog_size = (*((int *)buff));
	if (r4oi(plr->prog_size) > CHAMP_MAX_SIZE)
		ft_error("Champs exceeded CHAMP_MAX_SIZE");
}

void	ft_stock_comment(int fd, t_bin *plr)
{
	int ret;

	if (!(ret = read(fd, plr->comment, COMMENT_LENGTH)))
		ft_error("error READ comment");
	plr->comment[ret] = '\0';
	plr->com = ft_strdup(plr->comment);
}

void	ft_stock_program(int fd, t_bin *plr)
{
	int ret;

	if (!(ret = read(fd, plr->program, r4oi(plr->prog_size))))
		ft_error("error READ program");
	if (ret ^ r4oi(plr->prog_size))
		ft_error("Wrong prog");
	plr->program[ret] = '\0';
}

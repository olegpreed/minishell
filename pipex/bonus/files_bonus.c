/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarrosh <lgarrosh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:14:29 by lgarrosh          #+#    #+#             */
/*   Updated: 2022/06/25 17:14:30 by lgarrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	get_infile(char **argv, t_pipex *pip, t_ppxb *pipex)
{
	if (pipex->here_doc)
		here_doc(argv[2], pipex);
	else
	{
		if (pip->infile)
			pipex->infile = open(pip->infile, O_RDONLY);
		else
			pipex->infile = -1;
		if ((pipex->infile < 0) && pip->infile)
			msg_error(ERR_INFILE);
	}
}

void	get_outfile(t_pipex *pip, t_ppxb *pipex)
{
	if (pipex->here_doc)
		pipex->outfile = open(pip->outfile, O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else
	{
		if (pip->outfile)
			pipex->outfile = open(pip->outfile, O_CREAT | O_RDWR | O_TRUNC, 0000644);
		else
			pipex->outfile = -1;
	}
	if ((pipex->outfile < 0) && pip->outfile)
		msg_error(ERR_OUTFILE);
}

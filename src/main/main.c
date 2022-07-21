# include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_llist		*list;
	t_ll_elem	*el;
	char		a;
	char		*prom;
	char		*line;

	(void)argc;
	(void)argv;
	line = &a;
	prom = "minish:$ ";
	signal(SIGINT, handler);
	while(line)
	{	
		line = ft_readline(prom);
	}
	write(1, "exiting...\n", 11);
	list = llist_new(NULL, free, free);
	ft_parse_envp(list, envp);
	el = list->head;
	while (el)
	{
		printf("%s\n", (char *)el->key);
		el = el->next;
	}
	return (0);
}
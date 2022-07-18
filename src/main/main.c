# include "minishell.h"

int main()
{
	char	a;
	char	*prom;
	char	*line;

	line = &a;
	prom = "minish:$ ";
	signal(SIGINT, handler);
	while(line)
	{	
		line = ft_readline(prom);
	}
	write(1, "exiting...\n", 11);
	return (0);
}
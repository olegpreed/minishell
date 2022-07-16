#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
	rl_replace_line("", 1);
	rl_redisplay();
	// write(1, "  \b\b\n", 5);
	// rl_on_new_line();
	// rl_redisplay();
}

char	*ft_readline(char *prom)
{
	char	*line;
	
	line = readline(prom);
	if (line)
		add_history(line);
	return (line);
}

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
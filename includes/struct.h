#ifndef STRUCT_H
# define STRUCT_H

# include <unistd.h>
# define ERR_MALLOC "failed to allocate memory"


typedef int (*	t_llist_key_comparator_ptr)(const void	*k1,const void *k2);
typedef void (*	t_llist_key_destructor_ptr)(void	*key);
typedef void (*	t_llist_val_destructor_ptr)(void	*val);

typedef struct s_llist_element
{
	void	*key;
	void	*val;
	void	*next;
}	t_ll_elem;

typedef struct s_linked_list
{
	t_ll_elem					*head;
	t_llist_key_comparator_ptr	key_cmpr;
	t_llist_key_destructor_ptr	key_dstr;
	t_llist_val_destructor_ptr	val_dstr;
	unsigned int				size;
}	t_llist;

typedef struct s_info	t_info;
typedef int				(*t_builtin_ptr)(t_llist *, t_info *);

struct s_info
{
	char						exit_f;
	char						envp_f;
	char						**envp;
	char						*g_exit_str;
	char						*reserved_words[7];
	t_builtin_ptr				f_ptrs[7];
	t_llist						*envp_list;
};

typedef struct s_cmd_info
{
	char	*in_file;
	char	*out_file;
	char	*delim;
	int		flags;
	int		_shlvl;
}	t_cmd_info;

typedef struct s_group
{
	int			type;
	t_llist		*cmds;
	t_llist		*files;
}	t_group;

typedef struct s_fd
{
	int		pfd[2];
	int		fds[2];
}	t_fd;

typedef struct s_expi
{
	unsigned int	size;
	int				f;
}	t_expi;

typedef struct s_chunk_info
{
	unsigned int	s;
	unsigned int	e;
}	t_chunk_info;

typedef struct s_fpack1
{
	t_chunk_info	*ci;
	unsigned int	*i;
	unsigned int	*size;
}	t_fpack1;

typedef struct s_env //переменные окружения
{
	char			*name;
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	**cmd_line;
	char	**envp;
}			t_pipex;

#endif
#include "push_swap.h"

#define YELL(txt)		(ft_printf("\n–––––––––– %s ––––––––––\n", txt))

static void printcnt(int c)
{
	ft_printf("> %d ", (char)c);
}

static void	show_error(char *s)
{
	write(0, s, ft_strlen(s));
	write(0, "\n", 1);
	exit(1);
}

static int	check(char *arg)
{
	int i;

	i = -1;
	while(arg[++i])
		if (!ft_isdigit(arg[i]))
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	char		**args;
	t_list	*stack_a;
	t_list	*stack_b = NULL;

	if(argc < 2)
		return (0);

	/* Init stack_a with arguments */
	i = 0;
	args = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		i--;
		while(args[++i])
			if (!check(args[i]))
				ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(args[i])));
			else
				show_error("Incorrect argument");
	}
	else
	{
		while(argc > ++i)
			ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i])));
	}
	return (0);
}
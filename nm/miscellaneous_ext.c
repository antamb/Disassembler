
#include	"nm.h"

extern t_nm	s_nm;

int      check_format(void)
{
  if (s_nm.s_helf != NULL)
    {
      if ((s_nm.s_helf->e_ident[EI_MAG0] == ELFMAG0) \
          || (s_nm.s_helf->e_ident[EI_MAG1] == ELFMAG1) \
          || (s_nm.s_helf->e_ident[EI_MAG2] == ELFMAG2) \
          || (s_nm.s_helf->e_ident[ELFMAG3] == ELFMAG3))
        return (SUCCEED);
    }
  printf(ERR_FELF, s_nm.file);
  fflush(stdout);
  return (FAILED);
}

int      fill_struct_nm(void)
{
  if (get_map() == FAILED)
    return (error(ERR_MMAP));
  if (get_helf() == FAILED)
    return (error(ERR_HEAD));
  if (get_self() == FAILED)
    return (error(ERR_SECT));
  if (check_format() == FAILED)
    return (FAILED);
  return (SUCCEED);
}

int	check_option_ext(char **av, int i)
{
  if (av[i][0] == '-')
    {
      if (av[i][1] != 'u' && av[i][1] != 'r' && av[i][1] != 'v' \
	  && av[i][1] != 'n' && av[i][1] != 'h' && av[i][1] != 'S')
	{
	  printf(ERR_INVAL_OPTION, av[i][1]);
	  fflush(stdout);
	  printf("%s\n", HELP);
	  fflush(stdout);
	  return (FAILED);
	}
    }
  return (SUCCEED);
 }

int	check_option(char **av)
{
  int	i;

  i = 0;
  if (av == NULL)
    return (FAILED);
  while (av[i] != NULL)
    {
      if (check_option_ext(av, i) == FAILED)
	return (FAILED);
      if (strcmp(av[i], OPT_V) == 0 || strcmp(av[i], OPT_N) == 0)
	s_nm.opt[N] = 1;
      if (strcmp(av[i], OPT_R) == 0)
	s_nm.opt[R] = 1;
      if (strcmp(av[i], OPT_U) == 0)
	s_nm.opt[U] = 1;
      if (strcmp(av[i], OPT_H) == 0)
	s_nm.opt[H] = 1;
      if (strcmp(av[i], OPT_S) == 0)
	s_nm.opt[S] = 1;
      i++;
    }
  return (SUCCEED);
}



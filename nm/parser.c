
#include	"nm.h"
#include	<string.h>

t_nm		s_nm;

static	int	count_file(char **av)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  while (av[i] != NULL)
    {
      if (av[i][0] != '-')
	n++;
      i++;
    }
  return (n);
}

static	int	has_no_args(void)
{
  char		buf[BSIZE];

  bzero(buf, sizeof(buf));
  s_nm.file = strcpy(buf, DFILE);
  if (fill_struct_nm() == FAILED)
    return (FAILED);
  my_nm();
  return (SUCCEED);
}

static	int	has_args(int ac, char **av)
{
  int	i;
  int	n;

  i = -1;
  n = 0;
  while (av[++i] != NULL)
    {
      if (av[i][0] != '-')
	{
	  s_nm.file = av[i];
	  if (fill_struct_nm() == FAILED)
	    return (FAILED);
	  if (ac > 1)
	    {
	      printf("\n%s : \n", s_nm.file);
	      fflush(stdout);
	    }
	  my_nm();
	  init_struct_nm();
	  check_option(av);
	  n++;
	}
    }
  n =  n == 0 ? has_no_args() : 0;
  return (SUCCEED);
}

int	parser(int ac, char **av)
{
  av++;
  init_struct_nm();
  if (check_option(av) == FAILED)
    return (FAILED);
  if (s_nm.opt[H] == 1)
    {
      printf("%s\n", HELP);
      fflush(stdout);
      return (SUCCEED);
    }
  if (ac == 1)
    {
      if (has_no_args() == FAILED)
	return (FAILED);
    }
  else
    {
      if (has_args(count_file(av), av) == FAILED)
	return (FAILED);
    }
  return (0);
}

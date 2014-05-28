
#include	"objdump.h"
#include	<string.h>

t_ob		s_ob;

static int	check_format(void)
{
  if (s_ob.s_helf != NULL)
    {
      if ((s_ob.s_helf->e_ident[EI_MAG0] == ELFMAG0) \
	  || (s_ob.s_helf->e_ident[EI_MAG1] == ELFMAG1) \
	  || (s_ob.s_helf->e_ident[EI_MAG2] == ELFMAG2) \
	  || (s_ob.s_helf->e_ident[ELFMAG3] == ELFMAG3))
	return (SUCCEED);
    }
  printf(ERR_FELF, s_ob.file);
  fflush(stdout);
  return (FAILED);
}

static int	fill_struct_nm(void)
{
  if (get_map() == FAILED)
    return (error(ERR_MMAP));
  if (get_helf() == FAILED)
    return (FAILED);
  if (get_self() == FAILED)
    return (FAILED);
  if (check_format() == FAILED)
    return (FAILED);
  return (SUCCEED);
}

int	parser(int ac, char **av)
{
  char	buf[BSIZE];

  av++;
  init_struct_nm();
  bzero(buf, sizeof(buf));
  if (ac == 1)
    {
      s_ob.file = strcpy(buf, DFILE);
      if (fill_struct_nm() == FAILED)
	return (FAILED);
      my_objdump();
    }
  else
    {
      while (*av)
	{
	  s_ob.file = *(av++);
	  if (fill_struct_nm() == FAILED)
	    return (FAILED);
	  my_objdump();
	}
    }
  return (0);
}

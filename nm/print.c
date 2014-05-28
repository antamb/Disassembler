
#include	"nm.h"
#include        <sys/mman.h>

extern t_nm	s_nm;

static void	print_sym_ext_size(char *zero, t_list *swap)
{
  if (swap->sym.size != 0) 
    {
      if (swap->sym.value != 0 && swap->sym.type != 'U' && swap->sym.type != 'u' \
	  && swap->sym.type != 'w')
	printf("%08x %08x %c %s\n", swap->sym.value, swap->sym.size,	\
	       swap->sym.type, swap->sym.name);
      else
	printf("%s %08x %c %s\n", zero, swap->sym.size,	\
	       swap->sym.type, swap->sym.name);
    }
  else
    {
      if (swap->sym.value != 0 && swap->sym.type != 'U' && swap->sym.type != 'u' \
	  && swap->sym.type != 'w')
	printf("%08x %c %s\n", swap->sym.value, \
	       swap->sym.type, swap->sym.name);
      else
	printf("%s %c %s\n", zero, \
	       swap->sym.type, swap->sym.name);
    }
}

static void	print_sym_ext_nosize(char *zero, t_list *swap)
{
  if (swap->sym.value != 0 && swap->sym.type != 'U' && swap->sym.type != 'u' \
      && swap->sym.type != 'w')
    printf("%08x %c %s\n", swap->sym.value, swap->sym.type,     \
	   swap->sym.name);
  else
    printf("%s %c %s\n", zero, swap->sym.type,  \
	   swap->sym.name); 
}

static void     print_sym_ext(char *zero, t_list *swap)
{
  while (swap != NULL)
    {
      if (s_nm.opt[S] == 1)
	print_sym_ext_size(zero, swap);
      else
	print_sym_ext_nosize(zero, swap);
      fflush(stdout);
      swap = swap->next;
    }
}

int             print_sym(void)
{
  char          zero[9];
  t_list        *swap;

  sort();
  swap = s_nm.lsym;
  strcpy(zero, "        ");
  print_sym_ext(zero, swap);
  free_list();
  if (munmap(s_nm.map, s_nm.s_stat.st_size) == FAILED)
    return (FAILED);
  return (SUCCEED);
}

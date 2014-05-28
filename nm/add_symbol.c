
#include "nm.h"
#include <stdlib.h>

extern t_nm	s_nm;

int		add_symbol(int value, int size, char type, char *name)
{
  t_sym		sym;
  t_list	*elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (FAILED);
  sym.value = value;
  sym.type = type;
  sym.size = size;
  sym.name = strdup(name);
  elem->sym = sym;
  elem->next = s_nm.lsym;
  s_nm.lsym = elem;
  return (SUCCEED);
}

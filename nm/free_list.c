
#include "nm.h"
#include <stdlib.h>

extern t_nm	s_nm;

int		free_list(void)
{
  t_list	*tmp;
  t_list	*swap;

  if (s_nm.lsym == NULL)
    return (FAILED);
  swap = s_nm.lsym;
  while (swap != NULL)
    {
      tmp = swap;
      swap = swap->next;
      free(tmp->sym.name);
      free(tmp);
    }
  return (SUCCEED);
}


#include "nm.h"

extern t_nm	s_nm;

void     sort(void)
{
  if (s_nm.opt[R] == 1)
    {
      sort_rev_list();
      return ;
    }
  if (s_nm.opt[N] == 1 || s_nm.opt[V] == 1)
    {
      sort_num_list();
      return ;
    }
  sort_alph_list();
}

int		sort_alph_list(void)
{
  t_sym		swap;
  t_list	*swap1;
  t_list	*swap2;

  if (s_nm.lsym == NULL)
    return (FAILED);
  swap1 = s_nm.lsym;
  while (swap1 != NULL)
    {
      swap2 = swap1->next;
      while (swap2 != NULL)
	{
	  if (strcmp(swap1->sym.name, swap2->sym.name) > 0)
	    {
	      swap = swap1->sym;
	      swap1->sym = swap2->sym;
	      swap2->sym = swap;
	    }
	  swap2 = swap2->next;
	}
      swap1 = swap1->next;
    }
  return (SUCCEED);
}

int		sort_num_list(void)
{
  t_sym		swap;
  t_list	*swap1;
  t_list	*swap2;

  if (s_nm.lsym == NULL)
    return (FAILED);
  swap1 = s_nm.lsym;
  while (swap1 != NULL)
    {
      swap2 = swap1->next;
      while (swap2 != NULL)
	{
	  if (swap1->sym.value > swap2->sym.value)
	    {
	      swap = swap1->sym;
	      swap1->sym = swap2->sym;
	      swap2->sym = swap;
	    }
	  swap2 = swap2->next;
	}
      swap1 = swap1->next;
    }
  return (SUCCEED);
}

int		sort_rev_list(void)
{
  t_sym		swap;
  t_list	*swap1;
  t_list	*swap2;

  if (s_nm.lsym == NULL)
    return (FAILED);
  swap1 = s_nm.lsym;
  while (swap1 != NULL)
    {
      swap2 = swap1->next;
      while (swap2 != NULL)
	{
	  if (strcmp(swap1->sym.name, swap2->sym.name) < 0)
	    {
	      swap = swap1->sym;
	      swap1->sym = swap2->sym;
	      swap2->sym = swap;
	    }
	  swap2 = swap2->next;
	}
      swap1 = swap1->next;
    }
  return (SUCCEED);
}

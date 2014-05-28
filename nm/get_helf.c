
#include	"nm.h"

extern t_nm	s_nm;

int	get_helf(void)
{
  if (s_nm.map == NULL)
    return (FAILED);
  s_nm.s_helf = (Elf32_Ehdr *)s_nm.map;
  return (SUCCEED);
}

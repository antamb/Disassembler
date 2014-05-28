
#include	"nm.h"

extern t_nm	s_nm;

int	get_self(void)
{
  if (s_nm.map == NULL)
    return (FAILED);
  if (s_nm.s_helf->e_shoff != 0)
    s_nm.s_self = (Elf32_Shdr *)((char *)s_nm.map + s_nm.s_helf->e_shoff);
  return (SUCCEED);
}

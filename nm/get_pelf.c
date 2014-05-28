
#include	"nm.h"

extern t_nm	s_nm;

int	get_pelf(void)
{
  if (s_nm.addr == NULL)
    return (FAILED);
  if (e_phoff != 0)
    s_nm.s_pelf = (Elf32_Phdr *)(s_nm.map + s_nm.s_helf->e_phoff);
  return (SUCCEED);
}


#include	"objdump.h"

extern t_ob	s_ob;

int	get_self(void)
{
  if (s_ob.map == NULL)
    return (FAILED);
  if (s_ob.s_helf->e_shoff != 0)
    s_ob.s_self = (Elf32_Shdr *)((char *)s_ob.map + s_ob.s_helf->e_shoff);
  return (SUCCEED);
}

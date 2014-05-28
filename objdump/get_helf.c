
#include	"objdump.h"

extern t_ob	s_ob;

int	get_helf(void)
{
  if (s_ob.map == NULL)
    return (FAILED);
  s_ob.s_helf = (Elf32_Ehdr *)s_ob.map;
  return (SUCCEED);
}

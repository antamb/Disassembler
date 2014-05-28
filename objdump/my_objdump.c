
#include	"objdump.h"

extern t_ob	s_ob;

int	my_objdump(void)
{
  if (s_ob.s_self != NULL)
    {
      if (disp_header() == FAILED)
        return (FAILED);
      if (disp_content() == FAILED)
        return (FAILED);
      init_struct_nm();
    }
  return (SUCCEED);
}


#include "nm.h"
#include <unistd.h>

int	error(char *msg)
{
  if (msg == NULL)
    return (FAILED);
  printf("%s", msg);
  fflush(stdout);
  return (FAILED);
}

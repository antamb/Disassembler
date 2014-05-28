
#include "objdump.h"
#include <unistd.h>

int	error(char *msg)
{
  if (msg == NULL)
    return (FAILED);
  if (xwrite(STDERR_FILENO, msg, strlen(msg)) == FAILED)
    return (FAILED);
  return (FAILED);
}

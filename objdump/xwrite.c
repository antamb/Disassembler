
#include "objdump.h"
#include <sys/uio.h>
#include <unistd.h>
#include <sys/types.h>

ssize_t	xwrite(int fd, char *str, size_t size)
{
  if (str == NULL)
    return (FAILED);
  if (write(fd, str, size) == -1)
    return (FAILED);
  return (SUCCEED);
}


#include "objdump.h"
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/fcntl.h>

extern t_ob     s_ob;

int		get_map(void)
{
  int		fd;

  if ((fd = open(s_ob.file, O_RDONLY)) == -1)
    return (error(ERR_OPEN));
  if (fstat(fd, &s_ob.s_stat) == -1)
    return (error(ERR_STAT));
  s_ob.map = mmap(NULL, s_ob.s_stat.st_size, PROT_READ, \
		  MAP_FILE | MAP_SHARED, fd, 0);
  if (s_ob.map == (char *)-1)
    return (FAILED);
  close(fd);
  return (SUCCEED);
}


#include "nm.h"
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/fcntl.h>

extern t_nm     s_nm;

int		get_map(void)
{
  int		fd;

  if ((fd = open(s_nm.file, O_RDONLY)) == -1)
    return (error(ERR_OPEN));
  if (fstat(fd, &s_nm.s_stat) == -1)
    return (error(ERR_STAT));
  s_nm.map = mmap(NULL, s_nm.s_stat.st_size, PROT_READ, \
		  MAP_FILE | MAP_SHARED, fd, 0);
  if (s_nm.map == (char *)-1)
    return (FAILED);
  close(fd);
  return (SUCCEED);
}

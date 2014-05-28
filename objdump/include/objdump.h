
#ifndef _MYOBJDUMP_
# define _MYOBJDUMP_

/*Include*/
#include <elf.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
/*Define*/
#define BSIZE	30
#define DFILE	"a.out"

#define FAILED	-1
#define SUCCEED	0

#define ERR_STAT	"Error stat\n"
#define ERR_MMAP	"Unable to map file\n"
#define ERR_OPEN	"Unable to open file\n"
#define ERR_FELF	"nm: %s: File format not recognized\n"

/*Structure*/
typedef struct s_ob{
  char		*file;
  void		*map;
  Elf32_Ehdr	*s_helf;
  Elf32_Shdr	*s_self;
  struct stat	s_stat;
}		t_ob;

/*functions*/
int	get_map(void);
int	get_helf(void);
int	get_self(void);
int	my_objdump(void);
int	error(char *msg);
int	disp_header(void);
int	disp_content(void);
int	parser(int ac, char **av);
int	xwrite(int fd, char *str, size_t size);

char	*get_arch(void);
char	*get_class(void);
char	*get_osabi(void);
void    init_struct_nm(void);
#endif /*__MYOBJDUMP__*/

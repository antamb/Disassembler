
#ifndef _MYNM_
# define _MYNM_

/*Include*/
#include <elf.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
/*Define*/
#if defined(__sun) || (sun)
#define	MAP_FILE	0
#include <strings.h>

char	*strdup(const char *s1); 
int	open(const char *file, int flags);
#endif
#define BSIZE	30
#define DFILE	"a.out"

#define FAILED	-1
#define SUCCEED	0

#define ERR_STAT		"Error stat\n"
#define ERR_MMAP		"Unable to map file\n"
#define ERR_OPEN		"Unable to open file\n"
#define ERR_SECT		"Unable to find sections\n"
#define ERR_HEAD		"Unable to find header\n "
#define ERR_FELF		"nm: %s: File format not recognized\n"
#define ERR_INVAL_OPTION	"nm: Invalid option -%c\n"

#define HELP		"Usage: nm [option(s)] [file(s)]\n List symbols in [file(s)] (a.out by default).\nThe options are: \n-n\tSort symbols numerically by address\n-r\tReverse the sense of the sort\n-S\tPrint size of defined symbols\n-u\tDisplay only undefined symbols\n-help\tDisplay this information\nnm: supported targets: elf32-i386-freebsd elf32-i386"

/*Options*/
#define OPT_V	"-v"
#define OPT_R	"-r"
#define OPT_U	"-u"
#define OPT_N	"-n"
#define OPT_S	"-S"
#define OPT_H	"-h"

#define V	0
#define R	1
#define U	2
#define S	3
#define N	4
#define H	5

/*Structure*/
typedef struct	s_sym{
  char		type;
  char		*name;
  int		value;
  int		size;
}		t_sym;

typedef struct	s_list{
  t_sym		sym;
  struct s_list	*next;
}		t_list;

typedef struct s_nm{
  int		opt[7];
  char		*file;
  void		*map;
  t_list	*lsym;
  Elf32_Ehdr	*s_helf;
  Elf32_Phdr	*s_pelf;
  Elf32_Shdr	*s_self;
  struct stat	s_stat;
}		t_nm;

/*functions*/
int	my_nm(void);
int	get_map(void);
int	get_helf(void);
int	get_self(void);
int	get_pelf(void);
int	free_list(void);
int	print_sym(void);
int	error(char *msg);
int	check_formet(void);
int	sort_rev_list(void);
int	sort_alph_list(void);
int	sort_num_list(void);
int	fill_struct_nm(void);
int	check_option(char **av);
int	parser(int ac, char **av);
int	add_symbol(int value, int size, char type, char *name);

void	sort(void);
void	*get_symtab(void);
void    init_struct_nm(void);

char    get_scope(unsigned char info, char type, int value);
char	get_type(unsigned char info, uint16_t index, int value);
#endif /*__MYNM__*/

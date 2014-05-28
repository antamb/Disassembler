
#include	"nm.h"

extern t_nm	s_nm;

void    init_struct_nm(void)
{
  int	i;
  int	n;

  i = 0;
  n = (int)(sizeof(s_nm.opt) / sizeof(int));
  while (i < n)
    s_nm.opt[i++] = 0;
  s_nm.map = NULL;
  s_nm.file = NULL;
  s_nm.lsym = NULL;
  s_nm.s_helf = NULL;
  s_nm.s_self = NULL;
}

char	get_scope(unsigned char info, char type, int value)
{
  (void)value;
  if (ELF32_ST_BIND(info) == STB_GLOBAL)
    return (type);
  return (type + 32);
}

void		*get_symtab(void)
{
  int		n;
  int		ns;
  Elf32_Shdr	*self;

  n = 0;
  if ((self = (Elf32_Shdr *)((char *)s_nm.map + s_nm.s_helf->e_shoff)) == NULL)
    return (NULL);
  ns = (int)s_nm.s_helf->e_shnum;
  while (n < ns)
    {
      if (self->sh_type == SHT_SYMTAB)
        return (self);
      self++;
      n++;
    }
  return (NULL);
}

static char	get_type_ext(unsigned char info, uint16_t index, int value)
{
  Elf32_Shdr	*sect;

  sect = &s_nm.s_self[index];
  if (sect->sh_type == SHT_NOBITS && (sect->sh_flags & SHF_ALLOC)	\
      && (sect->sh_flags & SHF_WRITE))
    return (get_scope(info, 'B', value));
  else if (sect->sh_type == SHT_PROGBITS && (sect->sh_flags & SHF_ALLOC) \
	   && (sect->sh_flags & SHF_WRITE))
    return (get_scope(info, 'D', value));
  else if (ELF32_ST_BIND(info) == STB_WEAK)
    return (get_scope(info, 'W', value));
  else if (sect->sh_type == SHT_PROGBITS && (sect->sh_flags & SHF_ALLOC) \
	   && (sect->sh_flags & SHF_EXECINSTR))
    return (get_scope(info, 'T', value));
  else if (!(sect->sh_flags & SHF_WRITE) && (sect->sh_flags & SHF_ALLOC))
    return (get_scope(info, 'R', value));
  else if (sect->sh_type == SHT_PROGBITS)
    return (get_scope(info, 'N', value));
  return ('?');
}

char		get_type(unsigned char info, uint16_t index, int value)
{
  if (index == SHN_ABS)
    return (get_scope(info, 'A', value));
  else if (index == SHN_COMMON)
    return (get_scope(info, 'C', value));
  else if ((index == SHN_UNDEF) && ELF32_ST_BIND(info) != STB_WEAK)
    return (get_scope(info, 'U', value));
  if (index <= s_nm.s_helf->e_shnum)
    return (get_type_ext(info, index, value));
  return ('?');
}

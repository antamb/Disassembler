
#include	"objdump.h"

extern t_ob	s_ob;

void    init_struct_nm(void)
{
  s_ob.map = NULL;
  s_ob.file = NULL;
  s_ob.s_helf = NULL;
  s_ob.s_self = NULL;
}

char	*get_class(void)
{
  if (s_ob.s_helf == NULL)
    return (NULL);
  if (s_ob.s_helf->e_ident[EI_CLASS] == ELFCLASS32)
    return ("elf32");
  else if (s_ob.s_helf->e_ident[EI_CLASS] == ELFCLASS64)
    return ("elf64");
  return ("elf");
}

char	*get_osabi(void)
{
  if (s_ob.s_helf == NULL)
    return (NULL);
  if (s_ob.s_helf->e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
    return ("freebsd");
  else if (s_ob.s_helf->e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
    return ("solaris");
  else if (s_ob.s_helf->e_ident[EI_OSABI] == ELFOSABI_LINUX)
    return ("linux");
  else if (s_ob.s_helf->e_ident[EI_OSABI] == ELFOSABI_NETBSD)
    return ("netbsd");
  else if (s_ob.s_helf->e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
    return ("standalone");
  else if (s_ob.s_helf->e_ident[EI_OSABI] == ELFOSABI_IRIX)
    return ("irix");
  return (NULL);
}

char	*get_arch(void)
{
  if (s_ob.s_helf == NULL)
    return (NULL);
  if (s_ob.s_helf->e_machine == EM_386)
    return ("i386");
  else if (s_ob.s_helf->e_machine == EM_486)
    return ("i486");
  else if (s_ob.s_helf->e_machine == EM_860)
    return ("i860");
  else if (s_ob.s_helf->e_machine == EM_SPARC)
    return ("sparc");
  return (NULL);
}

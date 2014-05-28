
#include	"nm.h"
#include	<stdio.h>
#include	<sys/mman.h>

extern t_nm	s_nm;

int		browse_sym(void)
{
  char		type;
  char		*name;
  char		*sstr;
  Elf32_Shdr	*ssym;
  Elf32_Sym	*last;
  Elf32_Sym	*first;

  
  if ((ssym = (Elf32_Shdr *)get_symtab()) == NULL)
    return (FAILED);
  first = (Elf32_Sym *)((char *)s_nm.map + ssym->sh_offset);
  last = (Elf32_Sym *)((char *)s_nm.map + (ssym->sh_offset + ssym->sh_size));
  sstr = (char *)((char *)s_nm.map + s_nm.s_self[ssym->sh_link].sh_offset);
  while (first != last)
    {
      if (first->st_name != 0)
	{
	  name = sstr + first->st_name;
	  type = get_type((unsigned char)first->st_info, first->st_shndx, first->st_value);
	  if (first->st_value != 0 || first->st_shndx < s_nm.s_helf->e_shnum)
	    add_symbol(first->st_value, first->st_size, type, name);
	}
      first++;
    }
  return (SUCCEED);
}

int		my_nm(void)
{
  if (s_nm.s_self != NULL)
    {
      if (browse_sym() == FAILED)
	return (FAILED);
      if (print_sym() == FAILED)
	return (FAILED);
      init_struct_nm();
    }
  return (SUCCEED);
}

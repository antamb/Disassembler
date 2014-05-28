
#include	"objdump.h"
#include	<stdio.h>
#include	<unistd.h>
#include	<ctype.h>
#include	<sys/mman.h>

extern t_ob	s_ob;

int	disp_header(void)
{
  char	*os;
  char	*arch;
  char	*class;

  if (s_ob.s_helf == NULL)
    return (FAILED);
  os = get_osabi();  
  arch = get_arch();
  class = get_class();
  printf("%s:\tfile format %s-%s-%s\n", s_ob.file, class, arch, os);
  fflush(stdout);
  printf("architecture: %s, falgs 0x%08x\n", arch, s_ob.s_helf->e_flags);
  fflush(stdout);
  printf("start address 0x%08x\n\n", s_ob.s_helf->e_entry);
  fflush(stdout);
  return (SUCCEED);
}

void	disp_section_ext1(char *start, char *end)
{
  int	j;
  int	n;

  j = 0;
  while (j < 16)
    {
      n = 0;
      while (n < 4)
	{
	  if ((start + n) < end)
	    printf("%02x", (unsigned char)*(start + n));
	  else
	    printf("  ");
	fflush(stdout);
	n++;
	}
      j += 4;
      start += 4;
      xwrite(STDOUT_FILENO, " ", 1);
    }
}

void	disp_section_ext2(Elf32_Shdr *sect, char **start, int *i)
{
  int	n;
  char	c;

  n = 0;
  while (n < 16 && *i < (int)sect->sh_size)
    {
      c = **start;
      if (isprint(**start) && isascii(**start))
	xwrite(STDOUT_FILENO, &c, 1);
      else
	xwrite(STDOUT_FILENO, ".", 1);
      n++;
      (*i)++;
      (*start)++;
    }
}

static int	disp_section(Elf32_Shdr *sect)
{
  int		i;
  int		addr;
  char		*end;
  char		*start;

  i = 0;
  start = (char *)((char *)s_ob.map + sect->sh_offset);
  end = (char *)(((char *)s_ob.map + sect->sh_offset) + sect->sh_size);
  addr = sect->sh_addr;
  while (i < (int)sect->sh_size)
    {
      printf("%04x ", addr);
      fflush(stdout);
      disp_section_ext1(start, end);
      disp_section_ext2(sect, &start, &i);
      addr += 16;
      xwrite(STDOUT_FILENO, "\n", 1); 
    }
  return (SUCCEED);
}

int		disp_content(void)
{
  int		n;
  int		ns;
  char		*sstr;
  Elf32_Shdr	*sect;

  n = 0;
  ns = s_ob.s_helf->e_shnum;
  if (s_ob.s_self == NULL)
    return (FAILED);
  sect = s_ob.s_self;
  sstr = (char *)((char *)s_ob.map + sect[s_ob.s_helf->e_shstrndx].sh_offset);
  while (n < ns)
    {
      if (sect->sh_size > 0)
	{
	  printf("Contents of section %s:\n", sstr + sect->sh_name);
	  fflush(stdout);
	  disp_section(sect);
	}
      sect++;
      n++;
    }
  return (SUCCEED);
}

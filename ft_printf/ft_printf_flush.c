#include "ft_printf.h"

static void	ft_membzdel(void **ap, size_t n)
{
	if(!ap)
			return ;
	ft_bzero(*ap, n);
	ft_memdel(ap);
}

void		flush_fd(int fd)
{
	t_list	*drive;
	t_list	*tmp;

	drive = *buff_list();
	while (drive)
	{
		tmp = drive->next;
		write(fd, drive->content, drive->content_size);
		free(drive->content);
		ft_membzdel((void **)&drive, sizeof(t_list));
		drive = tmp;
	}
	*buff_list() = NULL;
}

void		flush_str(char *str)
{
	t_list	*drive;
	t_list	*tmp;

	drive = *buff_list();
	while (drive)
	{
		tmp = drive->next;
		ft_memcpy(str, drive->content, drive->content_size);
		str += drive->content_size;
		free(drive->content);
		ft_membzdel((void **)&drive, sizeof(t_list));
		drive = tmp;
	}
	*buff_list() = NULL;
	*str = '\0';
}

void		flush_nstr(char *str, size_t size)
{
	t_list	*drive;
	t_list	*tmp;

	drive = *buff_list();
	while (drive)
	{
		tmp = drive->next;
		if (drive->content_size < size)
		{
			ft_memcpy(str, drive->content, drive->content_size);
			str += drive->content_size;
			size -= drive->content_size;
		}
		else
		{
			ft_memcpy(str, drive->content, size);
			str += size;
			size = 0;
		}
		free(drive->content);
		ft_membzdel((void **)&drive, sizeof(t_list));
		drive = tmp;
	}
	*buff_list() = NULL;
	*str = '\0';
}

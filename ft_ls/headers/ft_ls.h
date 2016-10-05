/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:29:52 by qstemper          #+#    #+#             */
/*   Updated: 2016/10/05 15:48:47 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 11:19:12 by qstemper          #+#    #+#             */
/*   Updated: 2016/09/29 11:21:35 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <dirent.h>
# include <time.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include "libft.h"
# include "tree.h"
# include "ft_printf.h"

# define CHARSET_O "alRrt"
# define SIZE_O 5

# define O_HIDE 0x1
# define O_LONG 0x2
# define O_RECU 0x4
# define O_REVE 0x8
# define O_TIME 0x10
# define O_COLOR 0x40
# define O_PRIVATE_ERROR 0x80
# define O_PRIVATE_MAX 0x100
# define O_PRIVATE_MULTI 0x200

# define T_ERROR 0x1
# define T_FILE 0x2
# define T_DIR 0x4

# define NAMESIZE 510
# define MSGSIZE 510
# define PATHSIZE 2096
# define ATTRIBUTESIZE 512
# define LINKSIZE 512

# define SIXMONTH ((365 / 2) * 86400)

# define FMT1 "{green|fat}%s{eoc} : {fat}%s{eoc} -- {red}%sc{eoc}\n"
# define FMT2 "{pink}%s{eoc} : {fat}%s{eoc} [{pink}-%s{eoc}] [{pink}%s{eoc}]\n"

# define MSG_MEM "Memory Allocation Failed"

# define SET(X, Y) (Y |= X)
# define IS(X, Y) ((Y & X) == X ? 1 : 0)

typedef struct stat		t_stat;

typedef struct			s_env
{
	char				path[PATHSIZE + 1];
	char				*av;
	int					o;
	int					i;
	size_t				nlinkpad;
	size_t				sizepad;
	size_t				ownerlen;
	size_t				grplen;
}						t_env;

typedef struct			s_ls_entry
{
	int					handle;
	int					type;
	char				*msg;
	char				name[NAMESIZE + 1];
	t_stat				stat;
}						t_ls_entry;

int						avs_lex(void *s1, void *s2);
int						avs_rlex(void *s1, void *s2);
int						avs_modt(void *s1, void *s2);
int						avs_rmodt(void *s1, void *s2);


int						s_lex(void *s1, void *s2);
int						s_rlex(void *s1, void *s2);
int						s_modt(void *s1, void *s2);
int						s_rmodt(void *s1, void *s2);

void					p_standard(void *p, size_t);
void					p_cstandard(void *p, size_t);
void					p_long(void *p, size_t);
void					p_clong(void *p, size_t);

char					fmt_file_mode(t_ls_entry *e);
char					*fmt_owner_perm(t_ls_entry *e, char *buff);
char					*fmt_group_perm(t_ls_entry *e, char *buff);
char					*fmt_other_perm(t_ls_entry *e, char *buff);
char					fmt_attribute(t_ls_entry *e);

int						fmt_nblink(t_ls_entry *e);
char					*fmt_owner(t_ls_entry *e);
char					*fmt_group(t_ls_entry *e);
int						fmt_size(t_ls_entry *e);
char					*fmt_link(t_ls_entry *e, char *buff);

char					*fmt_month(t_ls_entry *e, char *buff);
char					*fmt_day(t_ls_entry *e, char *buff);
char					*fmt_yhm(t_ls_entry *e, char *buff);

int						(*g_ls_select_avsort(int o))(void *, void *);
int						(*g_ls_select_sort(int o))(void *, void *);
void					(*g_ls_select_print(int o))(void *, size_t);

t_ls_entry				ls_newentry(char *name, char *absname);
void					ls_dir(void *p, size_t size);
t_node					*av_tree (int ac, char **av);
void					maj_env(t_ls_entry e);

int						get_opt(const char *cset, int ac, char **av, char *err);

char					*ft_name(char *path);

int						error(char *key, char *msg);

t_env					*env(void);

size_t					ft_intlen(int n);

#endif

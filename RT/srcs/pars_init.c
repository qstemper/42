#include "rt.h"

void			pars_add_cmd(t_pars_cmd **cmd, int indent_lvl, \
		char *tok, void (*callback)(t_pars *, char **))
{
	t_pars_cmd	*new_cmd;

	if(!(new_cmd = (t_pars_cmd *)ft_memalloc(sizeof(t_pars_cmd))))
	{
		ft_printf("{red}%s{eoc} : pars_init\n", MSG_MEM);
		return ;
	}
	new_cmd->tok = ft_strdup(tok):
	new_cmd->indent_lvl = indent_lvl;
	new_cmd->callback = callback;
	new_cmd->next = *cmd;
	*cmd = new_cmd;
}

static void		init_pars2(t_pars *pars)
{
	pars_add_cmd(&pars->cmd, 1, "red", cmd_def_red);
	pars_add_cmd(&pars->cmd, 1, "green", cmd_def_green);
	pars_add_cmd(&pars->cmd, 1, "blue", cmd_def_blue);
	pars_add_cmd(&pars->cmd, 1, "radius", cmd_def_radius);
	pars_add_cmd(&pars->cmd, 1, "ambient", cmd_def_ambient);
	pars_add_cmd(&pars->cmd, 1, "diffuse", cmd_def_diffuse);
	pars_add_cmd(&pars->cmd, 1, "mirror", cmd_def_mirror);
	pars_add_cmd(&pars->cmd, 1, "reflec", cmd_def_reflec);
	pars_add_cmd(&pars->cmd, 1, "refrac", cmd_def_refrac);
	pars_add_cmd(&pars->cmd, 1, "color", cmd_def_color);
	pars_add_cmd(&pars->cmd, 1, "intens", cmd_def_intens);
	pars_add_cmd(&pars->cmd, 1, "vx_x", cmd_def_vx_x);
	pars_add_cmd(&pars->cmd, 1, "vx_y", cmd_def_vx_y);
	pars_add_cmd(&pars->cmd, 1, "vx_z", cmd_def_vx_z);
	pars_add_cmd(&pars->cmd, 1, "vy_x", cmd_def_vy_x);
	pars_add_cmd(&pars->cmd, 1, "vy_y", cmd_def_vy_y);
	pars_add_cmd(&pars->cmd, 1, "vy_z", cmd_def_vy_z);
	pars_add_cmd(&pars->cmd, 1, "vz_x", cmd_def_vz_x);
	pars_add_cmd(&pars->cmd, 1, "vz_y", cmd_def_vz_y);
	pars_add_cmd(&pars->cmd, 1, "vz_z", cmd_def_vz_z);
}

void			init_pars(t_pars *pars)
{
	pars->cmd = NULL;
	parser_add_cmd(&pars->cmd, 0, "diaph", cmd_def_diaph);
	parser_add_cmd(&pars->cmd, 0, "recurs", cmd_def_recurs);
	parser_add_cmd(&pars->cmd, 0, "if_name", cmd_def_);
	parser_add_cmd(&pars->cmd, 0, "width", cmd_def_);
	parser_add_cmd(&pars->cmd, 0, "height", cmd_def_);
	parser_add_cmd(&pars->cmd, 0, "cam", cmd_def_);
	parser_add_cmd(&pars->cmd, 0, "light", cmd_def_);
	parser_add_cmd(&pars->cmd, 0, "plane", cmd_def_);
	parser_add_cmd(&pars->cmd, 0, "cone", cmd_def_);
	parser_add_cmd(&pars->cmd, 0, "sphere", cmd_def_);
	parser_add_cmd(&pars->cmd, 0, "cyl", cmd_def_);
	parser_add_cmd(&pars->cmd, 1, "x", cmd_def_);
	parser_add_cmd(&pars->cmd, 1, "y", cmd_def_);
	parser_add_cmd(&pars->cmd, 1, "z", cmd_def_);
	parser_add_cmd(&pars->cmd, 1, "rot_x", cmd_def_);
	parser_add_cmd(&pars->cmd, 1, "rot_y", cmd_def_);
	parser_add_cmd(&pars->cmd, 1, "rot_z", cmd_def_);
	parser_add_cmd(&pars->cmd, 1, "norm_x", cmd_def_);
	parser_add_cmd(&pars->cmd, 1, "norm_y", cmd_def_);
	parser_add_cmd(&pars->cmd, 1, "norm_z", cmd_def_);
	init_pars2(pars);
}

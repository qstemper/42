/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 14:17:48 by qstemper          #+#    #+#             */
/*   Updated: 2015/12/09 16:24:48 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		bresenham(int x1, int y1, int x2, int y2)
{
	int		dx;
	int		dy;
	int		e;

	if ((dx = x2 - x1) != 0)
	{
		if (dx > 0)
		{
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy *= 2;
						while (42)
						{
							TRACERPIXEL(x1, y1);
							if (x1++ == x2)
								break ;
							if ((e = e - dy) < 0)
							{
								y1++;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (42)
						{
							TRACERPIXEL(x1, y1);
							if (y1++ == y2)
								break;
							if ((e = e - dx) < 0)
							{
								x1++;
								e += dy;
							}
						}
					}
				}
				else
				{
					if (dx >= -dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (42)
						{
							TRACERPIXEL(x1, y1);
							if (x1++ == x2)
								break ;
							if ((e = e + dy) < 0)
							{
								y1++;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (42)
						{
							TRACERPIXEL(x1, y1);
							if (y1++ == y2)
								break ;
							if ((e = e + dx) > 0)
							{
								x1++;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while (x1++ <= x2)
					TRACERPIXEL(x1, y1);
			}
		}
		else
		{
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (42)
						{
							TRACERPIXEL(x1, y1);
							if (x1++ == x2)
								break ;
							if ((e = e + dy) >= 0)
							{
								y1++;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (42)
						{
							TRACERPIXEL(x1, y1);
							if (y1++ == y2)
								break ;
							if ((e = e + dx) <= 0)
							{
								x1--;
								e = e + dy;
							}
						}
					}
				}
				else
				{
					if (dx <= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (42)
						{
							TRACERPIXEL(x1, y1);
							if (x1-- == x2)
								break ;
							if ((e = e - dy) >= 0)
							{
								y1--;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (42)
						{
							TRACERPIXEL(x1,y1);
							if (y1-- == y2)
								break ;
							if ((e = e - dx) >= 0)
							{
								x1--;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while (x1-- >= x2)
					TRACERPIXEL(x1, y1);
			}
		}
	}
	else
	{
		if ((dy = y2 - y1) != 0)
		{
			if (dy > 0)
			{
				while (y1++ <= y2)
					TRACERPIXEL(x1, y1);
			}
			else
			{
				while (y1-- >= y2)
					TRACERPIXEL(x1, y1);
			}
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:28:13 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/05 23:50:51 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define FRAME_RATE 3000
# define TRAP_RATE 25
# define FRAME 1536
# define HEIGHT_LIMIT 1920
# define WIDTH_LIMIT 1080

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>
# include <time.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_solong
{
	int		length;
	int		width;
	int		x;
	int		y;
	int		ecount;
	int		ccount;
	int		pcount;
	int		item_count;
	char	**map;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*grass;
	void	*wall;
	void	*chkn;
	void	*hole;
	void	*buck[4];
}	t_solong;

//**********************GNL***********************
char	*ft_strjoin(char const *s1, const char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	ft_free(char *ptr);
char	*get_next_line(int fd);
int		ft_read(int fd, char **to_read, char **buffer, char **line);
char	*ft_line(char **line, char **to_read);

int	line_numb(char **map);
int	col_numb(char **map);
int	map_check(char **map, t_solong *s);
int	is_rect(char **map, t_solong *s);
int	ft_strlen2(char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup2(const char *s);
int	name_check(char *arg);
char	**map_create(char **argv);


void	put_image(t_solong *s);
void	fill_map(t_solong *s);
void 	count_check(int i, int j, t_solong *s);

int    key_act(int key, t_solong *s);
void 	move_up(t_solong *s);
void 	move_down(t_solong *s);
void 	move_left(t_solong *s);
void 	move_right(t_solong *s);

int close_window(t_solong *s);

#endif
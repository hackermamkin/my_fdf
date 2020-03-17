
#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"

typedef struct      s_map
{
    int             *mas;
    char            last_point;
    int             width;
    int             heigth;
    struct s_map    *next;
}                   t_map;

typedef struct      s_main_list
{
    t_map           *map;
    void            *mlx_ptr;
    void            *win_ptr;
}                   t_main_list;

int     len_double_star_mas(char **str)
{
    int i;

    i = 0;
    while (str[i] != NULL)
        i++;
    return (i);
}

t_map   *create_list()
{
    t_map   *new;

    new = (t_map *)malloc(sizeof(t_map));
    new->next = NULL;
    new->last_point = 'L';
    return (new);
}

t_map   *save_line(t_map *map, char *str, int   width)
{
    char    **values;
    int     i;
    int     *mas_values;

    i = 0;
    mas_values = (int *)malloc(sizeof(int) * width);
    mas = ft_strsplit(str, ' ');
    while (mas[i] != NULL)
    {
        mas_values[i] = ft_atoi(mas[i]);
        i++;
    }
    map->mas = mas_values;
    map->width = width;
    return (map);
}

int     search_width_error(t_map *map)
{
    int     w;

    w = map->width;
    while (map->last_point != 'L' && w == map->width)
        map = map->next;
    if (map->last_point != 'L')
    {
        printf("ERROR\n");
        return (1);
    }    
    return (0);
}

//draw func

float   mod_func(float a)
{
    if (a < 0)
        return (a * (-1));
    return (a);
}

float   compare(float a, float b)
{
    if (a > b)
        return (a);
    return (b);
}

void    draw_func(float x, float y, float x1, float y1, t_main_list *main_list)
{
    int     max;
    float   x_step;
    float   y_step;

    max = compare(mod_func(x1 - x), mod_func(y1 - y));
    x_step /= max;
    y_step /= max;
    while ((int)(y - y1) && (int)(x - x1))
    {
        mlx_pixel_put(main_list->mlx_ptr, main_list->win_ptr, x, y, 0xffffff);
        x += x_step;
        y += y_step;
    }
}

t_map   *reader()
{
    t_map           *map;
    t_map           *save;
    int             width;
    int             i;

    map = create_list();
    save = map;
    while (get_next_line(0, &str))
    {
        width = len_double_star_mas(ft_strsplit(str, ' '));
        map->mas = save_line(map, str, width0);
        map->next = create_list();
        map->last_point = 'S';
        map->heigth = i;
        map = map->next;
        i++;
    }
    map = save;
    if (search_width_error(map))
    {
        printf("ERROR\n");
        return (0);
    }
    return (map);
}

int     main(int gc, char **gv)
{
    t_main_list     main_list;
    char            *str;

    i = 0;
    main_list = (t_main_list *)malloc(sizeof(t_main_list));
    main_list->map = reader();
    return (0);
}
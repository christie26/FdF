# FdF
graphic project in 42

## map parsing 
use **get_next_line** to read map and split with **ft_split** 

## get cube data
```
cube_set[i].x = 10 * x;
cube_set[i].y = 10 * y;
cube_set[i].z = ft_atoi(tab2[x]);
```

## preparing for rendering
```
t_cube	*transform_init(t_data *data, t_cube *cube)
```
with this function, duplicate new struct to render (keep the origin for top-view)
``` 
void	transform_move(t_data *data, t_cube *cube);
void	transform_rotate(t_data *data, t_cube *cube);
void	transform_scale(t_data *data, t_cube *cube);
```
using these three function, I can tranform the t_cube data 

## rendering
using ...

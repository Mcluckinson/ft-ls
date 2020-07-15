#ifndef UTILS_H
# define UTILS_H

/*!
* \file
* \brief Some utils:
*	- create structs
*	- build full path to a file
*	- calculate length of nbr
*/

#include "types.h"

t_flags		*init_flags(void);
t_file 		*init_file(void);
t_file		*new_file(t_file *prev);
t_conf		*new_conf(void);
char 		*build_path(t_file *file);
char 		*build_path_for_arg(const char *name);
int			nbrlen(long long nbr);

#endif

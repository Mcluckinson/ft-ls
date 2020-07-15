#ifndef OUTPUT_H
# define OUTPUT_H

#include "libft.h"
#include "types.h"
#include <errno.h>

/*!
* \file
* \brief Functions for print output
*/

void    	    print_illegal_opt(const char);
void 			errno_exit(void);
void 			print_directory(t_file *file, const t_flags *flags);
void 			print_all_things(t_file *file, const t_flags *flags);
void			print_all_info(const struct stat *stat,
					const bool is_flag_g, const char *name);
void 			print_file(const t_file *file,
					const t_flags *flags, const bool is_next);
void			print_with_color(const struct stat *stat, const char *name);

/*!
*	Colors
*/

#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_BOLD_GREEN "\x1b[32;1m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_BOLD_CYAN  "\x1b[96;1m"
#define ANSI_COLOR_RESET      "\x1b[0m"

#endif

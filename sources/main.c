#include "types.h"
#include "utils/utils.h"
#include "parser/parser.h"
#include "print/print.h"
#include "sort/sort.h"

/*!
** \file
** \brief Main file
**	How if works:
**		1. Init structs
**		2. Parsing input agruments by flags
**		3. Parsing input agruments by folders
**			calculate sizes for output
**		4. Sort
**		5. Print result
*/

int		main(int ac, char **av)
{
	t_flags		*flags;
	t_file		*files;
	t_conf		*conf;

	if (!(flags = init_flags()))
		return (1);
	if (!(files = init_file()))
		return (free_all(NULL, NULL, flags));
	if (!(conf = parser((const char **)av, files, flags, ac)))
		return (free_all(files, NULL, flags));
	sort((const t_flags*)flags, &files);
	print((const t_flags*)flags, (const t_file*)files, (const t_conf*)conf);
	free_all(files, conf, flags);
	return (0);
}

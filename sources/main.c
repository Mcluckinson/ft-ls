#include "types.h"
#include "utils/utils.h"
#include "parser/parser.h"
#include "output/output.h"
#include "sort/sort.h"

/*!
* \file
* \brief Main file
*	How if works:
*		1. Init structs
*		2. Parsing input agruments by flags and folders
*		3. Processing flags
*		4. Print result
*/

void	FunctionForTest(t_flags *flags, t_file *files)
{ //del this later
	printf("flags: -%d -%d, -%d -%d, -%d -%d\n", flags->big_r, flags->little_r, flags->l, flags->a, flags->t, flags->one);
	
	t_file* tmp = files;
	printf("folders:\n");
	if (!flags->big_r)
		print_directory(files->files_inside, flags);
	else
		print_all_things(files, flags);
}

int		main(int ac, char **av)
{
	t_flags		*flags;
	t_file		*files;

	if (!(flags = init_flags()))
		return (1);
	if (!(files = init_file()))
		return (1);
	if (!parser((const char **)av, files, flags, ac))
		return (1);
	//if (flags->t || flags->little_r)
		//sort((const t_flags*)flags, &files);
	FunctionForTest(flags, files);
	return (0);
}

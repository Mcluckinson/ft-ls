#include "print/print.h"
#include "types.h"
#include <sys/ioctl.h>


void	print_column(const t_file *files, const t_flags *flags, const t_conf *conf)
{
	int				term_width;
	int				cols;
	struct ttysize	ts;
	char			matrix[conf->count][conf->name_len];


	ft_memset(matrix, '\0', sizeof(matrix));
	ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
//	term_width = ts.ts_cols;
	term_width = 80;////in dev
	//printf("Terminal is %d\nCount %d\n", term_width, conf->count);
	cols = term_width / (conf->name_len + 4); ////amount of columns

	t_file *tmp = (t_file *)files->files_inside;
	for (int i = 0; i < conf->count && tmp; i++) {
		ft_strcpy(matrix[i], tmp->name);
		tmp = tmp->next;
	}


	int index = 0;////index for printing
	int 			file_in_row_counter = 0;///files num in curr row
	int 			files_done;////files already printed
	int 			row;///curr row
	int 			col;////curr col
	files_done = 0;
	row = 0;
	file_in_row_counter = 0;
	int max_files_per_col = conf->count / cols;
	max_files_per_col = (term_width % 2 ? max_files_per_col + 1 : max_files_per_col);

	while (files_done < conf->count)
	{

		col = 1;
		while (col < (cols + 1))
		{
			index = row + (col - 1)  * max_files_per_col;

			printf("%-*s ", conf->name_len, matrix[index]);
			col++;
			files_done++;
		}
		row++;
		printf("\n");

	}

/*	for (int i = 0; i < conf->count; i++) {
		printf("%s\n", matrix[i]);
	}*/
}
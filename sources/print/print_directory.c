#include "print/print.h"
#include "types.h"
/*!
** \file
** \brief
*/

static int count_files(t_file *file)
{
	int i;
	t_file *counter;

	i = 0;
	counter = file;
	while (counter)
	{
		i++;
		counter = counter->next;
	}
	return (i);
}

static int max_file_len(t_file *file)
{
	int i;
	int len;
	t_file *counter;

	counter = file;
	i = 0;
	len = 0;
	while (counter)
	{
		len = ft_strlen(counter->name);
		i = (len > i ? len : i);
		counter = counter->next;
	}
	return (i);
}

static int count_cols(t_file *files)
{
	int win_size = 50;/////get actual width;
	int cols = win_size / (max_file_len(files) + 1);
	return (cols);
}

static int count_files_per_col(t_file *files, t_conf *conf)
{
	int	cols;
	int amount_of_files;


	cols = count_cols(files); ///////////?????????
	amount_of_files = count_files(files);
	return (amount_of_files / cols);
}

static bool should_print(t_file *file, const t_flags *flags)
{
	if (file->name[0] == '.' && !file->no_ignore)
		return (flags->a ? true : false);
	return (true);
}

void 		print_directory(const t_file *file,
				const t_flags *flags, const t_conf *conf)
{
	t_file	*tmp;
	bool	is_last;

	tmp = (t_file *)file;
	if (flags->l || flags->g)
		ft_printf("total: %d\n", conf->total);
	while(tmp)
	{
		if (should_print(tmp, flags))
		{
			if (tmp->name)
			{
				is_last = tmp->next ? true : false;
				print_file((const t_file*)tmp, flags, is_last, conf);
			}
		}
		tmp = tmp->next;
	}
	if (!flags->l && !flags->g)
		ft_printf("\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_information.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 17:16:51 by ptruffau          #+#    #+#             */
/*   Updated: 2018/06/08 17:24:11 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*find_mode(mode_t st_mode)
{
	char *str;

	if (!(str = ft_strnew(9)))
		return (NULL);
	str[0] = (st_mode & S_IRUSR ? 'r' : '-');
	str[1] = (st_mode & S_IWUSR ? 'w' : '-');
	str[2] = (st_mode & S_IXUSR ? 'x' : '-');
	str[3] = (st_mode & S_IRGRP ? 'r' : '-');
	str[4] = (st_mode & S_IWGRP ? 'w' : '-');
	str[5] = (st_mode & S_IXGRP ? 'x' : '-');
	str[6] = (st_mode & S_IROTH ? 'r' : '-');
	str[7] = (st_mode & S_IWOTH ? 'w' : '-');
	str[8] = (st_mode & S_IXOTH ? 'x' : '-');
	str[9] = '\0';
	return (str);
}

static	char	find_type(mode_t st_mode)
{
	if (S_ISDIR(st_mode) == 1)
		return ('d');
	if (S_ISREG(st_mode) == 1)
		return ('-');
	if (S_ISLNK(st_mode) == 1)
		return ('l');
	if (S_ISBLK(st_mode) == 1)
		return ('b');
	if (S_ISCHR(st_mode) == 1)
		return ('c');
	if (S_ISFIFO(st_mode) == 1)
		return ('p');
	if (S_ISSOCK(st_mode) == 1)
		return ('s');
	return ('0');
}

void	ft_get_file_information(t_file *file, struct dirent *t_dir, char *path)
 {
	struct stat buf;
	struct group *grp;
	struct passwd *owner;

	if ((!(file->name = ft_strdup(t_dir->d_name))) ||
	!(file->path = ft_new_path(path, file->name)) ||
	(lstat(file->path, &buf) < 0) ||
	((file->type = find_type(buf.st_mode)) == '0') || 
	(!(owner = getpwuid(buf.st_uid)) || !(file->owner = ft_strdup(owner->pw_name))) ||
	(!(grp = getgrgid(buf.st_gid)) || !(file->group = ft_strdup(grp->gr_name))) ||
	!(file->mode = find_mode(buf.st_mode)))
		warning("impossible to take all the file's info", path);
	file->modif_time = buf.st_mtime;
	file->access_time = buf.st_atime;
	file->block = (int)buf.st_blocks;
	file->nb_of_l = buf.st_nlink;
	file->size = buf.st_size;
	if (file->type == 'l' && (!(file->link = ft_strnew(BUFF_SIZE)) ||
		readlink(file->path, file->link, BUFF_SIZE) < 0))
		warning("impossible to read the link", path);
}

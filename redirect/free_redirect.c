#include "redirect.h"

t_redirect	*free_redirect(t_redirect *this)
{
	if (this)
	{
		if (this->file)
			free(this->file);
		if (this->fd)
			close(this->fd);
		free(this);
	}
	return (NULL);
}

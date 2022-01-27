#include "builtin.h"

int	unset(t_env *envi, char *name)
{
	return (env_delete(name, envi));
}

#include "libft.h"
// continuously allocate memory and set them to bytes of zero

// how to detect overflow
void	*ft_calloc(size_t count, size_t size)
{
	void *ptr = NULL;
	size_t bf = 0;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	bf = count * size; // overflow possibility after multiplicatio

	if (bf == 0)
		bf = 1; // super smart

	ptr = malloc(bf);
	if (ptr == NULL)
		return (NULL);

	ft_bzero(ptr, bf); // call your friend.
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	// malloc
	char *dup;
	size_t i;
	i = 0;
	dup = malloc((ft_strlen(s) + 1) * sizeof(*s));
	if (dup == NULL)
		return (NULL);
	// dupicate
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

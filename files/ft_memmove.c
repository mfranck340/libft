
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (ptr_dst > ptr_src)
	{
		while (n--)
			ptr_dst[n] = ptr_src[n];
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
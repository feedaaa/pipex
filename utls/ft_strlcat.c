/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:53:44 by ffidha            #+#    #+#             */
/*   Updated: 2023/11/06 14:45:00 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			i;
	size_t			dest_len;
	size_t			src_len;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize < dest_len + 1)
	{
		return (dstsize + src_len);
	}
	else if (dstsize > dest_len + 1)
	{
		while (src[i] && i < (dstsize - dest_len - 1))
		{
			dst[dest_len + i] = src[i];
			i++;
		}
		dst[dest_len + i] = '\0';
	}
	return (dest_len + src_len);
}

// int main(void)
// {
//     char src[] = "here";
//     char dest[10] = "look";

//     size_t result = ft_strlcat(dest, src, 0);

//     printf("concatenated str = %s\n", dest);
//     printf("length = %zu\n", result);
// }

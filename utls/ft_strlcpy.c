/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:39:59 by ffidha            #+#    #+#             */
/*   Updated: 2023/11/06 14:42:53 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = dstsize - 1;
	if (dstsize != '\0')
	{
		while (len > i && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

// int main(void)
// {
//     char dest[10] = "";
//     char src[] = "look here";
//     size_t len = ft_strlcpy(dest, src, sizeof(dest));
//     printf("src =  %s\n", src);
//     printf("dest =  %s\n", dest);
//     printf("length =  %zu\n", len);
//     return (0);
// }

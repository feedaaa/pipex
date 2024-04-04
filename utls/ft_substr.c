/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:43:36 by ffidha            #+#    #+#             */
/*   Updated: 2023/11/09 12:55:48 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*all;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	all = (char *)malloc(sizeof(char) * len + 1);
	if (!all)
		return (NULL);
	while (i < len && s[start + i])
	{
		all[i] = s[start + i];
		i++;
	}
	all[i] = '\0';
	return (all);
}

// int main(void)
// {
//     char str[] = "i just want this part #############";
//     size_t size = 20;

//     char *ret = ft_substr(str, 5, size);
//     str[size + 5] = 0;
//     if (!memcmp(ret, str + 5, size + 1))
//     {
//         printf("TEST_SUCCESS\n");
//     }
//     free(ret); // Free the allocated memory here
//     return 0; // Add a return statement to indicate successful execution
// }

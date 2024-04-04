/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:23:42 by ffidha            #+#    #+#             */
/*   Updated: 2023/11/07 10:41:05 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int main(void) 
// {
//     const char *originalString = "Hello, World!";

//     char *duplicateString = ft_strdup(originalString);
//     if (duplicateString == NULL) {
//         perror("Error in strdup");
//         return 1;
//     }

//     printf("Original String: %s\n", originalString);
//     printf("Duplicate String: %s\n", duplicateString);

//     free(duplicateString);

//     return 0;
// }
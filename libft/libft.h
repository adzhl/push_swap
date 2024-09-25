/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:23:23 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/25 11:06:00 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_isdigit(int c);
size_t				ft_strlen(char const *str);
size_t				ft_strlcpy(char *dest, char const *src, size_t n);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
int					ft_atoi(char const *str);

#endif

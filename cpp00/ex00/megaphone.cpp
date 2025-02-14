/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 22:27:30 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/16 22:56:51 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>

void megaphone(const char *s)
{
	const size_t length = std::strlen(s);

	for (size_t i = 0; i < length; i++)
		std::cout << (char)std::toupper(s[i]);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		megaphone("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	else
	{
		for (int i = 1; i < argc; i++)
		{
			megaphone(argv[i]);
			std::cout << " ";
		}
	};
	std::cout << std::endl;
	return (0);
}

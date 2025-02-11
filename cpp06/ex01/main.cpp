/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:40:07 by maiboyer          #+#    #+#             */
/*   Updated: 2025/02/09 16:33:08 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>
#include <string>

int main(void)
{
	Data dat = {.price = -10, .stock = 5, .name = "banana", .used = true};

	std::cout << "price original: " << dat.price << std::endl;
	uintptr_t uint = Serializer::serialize(&dat);
	std::cout << "Data* as uintptr_t = " << uint << std::endl;
	Data* dat2 = Serializer::deserialize(uint);
	dat2->price = 20;

	std::cout << "price through original: " << dat.price << std::endl;
	std::cout << "price through pointer : " << dat2->price << std::endl;
	if (dat2 != &dat)
		std::cout << "pointer are different ?" << std::endl;
	else
		std::cout << "cpp says pointer are the same (using `==`)" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:34:15 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/10 15:31:40 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <ostream>
int main()
{
	Brain *brain;
	// Animal *animal = new Animal(); // This doesn't compile
	Animal *dog = new Dog();
	Animal *cat = new Cat();
	Animal *cat_copied;
	std::cout << "animal type is: " << dog->getType() << " " << std::endl;
	std::cout << "animal type is: " << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();

	std::cout << "dog: " << std::endl;
	if ((brain = dog->getBrain()))
	{
		std::cout << "idea[50] " << *brain->getIdea(50) << std::endl;
		std::cout << "idea[10] " << *brain->getIdea(10) << std::endl;
		brain->setIdea(10, "banananan");
		std::cout << "idea[10] " << *brain->getIdea(10) << std::endl;
	}
	if ((brain = cat->getBrain()))
		brain->setIdea(50, "this is a idea of genius");
	cat_copied = new Cat(*(Cat *)cat);
	std::cout << "cat: " << std::endl;
	if ((brain = cat->getBrain()))
	{
		std::cout << "idea[50] " << *brain->getIdea(50) << std::endl;
		std::cout << "idea[10] " << *brain->getIdea(10) << std::endl;
		brain->setIdea(10, "banananan");
		std::cout << "idea[10] " << *brain->getIdea(10) << std::endl;
	}
	std::cout << "cat copied:" << std::endl;
	cat_copied->makeSound();
	if ((brain = cat_copied->getBrain()))
	{
		std::cout << "idea[50] " << *brain->getIdea(50) << std::endl;
		std::cout << "idea[10] " << *brain->getIdea(10) << std::endl;
		std::cout << "idea[11] " << *brain->getIdea(11) << std::endl;
		brain->setIdea(11, "bidule");
		std::cout << "idea[11] " << *brain->getIdea(11) << std::endl;
	}

	delete dog;
	delete cat;
	delete cat_copied;

	return 0;
}

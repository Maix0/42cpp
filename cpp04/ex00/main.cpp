/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:34:15 by maiboyer          #+#    #+#             */
/*   Updated: 2024/11/12 13:25:46 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Wrong.hpp"
#include <iostream>
#include <ostream>
int main()
{

	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	std::cout << "animal type is: " << animal->getType() << " " << std::endl;
	std::cout << "animal type is: " << dog->getType() << " " << std::endl;
	std::cout << "animal type is: " << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();

	delete animal;
	delete dog;
	delete cat;

	const WrongAnimal *wanimal = new WrongAnimal();
	const WrongAnimal *wdog = new WrongDog();
	const WrongAnimal *wcat = new WrongCat();
	std::cout << "animal type is: " << wanimal->getType() << " " << std::endl;
	std::cout << "animal type is: " << wdog->getType() << " " << std::endl;
	std::cout << "animal type is: " << wcat->getType() << " " << std::endl;
	wcat->makeSound();
	wdog->makeSound();
	wanimal->makeSound();

	delete wanimal;
	delete wdog;
	delete wcat;

	return 0;
}

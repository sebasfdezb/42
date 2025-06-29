/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:40:56 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 16:05:03 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/Animal.hpp"
#include "./inc/Dog.hpp"
#include "./inc/Cat.hpp"
#include "./inc/WrongAnimal.hpp"
#include "./inc/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	const WrongAnimal *k = new WrongAnimal();
	const WrongAnimal *l = new WrongAnimal();
	std::cout << k->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	k->makeSound();
	l->makeSound();
	delete meta;
	delete j;
	delete i;
	delete k;
	delete l;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:40:56 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 17:02:36 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/Animal.hpp"
#include "./inc/Dog.hpp"
#include "./inc/Cat.hpp"
#include "./inc/WrongAnimal.hpp"
#include "./inc/WrongCat.hpp"

/* int main()
{
	Animal* animals[4];
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	int i = 0;
	while(i < 4)
	{
		animals[i]->makeSound();
		i++;
	}
	int j = 0;
	while (j < 4)
	{
		delete animals[j];
		j++;
	}
	return (0);
}

 */

int main() 
{
    //Animal* b = new Animal();
    Animal* meta [4];
      
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
            meta [i] = new Dog();
        else
            meta [i] = new Cat();
        std::cout << " ~ Type: " << meta[i]->getType() << "\n";
        std::cout << " ~ Sound: ";
        meta[i]->makeSound();
        delete (meta[i]);
        std::cout << "\n";
    }
    return (0);
}
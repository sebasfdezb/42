/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:40:56 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 17:09:38 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/Animal.hpp"
#include "./inc/Dog.hpp"
#include "./inc/Cat.hpp"
#include "./inc/WrongAnimal.hpp"
#include "./inc/WrongCat.hpp"

int main()
{
    Animal* animals [4];
      
    for (int i = 0; i < 4; i++)
    {
        if (i % 2 == 0)
            animals [i] = new Dog();
        else
             animals [i] = new Cat();
        std::cout << " ~ Type: " << animals[i]->getType() << "\n";
        std::cout << " ~ Sound: ";
        animals[i]->makeSound();
        delete (animals[i]);
        std::cout << "\n";
    }
    return (0);
}
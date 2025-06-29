/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:09:55 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 20:20:51 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

class	Replace
{
	public:
		static int	replace(std::string filename, std::string s1, std::string s2);
};

#endif
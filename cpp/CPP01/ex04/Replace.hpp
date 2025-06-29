/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:09:55 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/03 20:14:39 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

class Replace
{
	private:
		std::string _inFile;
		std::string	_outFile;
	public:
		~Replace();
		Replace(std::string filename);
		
		void	replace (std::string s1, std::string s2);
};

#endif
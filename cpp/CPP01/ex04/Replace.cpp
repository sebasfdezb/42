/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:20:43 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/29 20:20:54 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"


int	Replace::replace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream	inputFile(filename.c_str());
	std::string		newFile = filename + ".replace";
	std::ofstream	outputFile(newFile.c_str());
	std::string		line;
	size_t			ptr;
	
	if (!inputFile.is_open())
	{
		std::cout << "Can't open file\n";
		return (1);
	}
	if (!outputFile.is_open())
	{
		std::cout << "Can't create output file\n";
		return (1); 
	}
	while (getline(inputFile, line))
	{
		ptr = 0;
		while ((ptr = line.find(s1, ptr)) != std::string::npos)
		{
			line.erase(ptr, s1.length());
			line.insert(ptr, s2);
			ptr += s2.length();
		}
		outputFile << line << std::endl;
	}
	outputFile.close();
	inputFile.close();
	return (0);
}

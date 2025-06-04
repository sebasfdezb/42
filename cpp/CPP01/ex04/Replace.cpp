/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:20:43 by sebferna          #+#    #+#             */
/*   Updated: 2025/06/04 19:27:04 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename) : _inFile(filename)
{
	this->_outFile = this->_inFile + ".replace";
}

Replace::~Replace(void)
{
}

void	Replace::replace(std::string toFind, std::string replace)
{
	std::ifstream ifs(this->_inFile.c_str());
	if (ifs.is_open())
	{
		std::string content;
		if (std::getline(ifs, content, '\0'))
		{
			std::ofstream ofs(this->_outFile.c_str());
			if (!ofs)
			{
				std::cerr << "Unable to open the output file." << std::endl;
				return ;
			}
			size_t pos = content.find(toFind);
			while (pos != std::string::npos)
			{
				content.erase(pos, toFind.length());
				content.insert(pos, replace);
				pos = content.find(toFind);
			}
			ofs << content;
		}
		else
			std::cerr << "Empty fie found." << std::endl;
		ifs.close();
	}
	else
	{
		std::cerr << "unable to open the input file." << std::endl;
		exit(EXIT_FAILURE);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:49:56 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/18 19:29:21 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <fstream>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "usage: " << argv[0] << " <filename> <pattern> <replace>" << std::endl;
		return 1;
	}

	std::string pattern = argv[2];
	std::string replace = argv[3];

	std::string input_filename = argv[1];
	std::string output_filename = input_filename + ".replace";

	std::ifstream input((char*)input_filename.c_str(), std::ios::in);
	std::ofstream output((char*)output_filename.c_str(), std::ios::out);

	if (input.fail() || output.fail())
	{
		std::cerr << "Error: input or output file failed to open" << std::endl;
		return 1;
	}

	while (!input.eof())
	{
		std::string line;
		std::getline(input, line);
		size_t pos = 0;
		size_t index = line.find(pattern, pos);
		while (index != std::string::npos)
		{
			line.erase(index, pattern.length());
			line.insert(index, replace);
			pos = index + replace.length();
			index = line.find(pattern, pos);
		}
		output << line;
		// do not output a newline if the file didn't have one right before the end
		if (!input.eof() && !input.fail())
			output << std::endl;
	}
}

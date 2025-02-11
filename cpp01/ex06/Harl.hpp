/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiboyer <maiboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:33:47 by maiboyer          #+#    #+#             */
/*   Updated: 2024/10/19 12:57:18 by maiboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
class Harl
{
public:
	Harl();
	~Harl();
	void complain(std::string level);
	void setFilter(std::string level);

private:
	static std::string levels[4];
	std::string		   filter;

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif /* HARL_HPP */

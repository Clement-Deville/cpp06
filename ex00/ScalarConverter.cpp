/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:27:11 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/27 18:50:01 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

# define NO_TYPE -1
# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3

int	detect_type(std::string &param)
{
	int		i;
	bool	digit(false);
	bool	dot(false);

	if (std::isdigit(param[0]) == false && param.length() == 1)
		return (CHAR);
	if (param.compare("-inf") || param.compare("+inf") || param.compare("nan"))
		return (FLOAT);
	if (param.compare("-inff") || param.compare("+inff") || param.compare("nanf"))
		return (DOUBLE);
	const char *str = param.c_str();
	i = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	if (str[i] && std::isdigit(str[i]))
		digit = true;
	while (str[i] && std::isdigit(str[i]))
		i++;
	if (str[i] && str[i] == '.')
	{
		i++;
		dot = true;
	}
	if (str[i] && std::isdigit(str[i]))
		digit = true;
	while (str[i] && std::isdigit(str[i]))
		i++;
	if (str[i] && str[i] == 'f' && str[i + 1] == '/0')
		return (digit == true ? FLOAT : NO_TYPE);
	if (!str[i] && digit)
		return (dot == true ? DOUBLE : INT);
	return (NO_TYPE);
}

void	display(void);

void ScalarConverter::convert(std::string param)
{

	switch (detect_type(param))
	{
	case CHAR:
	{
		//convertion
		display();
	}
		break;
	case INT:
	{
		//convertion
		display();
	}
		break;
	case FLOAT:
	{
		//convertion
		display();
	}
		break;
	case DOUBLE:
	{
		//convertion
		display();
	}
		break;
	default:
		break;
	}
}

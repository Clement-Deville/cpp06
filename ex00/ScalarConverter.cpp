/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:27:11 by cdeville          #+#    #+#             */
/*   Updated: 2024/11/29 16:13:23 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/**========================================================================
 *                            CANNONICAL DECLARATION
 *========================================================================**/

ScalarConverter::ScalarConverter()
{
	std::cout << "\e[0;32mScalarConverter Default constructor called\e[0m" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &Cpy)
{
	std::cout << "\e[0;32mScalarConverter Copy constructor called\e[0m" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &Cpy)
{
	std::cout << "\e[0;32mScalarConverter assignement operator called\e[0m" << std::endl;
	return (*this);
};

/**========================================================================
 *                           CONVERT FUNCTION
 *========================================================================**/

int	detect_type(std::string &param)
{
	int		i;
	bool	digit(false);
	bool	dot(false);

	if (std::isdigit(param[0]) == false && param.length() == 1)
		return (CHAR);
	if (!param.compare("-inf") || !param.compare("+inf") || !param.compare("nan"))
		return (FLOAT);
	if (!param.compare("-inff") || !param.compare("+inff") || !param.compare("nanf"))
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
	if (str[i] == 'f' && str[i + 1] == '\0')
		return (digit == true ? FLOAT : NO_TYPE);
	if (!str[i] && digit)
		return (dot == true ? DOUBLE : INT);
	return (NO_TYPE);
}

void	display(char c)
{
	if (std::isprint(c))
		std::cout << "char: " << static_cast<char>(c) << std::endl;
	else
		std::cout << "char: Not displayable" << std::endl;
	std::cout << std::fixed << std::setprecision(1);  // forcing un digit representation in decimal part
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
	std::cout.unsetf(std::ios::fixed | std::ios::scientific);
	std::cout << std::setprecision(6);
}

void	display(long long_nb)
{
	int nb;

	nb = static_cast<int>(long_nb);
	if ((nb > std::numeric_limits<unsigned char>::max() || nb < std::numeric_limits<unsigned char>::min()) == false
		&& std::isprint(static_cast<int>(nb)))
		std::cout << "char: " << (char)nb << std::endl;
	else
		std::cout << "char: Not displayable" << std::endl;
	std::cout << std::fixed << std::setprecision(1);  // forcing un digit representation in decimal part
	if (long_nb > std::numeric_limits<int>::max() || long_nb < std::numeric_limits<int>::min())
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << nb << std::endl;
		std::cout << "float: " << static_cast<float>(nb) << 'f' << std::endl;
		std::cout << "double: " << static_cast<double>(nb) << std::endl;
	}
	std::cout.unsetf(std::ios::fixed | std::ios::scientific);
	std::cout << std::setprecision(6);
}

void	display(float f)
{
	if ((f > std::numeric_limits<unsigned char>::max() || f < std::numeric_limits<unsigned char>::min()) == false
		&& f == f && std::isprint(static_cast<int>(f)))
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else
		std::cout << "char: Not displayable" << std::endl;
	if (static_cast<float>(f) - static_cast<int>(f) == 0.0)
		std::cout << std::fixed << std::setprecision(1);  // forcing un digit representation in decimal part;
	if (f != f || f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << static_cast<float>(f) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
	std::cout.unsetf(std::ios::fixed | std::ios::scientific);
	std::cout << std::setprecision(6);
}

void	display(double d)
{
	if ((d > std::numeric_limits<unsigned char>::max() || d < std::numeric_limits<unsigned char>::min()) == false
		&& d == d && std::isprint(static_cast<int>(d)))
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else
		std::cout << "char: Not displayable" << std::endl;
	if (static_cast<float>(d) - static_cast<int>(d) == 0.0)
		std::cout << std::fixed << std::setprecision(1);  // forcing un digit representation in decimal part
	if (d != d || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double: " << static_cast<float>(d) << std::endl;
	std::cout.unsetf(std::ios::fixed | std::ios::scientific);
	std::cout << std::setprecision(6);
}

void	ScalarConverter::convert(std::string param)
{
	switch (detect_type(param))
	{
	case CHAR:
	{
		std::cout << "This is a char: " << param << std::endl;
		display(param[0]);
	}
		break;
	case INT:
	{
		std::cout << "This is a INT: " << param << std::endl;
		display(std::atol(param.c_str()));
	}
		break;
	case FLOAT:
	{
		std::cout << "This is a FLOAT: " << param << std::endl;
		display(static_cast<float>(std::atof(param.c_str())));
	}
		break;
	case DOUBLE:
	{
		std::cout << "This is a DOUBLE: " << param << std::endl;
		display(std::atof(param.c_str()));
	}
		break;
	default:
		std::cerr << "No matching types for " << param << std::endl;
		break;
	}
}

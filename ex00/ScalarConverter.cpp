/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:27:11 by cdeville          #+#    #+#             */
/*   Updated: 2025/12/08 13:51:51 by cdeville         ###   ########.fr       */
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
	(void)Cpy;
	std::cout << "\e[0;32mScalarConverter Copy constructor called\e[0m" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &Cpy)
{
	(void)Cpy;
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
		return (DOUBLE);
	if (!param.compare("-inff") || !param.compare("+inff") || !param.compare("nanf"))
		return (FLOAT);
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

void	display(long long_nb)
{
	if ((long_nb > std::numeric_limits<unsigned char>::max() || long_nb < std::numeric_limits<unsigned char>::min()) == false
		&& std::isprint(static_cast<int>(long_nb)))
		std::cout << "char: \'" << (char)long_nb << "\'" << std::endl;
	else
		std::cout << "char: Not displayable" << std::endl;
	std::cout << std::fixed << std::setprecision(1);  // forcing un digit representation in decimal part
	if (long_nb > std::numeric_limits<int>::max() || long_nb < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(long_nb) << std::endl;
	std::cout << "float: " << static_cast<float>(long_nb) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(long_nb) << std::endl;
	std::cout.unsetf(std::ios::fixed | std::ios::scientific);
	std::cout << std::setprecision(6);
}

void	display(double d)
{
	if ((d > std::numeric_limits<unsigned char>::max() || d < std::numeric_limits<unsigned char>::min()) == false
		&& d == d && std::isprint(static_cast<int>(d)))
		std::cout << "char: \'" << static_cast<char>(d) << "\'" << std::endl;
	else
		std::cout << "char: Not displayable" << std::endl;
	if (static_cast<float>(d) - static_cast<int>(d) == 0.0)
		std::cout << std::fixed << std::setprecision(1);  // forcing un digit representation in decimal part
	if (d != d // checking nan, inf
		|| d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
	std::cout << "double: " << static_cast<float>(d) << std::endl;
	std::cout.unsetf(std::ios::fixed | std::ios::scientific);
	std::cout << std::setprecision(6);
}

void	display_error(void)
{
	std::cerr << "Impossible to convert the parameter into the corresponding type" << std::endl;
}

void	ScalarConverter::convert(std::string param)
{
	long	l_nb;
	double	d_nb;
	char	*end_ptr;

	l_nb = 0;
	d_nb = 0;
	switch (detect_type(param))
	{
	case CHAR:
	{
		std::cout << "This is a char: \"" << param << "\"" << std::endl;
		display(static_cast<long>(param[0]));
	}
		break;
	case INT:
	{
		std::cout << "This is a INT: \"" << param << "\"" << std::endl;
		l_nb = std::strtol(param.c_str(), &end_ptr, 10);
		if (&param.c_str()[param.size()] != end_ptr)
		{
			display_error();
			return;
		}
		display(l_nb);
	}
		break;
	case FLOAT:
	{
		std::cout << "This is a FLOAT: \"" << param << "\"" << std::endl;
		param.erase(param.size() - 1);
		d_nb = std::strtof(param.c_str(), &end_ptr);
		if (&param.c_str()[param.size()] != end_ptr)
		{
			display_error();
			return;
		}
		display(d_nb);
	}
		break;
	case DOUBLE:
	{
		std::cout << "This is a DOUBLE: \"" << param << "\"" << std::endl;
		d_nb = std::strtof(param.c_str(), &end_ptr);
		if (&param.c_str()[param.size()] != end_ptr)
		{
			display_error();
			return;
		}
		display(d_nb);
	}
		break;
	default:
		std::cerr << "No matching types for \"" << param << "\"" << std::endl;
		break;
	}
}

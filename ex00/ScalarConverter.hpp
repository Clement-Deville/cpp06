/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:24:19 by cdeville          #+#    #+#             */
/*   Updated: 2025/11/11 14:28:28 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <limits>
# include <iomanip>
# include <cmath>

# define NO_TYPE -1
# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &Cpy);
	virtual ~ScalarConverter() = 0;
	static void convert(const std::string param);

	ScalarConverter &operator=(const ScalarConverter &Cpy);
};

#endif

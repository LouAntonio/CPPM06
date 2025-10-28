/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:42:43 by lantonio          #+#    #+#             */
/*   Updated: 2025/10/28 12:03:07 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter constructor called!" << std::endl;	
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	(void)src;
	std::cout << "ScalarConverter cpy constructor called!" << std::endl;	
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	std::cout << "ScalarConverter assignment operator called!" << std::endl;
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructor called!" << std::endl;	
}

void	impossible() {
	std::cout << "Char: Impossible" << std::endl;
	std::cout << "Int: Impossible" << std::endl;
	std::cout << "Double: Impossible" << std::endl;
	std::cout << "Float: Impossible" << std::endl;
}

int		isSpecialCase(std::string literal) {
	if (literal == "nan" || literal == "nanf"
		|| literal == "-nan" || literal == "-nanf"
		|| literal == "+nan" || literal == "+nanf"
		|| literal == "-inf" || literal == "-inff"
		|| literal == "+inf" || literal == "+inff")
	{
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		if (literal == "nan" || literal == "nanf" || literal == "-nan" || literal == "-nanf" || literal == "+nan" || literal == "+nanf")
		{
			std::cout << "Float: nanf" << std::endl;
			std::cout << "Double: nan" << std::endl;
		} else if (literal == "+inf" || literal == "+inff") {
			std::cout << "Double: +inf" << std::endl;
			std::cout << "Float: +inff" << std::endl;
		} else if (literal == "-inf" || literal == "-inff") {
			std::cout << "Double: -inf" << std::endl;
			std::cout << "Float: -inff" << std::endl;
		}
		return 1;
	}
	return 0;
}

int	isChar(const char *literal)
{
	if (std::strlen(literal) > 1)
		return 0;
	char	c = literal[0];

	std::cout << "Char: " << c << std::endl;
	std::cout << "Int: " << static_cast<int>(c) << std::endl;
	std::cout << "Double: " << static_cast<double>(c) << std::endl;
	std::cout << "Float: " << static_cast<float>(c) << "f" << std::endl;
	return 1;
}

void 	ScalarConverter::convert(const char *literal)
{	
	if (isSpecialCase(literal)) return;
	errno = 0;
	char		*end_ptr;
	double		toDouble = std::strtod(literal, &end_ptr);

	std::cout << std::fixed << std::setprecision(1);
	if (isChar(literal))
		return;
	if (errno == ERANGE)
		impossible();
	else if (end_ptr == literal || *literal == '\0')
		impossible();
	else if (*end_ptr != '\0' && *end_ptr != 'f')
		impossible();
	else if (*end_ptr != '\0' && *(end_ptr + 1) != '\0')
		impossible();
	else {
		int toInt = static_cast<int>(toDouble);

		std::cout << "Double: " << toDouble << std::endl;
		std::cout << "Float: " << static_cast<float>(toDouble) << "f" << std::endl;

		if (toDouble > std::numeric_limits<int>::max() || toDouble < std::numeric_limits<int>::min())
			std::cout << "Int: Impossible" << std::endl;
		else
			std::cout << "Int: " << toInt << std::endl;
		if (!(toInt >= 32 && toInt <= 126))
			std::cout << "Char: Impossible" << std::endl;
		else
			std::cout << "Char: " << (char)toInt << std::endl;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:42:43 by lantonio          #+#    #+#             */
/*   Updated: 2025/10/21 11:50:45 by lantonio         ###   ########.fr       */
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
	if (literal == "-inff" || literal == "+inff"
		|| literal == "nanf" || literal == "-inf"
		|| literal == "+inf" || literal == "nan")
	{
		std::cout << "Char: Impossible" << std::endl;
		std::cout << "Int: Impossible" << std::endl;
		if (literal == "nan" || literal == "nanf")
		{
			std::cout << "Floar: nanf" << std::endl;
			std::cout << "Double: nan" << std::endl;
		} else {
			std::cout << "Floar: impossible" << std::endl;
			std::cout << "Double: impossible" << std::endl;
		}
		return 1;
	}
	return 0;
}

void 	ScalarConverter::convert(const char *literal) {
	char		*end_ptr;

	if (isSpecialCase(literal)) return;
	errno = 0;
	double		toDouble = std::strtod(literal, &end_ptr);

	if (errno == ERANGE)
	{
		std::cout << "Out of range!" << std::endl;
		impossible();
	}
	else if (literal == end_ptr)
	{
		std::cout << "Impossible to convert!" << std::endl;
		impossible();
	}
	else if (*end_ptr != '\0' && *end_ptr != 'f')
	{
		std::cout << "Inválid input (characters after value)!" << std::endl;
		impossible();
	}
	else {
		int value = static_cast<int>(toDouble);
		std::cout << std::fixed << std::setprecision(1);

		std::cout << "Double: " << toDouble << std::endl;
		std::cout << "Int: " << static_cast<int>(toDouble) << std::endl;
		std::cout << "Float: " << static_cast<float>(toDouble) << "f" << std::endl;
		if (!(value >= 32 && value <= 126))
			std::cout << "Char: Impossible" << std::endl;
		else
			std::cout << "Char: " << (char)value << std::endl;
	}
}

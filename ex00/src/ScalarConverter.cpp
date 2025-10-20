/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:42:43 by lantonio          #+#    #+#             */
/*   Updated: 2025/10/20 13:41:08 by lantonio         ###   ########.fr       */
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

void ScalarConverter::convert(const std::string &literal) {
	std::cout << "Parámetro recebido: " << literal << std::endl;
}
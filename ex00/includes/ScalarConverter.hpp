/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:28:02 by lantonio          #+#    #+#             */
/*   Updated: 2025/10/22 10:41:55 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER
#define SCALAR_CONVERTER

#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <iomanip>
#include <limits>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		virtual ~ScalarConverter();
	public:
		static void convert(const char *literal);
};

#endif

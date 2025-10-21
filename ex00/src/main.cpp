/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:42:52 by lantonio          #+#    #+#             */
/*   Updated: 2025/10/21 11:50:47 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int ac, char **av) {
	const char *tmp = "66.5f";
	if (ac == 2)
		tmp = av[1];
	const char *str = tmp;
	ScalarConverter::convert(str);
}

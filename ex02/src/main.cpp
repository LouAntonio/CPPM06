/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:39:33 by lantonio          #+#    #+#             */
/*   Updated: 2025/10/24 11:12:35 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate(void) {
	int debug = 0;
	std::srand(std::time(0));
	int escolha = std::rand() % 3;

	switch (escolha) {
		case 0:
			if (debug) std::cout << "O tipo original é A" << std::endl;
			return new A();
		case 1:
			if (debug) std::cout << "O tipo original é B" << std::endl;
			return new B();
		case 2:
			if (debug) std::cout << "O tipo original é C" << std::endl;
			return new C();
		default:
			if (debug) std::cout << "O tipo original é Base" << std::endl;
			return new Base();
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else if (dynamic_cast<Base*>(p))
		std::cout << "Base" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (std::exception &e) { }

	try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::exception &e) { }

	try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (std::exception &e) { }

	std::cout << "Base" << std::endl;
}

int main(void) {
	Base	*base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}

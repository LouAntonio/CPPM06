/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:39:33 by lantonio          #+#    #+#             */
/*   Updated: 2025/10/27 10:29:04 by lantonio         ###   ########.fr       */
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
			if (debug) std::cout << "The original class is A" << std::endl;
			return new A();
		case 1:
			if (debug) std::cout << "The original class is B" << std::endl;
			return new B();
		case 2:
			if (debug) std::cout << "The original class is C" << std::endl;
			return new C();
		default:
			if (debug) std::cout << "The original class is NULL" << std::endl;
			return NULL;
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
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (std::exception &e) { }

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::exception &e) { }

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (std::exception &e) { }

	std::cout << "Unknown" << std::endl;
}

int main(void) {
	Base	*base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}

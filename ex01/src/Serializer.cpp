/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:33:37 by lantonio          #+#    #+#             */
/*   Updated: 2025/10/22 15:46:12 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Serializer constructor called!" << std::endl;	
}

Serializer::Serializer(const Serializer &src) {
	(void)src;
	std::cout << "Serializer cpy constructor called!" << std::endl;	
}

Serializer &Serializer::operator=(const Serializer &src) {
	std::cout << "Serializer assignment operator called!" << std::endl;
	(void)src;
	return *this;
}

Serializer::~Serializer() {
	std::cout << "Serializer destructor called!" << std::endl;	
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t row) {
    
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:33:40 by lantonio          #+#    #+#             */
/*   Updated: 2025/10/23 11:28:51 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main(void)
{
	Data	data;
	data.name = "LouAntonio";
	data.value = 42;
	
	std::cout << "Before serialization:\nName: " << data.name << "\nValue: " << data.value << std::endl;
	uintptr_t test = Serializer::serialize(&data);
	
	std::cout << "\n---\n" << std::endl;
	
	Data* ptr = Serializer::deserialize(test);
	data = *ptr;
	std::cout << "After deserialization:\nName: " << data.name << "\nValue: " << data.value << std::endl;
	
	std::cout << "\n---\n" << std::endl;

	std::cout << "Values:\nptr: " << test << " | data: " << &data << std::endl;
	if (ptr == &data)
		std::cout << "They are the same!" << std::endl;
	else
		std::cout << "They are not the same!" << std::endl;

	return 0;
}

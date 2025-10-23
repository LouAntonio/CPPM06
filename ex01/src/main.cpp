/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:33:40 by lantonio          #+#    #+#             */
/*   Updated: 2025/10/23 10:42:09 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main(void)
{
	Data	dados;
	dados.name = "LouAntonio";
	uintptr_t teste = 123;

	std::cout << "Teste = " << teste << std::endl;
	teste = Serializer::serialize(&dados);
	std::cout << "Teste = " << teste << std::endl;
	
	std::cout << "Dados = " << dados.name << std::endl;
	Data* ptr = Serializer::deserialize(teste);
	dados = *ptr;
	std::cout << "Dados = " << dados.name << std::endl;

	return 0;
}

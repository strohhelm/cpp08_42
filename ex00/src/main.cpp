/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:36:09 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/20 16:20:09 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <stack>

int main (void)
{
	std::vector<int> vi (3, 700);
	std::array<std::string, 3> strarr = {"Hallo ", "what's ", "up?"};
	std::cout<<"\n=========finding an int in an array of strings========]\n"<<std::endl;
	try{
		easyfind(vi, 70);
	}catch(std::exception &e)
	{std::cout<<e.what()<<std::endl;}
	
	
}
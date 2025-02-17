/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:36:09 by pstrohal          #+#    #+#             */
/*   Updated: 2025/02/17 14:19:22 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/easyfind.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <stack>
#include <random>

int main (void)
{
	std::vector<int> vi (3, 700);
	for (auto it = vi.begin(); it < vi.end(); it++)
		std::cout<<*it<<std::endl;
	std::cout<<"\n=========finding an 70 in a vector of ints filled with value 700 ========]\n"<<std::endl;
	try{
		(void)easyfind(vi, 70);
	}catch(std::exception &e)
	{std::cout<<e.what()<<std::endl;}
	
	std::cout<<"\n=========finding an 700 in an array of ints all with value 700 ========]\n"<<std::endl;
	try{
		(void)easyfind(vi, 700);
		std::cout<<"Heck yeah there is one in there"<<std::endl;
	}catch(std::exception &e)
	{std::cout<<e.what()<<std::endl;}


	std::cout<<"\n=========finding an 700 in an array of ints all with value 700 ========]\n"<<std::endl;
	try{
		easyfind(vi, 700);
		std::cout<<"Heck yeah there is one in there"<<std::endl;
	}catch(std::exception &e)
	{std::cout<<e.what()<<std::endl;}


	std::stack<int> random;
	for(auto i = 0; i < 1000; i++)
	{
		std::srand(0);
		random.push(std::rand() % 1000000);
	}
	std::cout<<"\n=========finding a number in a stack of 1000 random numbers between 0 nd 1,000,000 ========]\n"<<std::endl;
	std::cout<<"what number are you trying to find?"<<std::endl;
	std::string input;
	std::cin>>input;
	try {
		int i = std::stoi(input);
		easyfind(random, i);
		std::cout<<"Heck yeah there is a "<<i<<" in there"<<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
}
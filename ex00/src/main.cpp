/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:36:09 by pstrohal          #+#    #+#             */
/*   Updated: 2025/02/18 15:14:25 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/easyfind.hpp"


int main (void)
{
	std::vector<int> vi (100, 700);
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



	std::random_device rd;   // Seed generator
    std::mt19937 gen(rd());  // Mersenne Twister RNG
    std::uniform_int_distribution<int> dist(0, 1000);  // Range: 0 to 1000

	std::cout<<"\n=========finding a number in an array of 1000 random numbers between 0 nd 1000 ========]\n"<<std::endl;
	std::array<int, 800> rando;
	for (auto i = 0; i < 800; i++)
	{
		rando[i] = dist(gen);
	}
	std::cout<<"what number are you trying to find (0 - 10,000)?"<<std::endl;
	std::string input;
	std::cin>>input;
	try {
		int i = std::stoi(input);
		easyfind(rando, i);
		std::cout<<"Heck yeah there is a "<<i<<" in there"<<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}

	
	std::cout<<"\n=========finding a number in a deque of 1000 random numbers between 0 nd 1000 ========]\n"<<std::endl;
	std::deque<int> deq;
	for(auto i = 0; i < 800; i++)
	{
		std::srand(0);
		deq.push_back(dist(gen));
	}
	int number = dist(gen);
	std::cout<<"lets see if there is a "<<number<<" in there!\n"<<std::endl;
	try {
		easyfind(deq, number);
		std::cout<<"Heck yeah there is a "<<number<<" in there"<<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}

	std::cout<<"\n=========finding a number in a list of 1000 random numbers between 0 nd 1000 ========]\n"<<std::endl;
	std::list<int> li;
	for(auto i = 0; i < 800; i++)
	{
		li.push_back(dist(gen));
	}
	int num = dist(gen);
	std::cout<<"lets see if there is a "<<num<<" in there!\n"<<std::endl;
	try {
		easyfind(li, number);
		std::cout<<"Heck yeah there is a "<<num<<" in there"<<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}}

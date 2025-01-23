/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:37:45 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/23 16:57:02 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include <random>
#include <stdexcept>
void input_test(void)
{
	try{
			
		unsigned int N;
		std::string t;
		std::cout<<"please enter Array size:"<<std::endl;
		std::cin>>t;
		N = std::stoi(t);
		Span a(N);
		for (unsigned int i = 0; i < N; i++)
		{
			std::cout<<"add number: ";
			std::cin>>t;
			a.addNumber(std::stoul(t));
		}
		std::cout<<"longest Span: "<<a.longestSpan()<<std::endl;
		std::cout<<"shortest Span: "<<a.shortestSpan()<<std::endl;
	}
	catch(std::exception &e)
	{
		std::cout<<"oops: "<<e.what()<<std::endl;
	}
	return ;
}
	
void test(void){
	try{
	unsigned int N;
	unsigned long l;
	std::string t;
	int p;
	int r1;
	int r2;
	
	std::cout<<"please enter Array size:"<<std::endl;
	std::cin>>t;
	l = std::stoul(t);
	if (l > std::numeric_limits<unsigned int>::max() || l < std::numeric_limits<unsigned int>::min())
		{throw std::overflow_error("max_size of unsigned int!!");}
	N = static_cast<unsigned int>(l);
	Span a(N);
	
	std::cout<<"please enter lowest number to generate:"<<std::endl;
	std::cin>>t;
	r1 = std::stoi(t);
	
	std::cout<<"please enter higest number to generate:"<<std::endl;
	std::cin>>t;
	r2 = std::stoi(t);

	std::random_device				device;
	std::mt19937						generator(device());
	std::uniform_int_distribution<>	distribution(r1, r2);
	std::cout<<"generating "<<N<<" numbers from "<<r1<<" to "<<r2<<std::endl;
	std::cout<<"adding the following random numbers:"<<std::endl;
	int percent = 0;
		for (unsigned int i = 0; i < N; i++)
		{
			p = distribution(generator);
			if (N < 10000000)
				std::cout<<p<<"|";
			else
			{if (i % (N / 100) == 0)
			{
				std::cout<<percent<<"%"<<std::endl;
				percent++;
			}}
			a.addNumber(p);
		}
		std::cout<<std::endl;
		std::cout<<"shortest span: "<<a.shortestSpan()<<std::endl;
		std::cout<<"longest Span: "<<a.longestSpan()<<std::endl;
	}
	catch(std::exception &e)
	{std::cout<<"opps someting wong here!"<<e.what()<<std::endl;};
	return ;
}

int main(int argc, char** argv)
{
	(void)argv;
	if (argc < 2)
	{
		Span a(10);
		a.addNumber(1);
		a.addNumber(5);
		a.addNumber(2);
		a.addNumber(8);
		a.addNumber(6);
		a.addNumber(9);
		a.addNumber(3);
		a.addNumber(7);
		a.addNumber(4);
		a.addNumber(10);
		try{a.addNumber(15);}
		catch(std::exception &e)
		{std::cout<<e.what()<<std::endl;}
		
		std::cout<<"shortest span: "<<a.shortestSpan()<<std::endl;
		std::cout<<"longest Span: "<<a.longestSpan()<<std::endl;
		
		std::cout <<"\n\n======= NOW subject test: =======\n"<<std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::random_device				device;
		std::mt19937					generator(device());
		std::uniform_int_distribution<>	distribution(-800, 800);
			
		std::cout <<"\n\n======= NOW for the many number fill: =======\n"<<std::endl;
		std::vector<int> tmp;
		Span exmpl1(80);
		Span exmpl2(70);
		for (int i = 0; i < 80; i++)
			tmp.push_back(distribution(generator));
		try{
			exmpl1.addNumber(tmp.begin(), tmp.end());
			std::cout << "shortest Span: "<<exmpl1.shortestSpan() << std::endl;
			std::cout << "longest Span: "<<exmpl1.longestSpan() << std::endl;
		}
		catch(std::exception& e){std::cout<<e.what();}
		
		try{
			exmpl2.addNumber(tmp.begin(), tmp.end());
			std::cout << exmpl2.shortestSpan() << std::endl;
			std::cout << exmpl2.longestSpan() << std::endl;
		}
		catch(std::exception& e){std::cout<<e.what();}
		
		
		std::cout <<"\n\n======= NOW for a not hardcoded test: =======\n"<<std::endl;
		input_test();
	}
	std::cout <<"\n\n======= NOW for a random test: =======\n"<<std::endl;

	test();

}
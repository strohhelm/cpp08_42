/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:25:11 by pstrohal          #+#    #+#             */
/*   Updated: 2025/02/18 14:53:48 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <limits>
#include <numeric>


class Span 
{
	public:
		Span()= delete;
		~Span() = default;
		Span(unsigned int N);
		Span(const Span& src) = default;
		Span& operator=(const Span& src);
		
		void addNumber(int num);
		void addNumber(std::vector<int>::iterator it1, std::vector<int>::iterator it2);
		long shortestSpan(void);
		long longestSpan(void);
		void printi(void);
		void printv(void);

		class NoSpanException : public std::exception
		{const char *what() const noexcept override;};
		class NoSizeException : public std::exception
		{const char *what() const noexcept override;};
		class SizeException : public std::exception
		{const char *what() const noexcept override;};
		
	private:
		std::vector<int>	_vec;
		std::vector<int>	_diff;
		unsigned int		_max;
		void	sort_and_diff(void);
};
#endif
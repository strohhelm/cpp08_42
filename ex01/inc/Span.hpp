/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:25:11 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/21 15:49:00 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <limits>

class Span 
{
	public:
		Span()= delete;
		~Span() = default;
		Span(unsigned int N);
		Span(const Span& src) = default;
		Span& operator=(const Span& src)=default;
		
		void addNumber(int num);
		int	shortestSpan(void) const;
		int	longestSpan(void) const;
		const std::vector<int>* getVector(void);
		
		class NoSpanException : public std::exception
		{const char *what() const noexcept override;};
		class SizeException : public std::exception
		{const char *what() const noexcept override;};
		
	private:
		std::vector<int>	_vec;
		unsigned int		_max;
		int					_maxValue;
		int					_minValue;
};
#endif
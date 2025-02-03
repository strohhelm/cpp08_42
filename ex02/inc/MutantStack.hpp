/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstrohal <pstrohal@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:09:19 by pstrohal          #+#    #+#             */
/*   Updated: 2025/01/26 12:03:27 by pstrohal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>


template <typename T>
class MutantStack :public std::stack<T>
{
	public:
		MutantStack() = default;
		~MutantStack() = default;
		MutantStack(const MutantStack& src) = default;
		MutantStack& operator=(MutantStack& src) = default;

		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		iterator begin(void){return this->c.begin();};
		iterator end(void){return this->c.end();};
		reverse_iterator rbegin(void){return this->c.rbegin();};
		reverse_iterator rend(void){return this->c.rend();};
		const_iterator cbegin(void){return this->c.cbegin();};
		const_iterator cend(void){return this->c.cend();};
		const_reverse_iterator crend(void){return this->c.crbegin();};
		const_reverse_iterator crbegin(void){return this->c.crend();};
};

#endif
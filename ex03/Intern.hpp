/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 14:20:11 by kuyu              #+#    #+#             */
/*   Updated: 2026/09/20 08:59:19 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>

class AForm;

class Intern
{
	private:
		AForm*	createShrubbery(const std::string& target) const;
		AForm*	createRobotomy(const std::string& target) const;
		AForm*	createPresidential(const std::string& target) const;
	public:
		Intern();
		Intern(const Intern& intern);
		Intern&	operator=(const Intern& other);
		~Intern();
		
		AForm*	makeForm(const std::string& formName,
			const std::string& formTarget) const;
};

#endif
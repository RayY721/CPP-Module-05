/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 15:26:46 by kuyu              #+#    #+#             */
/*   Updated: 2026/09/13 13:35:33 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	
}

Intern::Intern(const Intern& intern)
{
	(void)intern;
}

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
	
}

AForm*	Intern::createShrubbery(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createRobotomy(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createPresidential(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	std::string const formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	// function pointer
	AForm* (Intern::*createFunction[3])(const std::string& target) const = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*createFunction[i])(formTarget));
		}
	}
	std::cout << "Intern cannot create form: \"" << formName << "\" (unknown form name)" << std::endl;
	return (NULL);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:51:55 by kuyu              #+#    #+#             */
/*   Updated: 2026/09/20 10:52:27 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

static void	testCreation(Intern& intern, Bureaucrat& boss,
	const std::string& name, const std::string& target)
{
	std::cout << "\n===== Creating: " << name << " =====" << std::endl;

	AForm* form = intern.makeForm(name, target);

	if (form == NULL)
	{
		std::cout << "[FAIL] Intern returned NULL" << std::endl;
		return;
	}

	std::cout << "[PASS] Created: " << *form << std::endl;
	boss.signForm(*form);
	boss.executeForm(*form);
	delete form;
}

static void	testUnknownForm(Intern& intern)
{
	std::cout << "\n===== Unknown form =====" << std::endl;

	AForm* form = intern.makeForm("coffee request", "Bob");

	if (form == NULL)
		std::cout << "[PASS] Unknown form was rejected" << std::endl;
	else
	{
		std::cout << "[FAIL] Unknown form was created" << std::endl;
		delete form;
	}
}

int	main()
{
	std::srand(std::time(NULL));

	Intern		intern;
	Bureaucrat	boss("Boss", 1);

	testCreation(intern, boss, "shrubbery creation", "garden");
	testCreation(intern, boss, "robotomy request", "Bender");
	testCreation(intern, boss, "presidential pardon", "Arthur Dent");
	testUnknownForm(intern);

	return (0);
}

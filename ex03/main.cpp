/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:51:55 by kuyu              #+#    #+#             */
/*   Updated: 2026/09/13 13:35:00 by kuyu             ###   ########.fr       */
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

int main()
{
	std::srand(std::time(NULL));

	std::cout << "===== Test 1: Intern creates ShrubberyCreationForm ====="
			<< std::endl;
	try
	{
		Intern		intern;
		Bureaucrat	bob("Bob", 1);
		AForm*		form;

		form = intern.makeForm("shrubbery creation", "garden");

		if (form)
		{
			std::cout << *form << std::endl;
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	std::cout << "\n===== Test 2: Intern creates RobotomyRequestForm ====="
			<< std::endl;
	try
	{
		Intern		intern;
		Bureaucrat	bob("Bob", 1);
		AForm*		form;

		form = intern.makeForm("robotomy request", "Bender");

		if (form)
		{
			std::cout << *form << std::endl;
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	std::cout << "\n===== Test 3: Intern creates PresidentialPardonForm ====="
			<< std::endl;
	try
	{
		Intern		intern;
		Bureaucrat	bob("Bob", 1);
		AForm*		form;

		form = intern.makeForm("presidential pardon", "Arthur Dent");

		if (form)
		{
			std::cout << *form << std::endl;
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	std::cout << "\n===== Test 4: Unknown form ====="
			<< std::endl;
	try
	{
		Intern	intern;
		AForm*	form;

		form = intern.makeForm("coffee request", "Bob");

		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	std::cout << "\n===== Test 5: Bureaucrat cannot sign ====="
			<< std::endl;
	try
	{
		Intern		intern;
		Bureaucrat	bob("Bob", 150);
		AForm*		form;

		form = intern.makeForm("robotomy request", "Bender");

		if (form)
		{
			bob.signForm(*form);

			std::cout << "Form signed: "
					<< form->getIsSigned()
					<< std::endl;

			delete form;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	std::cout << "\n===== Test 6: Signed but cannot execute ====="
			<< std::endl;
	try
	{
		Intern		intern;
		Bureaucrat	signer("Signer", 70);
		Bureaucrat	executor("Executor", 50);
		AForm*		form;

		form = intern.makeForm("robotomy request", "Bender");

		if (form)
		{
			signer.signForm(*form);
			executor.executeForm(*form);

			delete form;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	std::cout << "\n===== Test 7: Multiple forms / polymorphism ====="
			<< std::endl;
	try
	{
		Intern		intern;
		Bureaucrat	boss("Boss", 1);

		AForm* forms[3];

		forms[0] = intern.makeForm("shrubbery creation", "home");
		forms[1] = intern.makeForm("robotomy request", "Marvin");
		forms[2] = intern.makeForm("presidential pardon", "Ford Prefect");

		for (int i = 0; i < 3; i++)
		{
			if (forms[i])
			{
				std::cout << "\n" << *forms[i] << std::endl;

				boss.signForm(*forms[i]);
				boss.executeForm(*forms[i]);

				delete forms[i];
			}
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}

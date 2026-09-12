/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:51:55 by kuyu              #+#    #+#             */
/*   Updated: 2026/09/12 14:08:41 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	std::cout << "===== Test 1: Form construction =====" << std::endl;
	try
	{
		ShrubberyCreationForm	shrubbery("home");
		RobotomyRequestForm		robotomy("Bender");
		PresidentialPardonForm	pardon("Arthur Dent");

		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << pardon << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 2: Execute unsigned form =====" << std::endl;
	try
	{
		Bureaucrat				bob("Bob", 1);
		ShrubberyCreationForm	form("unsigned_test");

		bob.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 3: Grade too low to sign =====" << std::endl;
	try
	{
		Bureaucrat				bob("Bob", 150);
		ShrubberyCreationForm	form("low_sign");

		bob.signForm(form);
		std::cout << "Form signed: "
				<< form.getIsSigned()
				<< std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 4: Signed but grade too low to execute =====" << std::endl;
	try
	{
		Bureaucrat				signer("Signer", 140);
		Bureaucrat				executor("Executor", 140);
		ShrubberyCreationForm	form("low_execute");

		signer.signForm(form);
		executor.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 5: Shrubbery success =====" << std::endl;
	try
	{
		Bureaucrat				bob("Bob", 1);
		ShrubberyCreationForm	form("garden");

		bob.signForm(form);
		bob.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 6: Robotomy =====" << std::endl;
	try
	{
		Bureaucrat			bob("Bob", 1);
		RobotomyRequestForm	form("Bender");

		bob.signForm(form);

		for (int i = 0; i < 10; i++)
			bob.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 7: Presidential pardon =====" << std::endl;
	try
	{
		Bureaucrat				bob("Bob", 1);
		PresidentialPardonForm	form("Arthur Dent");

		bob.signForm(form);
		bob.executeForm(form);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== Test 8: Polymorphism =====" << std::endl;
	try
	{
		Bureaucrat				bob("Bob", 1);
		ShrubberyCreationForm	shrubbery("polymorphic_garden");
		RobotomyRequestForm		robotomy("Marvin");
		PresidentialPardonForm	pardon("Ford Prefect");

		AForm* forms[3];

		forms[0] = &shrubbery;
		forms[1] = &robotomy;
		forms[2] = &pardon;

		for (int i = 0; i < 3; i++)
		{
			bob.signForm(*forms[i]);
			bob.executeForm(*forms[i]);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
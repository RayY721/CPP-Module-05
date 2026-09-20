/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:51:55 by kuyu              #+#    #+#             */
/*   Updated: 2026/09/20 10:50:35 by kuyu             ###   ########.fr       */
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

static void	testUnsignedForm()
{
	std::cout << "\n===== Unsigned form =====" << std::endl;

	Bureaucrat				boss("Boss", 1);
	ShrubberyCreationForm	form("unsigned");

	try
	{
		form.execute(boss);
		std::cout << "[FAIL] Execution should have thrown" << std::endl;
	}
	catch (const AForm::FormNotSignedException& e)
	{
		std::cout << "[PASS] Correct exception: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "[FAIL] Wrong exception: " << e.what() << std::endl;
	}
}

static void	testGradeTooLowToSign()
{
	std::cout << "\n===== Grade too low to sign =====" << std::endl;

	ShrubberyCreationForm	form("sign_test");
	Bureaucrat				weakSigner("Weak signer", 146);

	weakSigner.signForm(form);

	std::cout << "Signed: " << form.getIsSigned()
			<< " (expected 0)" << std::endl;
}

static void	testExactSignGrade()
{
	std::cout << "\n===== Exact grade can sign =====" << std::endl;

	ShrubberyCreationForm	form("sign_boundary");
	Bureaucrat				exactSigner("Exact signer", 145);

	exactSigner.signForm(form);

	std::cout << "Signed: " << form.getIsSigned()
			<< " (expected 1)" << std::endl;
}

static void	testGradeTooLowToExecute()
{
	std::cout << "\n===== Grade too low to execute =====" << std::endl;

	ShrubberyCreationForm	form("execute_test");
	Bureaucrat				signer("Signer", 145);
	Bureaucrat				weakExecutor("Weak executor", 138);

	signer.signForm(form);
	weakExecutor.executeForm(form);
}

static void	testExactExecuteGrade()
{
	std::cout << "\n===== Exact grade can execute =====" << std::endl;

	ShrubberyCreationForm	form("execute_boundary");
	Bureaucrat				signer("Signer", 145);
	Bureaucrat				exactExecutor("Exact executor", 137);

	signer.signForm(form);
	exactExecutor.executeForm(form);
}

static void	testAllForms()
{
	std::cout << "\n===== All forms through AForm pointers =====" << std::endl;

	Bureaucrat	boss("Boss", 1);
	AForm*		forms[3];

	forms[0] = new ShrubberyCreationForm("garden");
	forms[1] = new RobotomyRequestForm("Bender");
	forms[2] = new PresidentialPardonForm("Arthur Dent");

	for (int i = 0; i < 3; ++i)
	{
		std::cout << "\n" << *forms[i] << std::endl;
		boss.signForm(*forms[i]);
		boss.executeForm(*forms[i]);
		delete forms[i];
	}
}

int	main()
{
	std::srand(std::time(NULL));

	testUnsignedForm();
	testGradeTooLowToSign();
	testExactSignGrade();
	testGradeTooLowToExecute();
	testExactExecuteGrade();
	testAllForms();

	return (0);
}

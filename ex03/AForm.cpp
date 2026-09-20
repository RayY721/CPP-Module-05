/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 11:05:15 by kuyu              #+#    #+#             */
/*   Updated: 2026/09/20 11:14:49 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_isSigned = other.getIsSigned();
	return (*this);
}

AForm::~AForm()
{
	
}

const std::string&	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(Bureaucrat const& executor) const
{
	// handling the exception here
	if (!_isSigned)
		throw FormNotSignedException();
	if ( executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form has not been signed");
}

std::ostream&	operator<<(std::ostream& out, const AForm& Aform)
{
	out << "AForm Name: "
		<< Aform.getName()
		<< ", Sign Flag: "
		<< Aform.getIsSigned()
		<< ", Sign Grade: "
		<< Aform.getGradeToSign()
		<< ", Execute Grade: "
		<< Aform.getGradeToExecute();

	return (out);
}

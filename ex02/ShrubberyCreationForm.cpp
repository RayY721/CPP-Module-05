/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 12:47:29 by kuyu              #+#    #+#             */
/*   Updated: 2026/09/08 17:09:50 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	
}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream	file((_target + "_shrubbery").c_str());
	if (!file)
		throw std::runtime_error("Failed to open shrubbery file");

	file << "		/\\			" << std::endl;
	file << "	   /  \\		" << std::endl;
	file << "     /____\\		" << std::endl;
	file << "	 	||			" << std::endl;
	file << "		||			" << std::endl;

	file.close();
}

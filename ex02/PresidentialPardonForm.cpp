/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 12:59:49 by kuyu              #+#    #+#             */
/*   Updated: 2026/09/12 13:43:54 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	:AForm("PresidentialParardonForm", 25, 5), _target(target)
{
	
}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << _target
			<< " has been pardoned by Zaphod Beeblebrox."
			<< std::endl;
}

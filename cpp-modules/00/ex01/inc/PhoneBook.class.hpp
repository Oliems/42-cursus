/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:32:39 by mbarberi          #+#    #+#             */
/*   Updated: 2023/07/26 12:45:15 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

class PhoneBook {
public:
    PhoneBook( void );
    ~PhoneBook( void );

    void contact_add( void );
    void contact_print( int index );
    void contact_list( void );
    int get_size( void );

private:
    Contact _phonebook[ MAX_CONTACT ];
    int _size;
    int _index;
};

#endif

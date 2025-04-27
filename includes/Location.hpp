/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:06:35 by opdibia           #+#    #+#             */
/*   Updated: 2025/03/31 12:15:50 by opdi-bia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../includes/AnyValue.hpp"
#include <map>
#include <vector>
#include <string>
#include <iostream>

class Location {
private:
    std::map<std::string, AnyValue> _map_location;
    std::vector<std::string> _method; 
    std::vector<std::string> _cgiExt; 
    void check_value(const std::string &key, const AnyValue &value);
    void check_allowMethod(std::string value); 
    void check_autoindex(std::string value); 
    void check_body_size(std::string value);
    void check_errorPage(std::string value);
    void check_return(std::string value);
    void check_cgi_ext(std::string value);
    void check_cgi_enable(std::string value);

public:
    Location();
    Location(const Location& other);
    Location& operator=(const Location& other);
    ~Location();
    void  set_method(int i, const std::string &value);
    void  set_cgi_ext(int i, const std::string &value);
    void setValue(const std::string &key, const AnyValue&value);
    void  setMethod(std::string value);
    void  setCgiExt(std::string value);
    std::string  get_method(int i) const;
    std::string  get_cgiExt(int i) const;
    AnyValue getValue(const std::string &key) const;
    std::string get_nameLoc() const;
    size_t get_body_client() const;
    std::string get_error_page(std::string value) const;
    std::string get_root() const;
    std::string get_alias() const;
    std::string get_index() const;
    std::string get_autoindex() const;
    std::string get_return(std::string value) const;
    std::string get_cgi_enable() const;
    std::string get_cgi_extension() const;
    std::string get_cgi_path() const;
    bool is_emptyMethods();
    bool is_method(std::string str);
    bool is_cgiExt(std::string str);
    class WrongValueExeption : public std::exception {
    private:
        std::string message;

    public:
        explicit WrongValueExeption(const std::string& msg) : message(msg) {}

        virtual const char* what() const throw() {
            return message.c_str();
        }
        virtual ~WrongValueExeption() throw() {} 
    };
    class VectorExeption : public std:: exception
    {
        public :
        virtual const char* what() const throw()
        {
            return("method limit exceeded");
        }
    };
    void display() const;
};
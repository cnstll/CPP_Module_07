#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <string>
#include <iostream>

template <typename T>
void swap(T &a, T &b) {

	T temp = a;
	a = b;
	b = temp;
};

template <typename T>
T const &min(T const &a, T const &b){

	if (a == b)
		return b;
	else if (a > b)
		return b;
	else
		return a;
};

template <typename T>
T const &max(T const &a, T const &b){

	if (a == b)
		return b;
	else if (a > b)
		return a;
	else
		return b;
};

//Template specialization
template <>
void swap(std::string &a, std::string &b) {

	std::string temp = a;
	a = b;
	b = temp;
};

template <>
std::string const &min(std::string const &a, std::string const &b){

	int compare = a.compare(b);
	if (compare == 0)
		return b;
	else if (compare < 0)
		return a;
	else
		return b;
};

template <>
std::string const &max(std::string const &a, std::string const &b){

	int compare = a.compare(b);
	if (compare == 0)
		return b;
	else if (compare > 0)
		return a;
	else
		return b;
};
#endif

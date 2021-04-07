#pragma once
#include <iostream>
#include <vector>

class Set
{
private:
	std::vector<int> container;

public:
	Set() noexcept;
	std::vector<int> getElements() const noexcept;
	std::ostream& operator<<(Set const& s) const noexcept;
	Set operator+(Set const& s) const noexcept;
	Set operator-(Set const& s) const noexcept;
	Set operator+=(Set const& s) noexcept;
	Set operator-=(Set const& s) noexcept;
	Set operator+(int a) const noexcept;
	Set operator-(int a) const noexcept;
	Set operator+=(int a) noexcept;
	Set operator-=(int a) noexcept;
	Set operator*(Set const& s) const noexcept;
	bool isInSet(int a) const noexcept;
	bool isEmpty(int a) const noexcept;
	int count() const noexcept;


};

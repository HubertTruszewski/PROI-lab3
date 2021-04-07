#pragma once
#include <iostream>
#include <vector>

class Set
{
private:
	std::vector<int> container;
	size_t getPositionOfElement(int a) const;

public:
	Set() noexcept;
	Set(std::vector<int> const& numbers) noexcept;
	Set(Set const& set) noexcept;
	
	std::vector<int> getElements() const noexcept;

	Set operator+(Set const& s) const noexcept;
	Set operator-(Set const& s) const noexcept;
	Set operator+(int a) const noexcept;
	Set operator-(int a) const noexcept;
	
	void operator+=(Set const& s) noexcept;
	void operator-=(Set const& s) noexcept;
	void operator+=(int a) noexcept;
	void operator-=(int a) noexcept;

	Set operator*(Set const& s) const noexcept;
	
	bool isInSet(int a) const noexcept;
	bool isEmpty() const noexcept;
	
	size_t count() const noexcept;
};


std::ostream& operator<<(std::ostream& stream, Set const& s);
#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>


template < class T >
class Set
{
private:
	std::vector<T> container;
	size_t getPositionOfElement(T a) const
	{

		for (size_t i = 0; i < this->container.size(); i++)
		{
			if (a == this->container[i]) return i;
		}
		return 0;
	}

public:
	Set<T>() noexcept
	{

	}
	Set<T>(std::vector<T> const& numbers) noexcept
	{
		for (auto i : numbers)
		{
			if (!this->isInSet(i)) this->container.push_back(i);
		}
	}
	Set<T>(Set const& set) noexcept
	{
		this->container = set.getElements();
	}
	
	std::vector<T> getElements() const noexcept
	{
		return this->container;
	}

	Set<T> operator+(Set<T> const& s) const noexcept
	{
		Set<T> resultSet;
		for (auto i : this->container)
		{
			//if (!resultSet.isInSet(i)) resultSet += i;
			resultSet += i;
		}
		for (auto i : s.getElements())
		{
			//if (!resultSet.isInSet(i)) resultSet += i;
			resultSet += i;
		}
		return resultSet;
	}
	Set<T> operator-(Set<T> const& s) const noexcept
	{
		Set<T> resultSet;
		for (auto i : this->container)
		{
			if (!s.isInSet(i)) resultSet += i;
		}
		return resultSet;
	}
	Set<T> operator+(T a) const noexcept
	{
		Set<T> resultSet(*this);
		resultSet += a;
		return resultSet;
	}
	Set<T> operator-(T a) const noexcept
	{
		Set<T> resultSet(*this);
		resultSet -= a;
		return resultSet;
	}
	
	void operator+=(Set<T> const& s) noexcept
	{
		for (auto i : s.getElements())
		{
			if (!this->isInSet(i)) this->container.push_back(i);
		}
	}
	void operator-=(Set<T> const& s) noexcept
	{
		for (auto i : s.getElements())
		{
			if (this->isInSet(i)) this->container.erase(this->container.begin() + this->getPositionOfElement(i));
		}
	}
	void operator+=(T a) noexcept
	{
		if (!this->isInSet(a))
		{
			this->container.push_back(a);
		}
	}
	void operator-=(T a) noexcept
	{
		if (this->isInSet(a))
		{
			size_t elementPosition = this->getPositionOfElement(a);
			this->container.erase(this->container.begin() + elementPosition);
		}
	}

	Set<T> operator*(Set<T> const& s) const noexcept
	{
		Set resultSet;
		for (auto i : this->container)
		{
			if (s.isInSet(i) && !resultSet.isInSet(i)) resultSet += i;
		}

		return resultSet;
	}

	Set<T> complement(Set<T> const& s) const
	{
		Set<T> resultSet;
		for (auto i : this->container)
		{
			if(!s.isInSet(i)) throw std::domain_error("Given set is not superset");
		}
		for (auto i : s.getElements())
		{
			if (!this->isInSet(i)) resultSet += i;
		}
		return resultSet;
	}
	
	bool isInSet(T a) const noexcept
	{
		bool inSet = false;
		for (auto i : this->container)
		{
			if (i == a)
			{
				inSet = true;
				break;
			}
		}
		return inSet;
	}
	bool isEmpty() const noexcept
	{
		return this->container.empty();
	}
	
	size_t count() const noexcept
	{
		return this->container.size();
	}
};

template< class T >
std::ostream& operator<<(std::ostream& stream, Set<T> const& s)
{
	stream << "{";
	if (!s.isEmpty())
	{
		std::vector<T> elements = s.getElements();
		T last_element = elements.back();
		for (auto i : elements)
		{
			stream << i;
			if (i != last_element)
			{
				stream << ", ";
			}
		}
	}
	stream << "}";
	return stream;
}

namespace std
{

	template<class T> struct hash<Set<T>>
	{
		size_t operator()(Set<T> const& s) const noexcept
		{
			size_t sum_hash = 0;
			for (auto i : s.getElements())
			{
				sum_hash += pow(std::hash<T>{}(i) , 3);
			}
			size_t count_hash = std::hash<T>{}(s.count());
			return sum_hash ^ count_hash;
		}
	};
}
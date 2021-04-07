#include "SetLib.h"

size_t Set::getPositionOfElement(int a) const
{
	for (size_t i = 0; i < this->container.size(); i++)
	{
		if (a == this->container[i]) return i;
	}
	return 0;
}

Set::Set() noexcept
{
}

Set::Set(std::vector<int> const& numbers) noexcept
{
	for (auto i : numbers)
	{
		if (!this->isInSet(i)) this->container.push_back(i);
	}
}

Set::Set(Set const& set) noexcept
{
	this->container = set.getElements();
}

std::vector<int> Set::getElements() const noexcept
{
	return this->container;
}

Set Set::operator+(Set const& s) const noexcept
{
	Set resultSet;
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

Set Set::operator-(Set const& s) const noexcept
{
	Set resultSet;
	for (auto i : this->container)
	{
		if (!s.isInSet(i)) resultSet += i;
	}
	return resultSet;
}

Set Set::operator+(int a) const noexcept
{
	Set resultSet(*this);
	resultSet += a;
	return resultSet;
}

Set Set::operator-(int a) const noexcept
{
	Set resultSet(*this);
	resultSet -= a;
	return resultSet;
}


void Set::operator+=(Set const& s) noexcept
{
	for (auto i : s.getElements())
	{
		if (!s.isInSet(i)) this->container.push_back(i);
	}
}

void Set::operator-=(Set const& s) noexcept
{
	for (auto i : s.getElements())
	{
		if (this->isInSet(i)) this->container.erase(this->container.begin() + this->getPositionOfElement(i));
	}
}


void Set::operator+=(int a) noexcept
{
	if (!this->isInSet(a))
	{
		this->container.push_back(a);
	}
}


void Set::operator-=(int a) noexcept
{
	if (this->isInSet(a))
	{
		size_t elementPosition = this->getPositionOfElement(a);
		this->container.erase(this->container.begin() + elementPosition);
	}
}


Set Set::operator*(Set const& s) const noexcept
{
	Set resultSet;
	for (auto i : this->container)
	{
		if (s.isInSet(i) && !resultSet.isInSet(i)) resultSet += i;
	}

	return resultSet;
}

bool Set::isInSet(int a) const noexcept
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

bool Set::isEmpty(int a) const noexcept
{
	return this->container.size() == 0;
}

size_t Set::count() const noexcept
{
	return this->container.size();
}

std::ostream& operator<<(std::ostream& stream, Set const& s)
{
	std::vector<int> elements = s.getElements();
	int last_element = elements.back();
	std::cout << "{";
	for (auto i : elements)
	{
		std::cout << i;
		if (i != last_element)
		{
			std::cout << ", ";
		}
	}
	std::cout << "}" << std::endl;

	return stream;
}

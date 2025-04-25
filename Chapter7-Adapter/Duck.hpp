#pragma once


class Duck
{
	public:
		Duck() = default;
		~Duck() = default;
		virtual void quack() = 0;
		virtual void fly() = 0; 
};

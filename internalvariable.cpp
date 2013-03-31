//get methods
#ifndef _INTERNALVARIABLE_H_
#include "internalvariable.h"
#endif

#ifndef _STRING_H_
#include <string>
#endif

#ifndef _IOSTREAM_H_
#include <iostream>
#endif

#include <sstream>

InternalVariable::InternalVariable(bool value)
{
	this->value_type = Boolean;
	this->bool_value = value;
}

InternalVariable::InternalVariable(long long value)
{
	this->value_type = Integer;
	this->int_value = value;
}

InternalVariable::InternalVariable(long double value)
{
	this->value_type = Float;
	this->float_value = value;
}

InternalVariable::InternalVariable(std::string value)
{
	this->value_type = String;
	this->string_value = value;
}

InternalVariable::InternalVariable(char* value)
{
	this->value_type = String;
	this->string_value = std::string(value);
}

bool InternalVariable::get_bool_value()
{
	return this->bool_value;
}

long long InternalVariable::get_int_value()
{
	return this->int_value;
}

long double InternalVariable::get_float_value()
{
	return this->float_value;
}

std::string InternalVariable::get_string_value()
{
	return this->string_value;
}

VariableType InternalVariable::get_type()
{
	return this->value_type;
}

void InternalVariable::set_bool_value(bool value)
{
	this->bool_value = value;
}

void InternalVariable::set_int_value(long long value)
{
	this->int_value = value;
}

void InternalVariable::set_float_value(long double value)
{
	this->float_value = value;
}

void InternalVariable::set_string_value(std::string value)
{
	this->string_value = value;
}

void InternalVariable::set_string_value(char* value)
{
	this->string_value = std::string(value);
}

void InternalVariable::set_type(VariableType value)
{
	this->value_type = value;
}

InternalVariable& InternalVariable::operator=(long long value)
{
	this->value_type = Integer;
	this->int_value = value;
	return *this;
}

InternalVariable& InternalVariable::operator=(long double value)
{
	this->value_type = Float;
	this->float_value = value;
	return *this;
}

InternalVariable& InternalVariable::operator=(bool value)
{
	this->value_type = Boolean;
	this->bool_value = value;
	return *this;
}

InternalVariable& InternalVariable::operator=(std::string value)
{
	this->value_type = String;
	this->string_value = value;
	return *this;
}

InternalVariable& InternalVariable::operator=(char* value)
{
	this->value_type = String;
	this->string_value = std::string(value);
	return *this;
}

InternalVariable& InternalVariable::operator=(InternalVariable other)
{
	this->value_type = other.get_type();
	switch (this->value_type)
	{
		case Boolean:
			this->bool_value = other.get_bool_value();
			return *this;

		case Integer:
			this->int_value = other.get_int_value();
			return *this;

		case Float:
			this->float_value = other.get_float_value();
			return *this;

		case String:
			this->string_value = other.get_string_value();
			return *this;
	}
	return (*this); 
}

InternalVariable InternalVariable::operator+(bool value)
{
	switch (this->value_type)
	{
		case Boolean:
			return InternalVariable((long long)(this->bool_value + value));

		case Integer:
			return InternalVariable(this->int_value + (long long)(value));

		case Float:
			return InternalVariable(this->float_value + (long double)(value));

		case String:
			std::ostringstream temp;
			temp << this->string_value.data() << value;
			std::string temp2(temp.str());
			return InternalVariable(temp2);
	}
	return (*this); 
}

InternalVariable InternalVariable::operator+(long long value)
{
	switch (this->value_type)
	{
		case Boolean:
			return InternalVariable((long long)(this->bool_value) + value);

		case Integer:
			return InternalVariable(this->int_value + value);

		case Float:
			return InternalVariable(this->float_value + (long double)(value));

		case String:
			std::ostringstream temp;
			temp << this->string_value.data() << value;
			std::string temp2(temp.str());
			return InternalVariable(temp2);
	}
	return (*this); 
}

InternalVariable InternalVariable::operator+(long double value)
{
	switch (this->value_type)
	{
		case Boolean:
			return InternalVariable((long double)(this->bool_value) + value);

		case Integer:
			return InternalVariable((long double)(this->int_value) + value);

		case Float:
			return InternalVariable(this->float_value + value);

		case String:
			std::ostringstream temp;
			temp << this->string_value.data() << value;
			std::string temp2(temp.str());
			return InternalVariable(temp2);
	}
	return (*this); 
}

InternalVariable InternalVariable::operator+(std::string value)
{
	std::ostringstream temp;
	std::string temp2;
	switch (this->value_type)
	{
		case Boolean:
			temp.clear();
			temp << this->bool_value << value;
			temp2 = std::string(temp.str());
			return InternalVariable(temp2);

		case Integer:
			temp.clear();
			temp << this->int_value << value;
			temp2 = std::string(temp.str());
			return InternalVariable(temp2);

		case Float:
			temp.clear();
			temp << this->float_value << value;
			temp2 = std::string(temp.str());
			return InternalVariable(temp2);

		case String:
			temp2 = std::string(this->string_value.data()).append(value);
			return InternalVariable(temp2);
	}
	return (*this); 
}

InternalVariable InternalVariable::operator+(char* value)
{
	std::ostringstream temp;
	std::string temp2;
	switch (this->value_type)
	{
		case Boolean:
			temp.clear();
			temp << this->bool_value << value;
			temp2 = std::string(temp.str());
			return InternalVariable(temp2);

		case Integer:
			temp.clear();
			temp << this->int_value << value;
			temp2 = std::string(temp.str());
			return InternalVariable(temp2);

		case Float:
			temp.clear();
			temp << this->float_value << value;
			temp2 = std::string(temp.str());
			return InternalVariable(temp2);

		case String:
			temp2 = std::string(this->string_value.data()).append(std::string(value));
			return InternalVariable(temp2);
	}
	return (*this); 
}

InternalVariable InternalVariable::operator+(InternalVariable other)
{
	switch (other.value_type)
	{
		case Boolean:
			return (*this) + other.get_bool_value(); 

		case Integer:
			return (*this) + other.get_int_value(); 

		case Float:
			return (*this) + other.get_float_value(); 

		case String:
			return (*this) + other.get_string_value(); 
	}
	return (*this); 
}

InternalVariable InternalVariable::operator-(bool value)
{
	switch (this->value_type)
	{
		case Boolean:
			return InternalVariable((long long)(this->bool_value - value));

		case Integer:
			return InternalVariable(this->int_value - (long long)(value));

		case Float:
			return InternalVariable(this->float_value - (long double)(value));

		case String:
			return (*this);
	}
	return (*this); 
}

InternalVariable InternalVariable::operator-(long long value)
{
	switch (this->value_type)
	{
		case Boolean:
			return InternalVariable((long long)(this->bool_value) - value);

		case Integer:
			return InternalVariable(this->int_value - value);

		case Float:
			return InternalVariable(this->float_value - (long double)(value));

		case String:
			return (*this);
	}
	return (*this); 
}

InternalVariable InternalVariable::operator-(long double value)
{
	switch (this->value_type)
	{
		case Boolean:
			return InternalVariable((long double)(this->bool_value) - value);

		case Integer:
			return InternalVariable((long double)(this->int_value) - value);

		case Float:
			return InternalVariable(this->float_value - value);

		case String:
			return (*this);
	}
	return (*this); 
}

InternalVariable InternalVariable::operator-(InternalVariable other)
{
	switch (other.value_type)
	{
		case Boolean:
			return (*this) - other.get_bool_value(); 

		case Integer:
			return (*this) - other.get_int_value(); 

		case Float:
			return (*this) - other.get_float_value(); 

		case String:
			return (*this); 
	}
	return (*this); 
}

InternalVariable InternalVariable::operator*(bool value)
{
	switch (this->value_type)
	{
		case Boolean:
			return InternalVariable((long long)(this->bool_value * value));

		case Integer:
			return InternalVariable(this->int_value * (long long)(value));

		case Float:
			return InternalVariable(this->float_value * (long double)(value));

		case String:
			return (*this);
	}
	return (*this); 
}

InternalVariable InternalVariable::operator*(long long value)
{
	switch (this->value_type)
	{
		case Boolean:
			return InternalVariable((long long)(this->bool_value) * value);

		case Integer:
			return InternalVariable(this->int_value * value);

		case Float:
			return InternalVariable(this->float_value * (long double)(value));

		case String:
			return (*this);
	}
	return (*this); 
}

InternalVariable InternalVariable::operator*(long double value)
{
	switch (this->value_type)
	{
		case Boolean:
			return InternalVariable((long double)(this->bool_value) * value);

		case Integer:
			return InternalVariable((long double)(this->int_value) * value);

		case Float:
			return InternalVariable(this->float_value * value);

		case String:
			return (*this);
	}
	return (*this); 
}

InternalVariable InternalVariable::operator*(InternalVariable other)
{
	switch (other.value_type)
	{
		case Boolean:
			return (*this) * other.get_bool_value(); 

		case Integer:
			return (*this) * other.get_int_value(); 

		case Float:
			return (*this) * other.get_float_value(); 

		case String:
			return (*this); 
	}
	return (*this); 
}

InternalVariable InternalVariable::operator/(bool value)
{
	switch (this->value_type)
	{
		case Boolean:
			return (*this);

		case Integer:
			return InternalVariable(this->int_value / (long long)(value));

		case Float:
			return InternalVariable(this->float_value / (long double)(value));

		case String:
			return (*this);
	}
	return (*this); 
}

InternalVariable InternalVariable::operator/(long long value)
{
	switch (this->value_type)
	{
		case Boolean:
			return InternalVariable((long long)(this->bool_value) / value);

		case Integer:
			return InternalVariable(this->int_value / value);

		case Float:
			return InternalVariable(this->float_value / (long double)(value));

		case String:
			return (*this);
	}
	return (*this); 
}

InternalVariable InternalVariable::operator/(long double value)
{
	switch (this->value_type)
	{
		case Boolean:
			return InternalVariable((long double)(this->bool_value) / value);

		case Integer:
			return InternalVariable((long double)(this->int_value) / value);

		case Float:
			return InternalVariable(this->float_value / value);

		case String:
			return (*this);
	}
	return (*this); 
}

InternalVariable InternalVariable::operator/(InternalVariable other)
{
	switch (other.value_type)
	{
		case Boolean:
			return (*this) / other.get_bool_value(); 

		case Integer:
			return (*this) / other.get_int_value(); 

		case Float:
			return (*this) / other.get_float_value(); 

		case String:
			return (*this); 
	}
	return (*this); 
}

InternalVariable InternalVariable::operator%(long long value)
{
	switch (this->value_type)
	{
		case Boolean:
			return InternalVariable((long long)(this->bool_value) % value);

		case Integer:
			return InternalVariable(this->int_value % value);

		case Float:
			return InternalVariable(this->float_value);

		case String:
			return InternalVariable(this->string_value);
	}
	return (*this); 
}

InternalVariable InternalVariable::operator%(InternalVariable other)
{
	switch (other.value_type)
	{
		case Boolean:
			return (*this) / other.get_bool_value(); 

		case Integer:
			return (*this) / other.get_int_value(); 

		case Float:
			return (*this); 

		case String:
			return (*this); 
	}
	return (*this); 
}
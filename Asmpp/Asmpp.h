#pragma once

#include <vector>

using Register = int;

class Memory
{
public:
	Memory(int address, int value);

	int GetAddress() const;
	int GetValue() const;
private:
	int address_;
	int value_;
};
class Assembly
{
public:
	void mov(Register& lvalue, int address);
	void lea(Register& lvalue, int address);

	void add(Register& lvalue, Register address);
	void addv(Register& lvalue, int value);
	void sub(Register& lvalue, Register address);
	void subv(Register& lvalue, int value);
	void inc(Register& lvalue);
	void dec(Register& lvalue);

	void AddMemory(int address, int value);
	void AddMemory(const Memory& memory);
private:
	const Memory& GetMemory(int address);
	std::vector<Memory> memories_;
};
#include "Asmpp.h"
#include <string>

Memory::Memory(int address, int value)
{
	address_ = address;
	value_ = value;
}
int Memory::GetAddress() const
{
	return address_;
}
int Memory::GetValue() const
{
	return value_;
}

void Assembly::mov(Register& lvalue, int address)
{
	lvalue = GetMemory(address).GetValue();
}
void Assembly::lea(Register& lvalue, int address)
{
	lvalue = address;
}
void Assembly::add(Register& lvalue, Register address)
{
	lvalue += GetMemory(address).GetValue();
}
void Assembly::addv(Register& lvalue, int value)
{
	lvalue += value;
}
void Assembly::sub(Register& lvalue, Register address)
{
	lvalue -= GetMemory(address).GetValue();
}
void Assembly::subv(Register& lvalue, int value)
{
	lvalue -= value;
}
void Assembly::inc(Register& lvalue)
{
	lvalue++;
}
void Assembly::dec(Register& lvalue)
{
	lvalue--;
}
void Assembly::AddMemory(int address, int value)
{
	memories_.push_back(Memory(address, value));
}
void Assembly::AddMemory(const Memory& memory)
{
	memories_.push_back(memory);
}
const Memory& Assembly::GetMemory(int address)
{
	auto it = std::find_if(memories_.begin(), memories_.end(),
		[&address](const Memory& memory) { return memory.GetAddress() == address; });
	if (it == memories_.end()) return Memory(0, 0);

	return *it;
}
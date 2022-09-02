#include "Asmpp.h"
#include <iostream>

int main()
{
	auto code = Assembly();

	code.AddMemory(0x555555554000, 0x0000000000000000);
	code.AddMemory(0x555555554008, 0x0000000000000001);
	code.AddMemory(0x555555554010, 0x0000000000000003);
	code.AddMemory(0x555555554018, 0x0000000000000005);
	code.AddMemory(0x555555554020, 0x000000000003133A);

	Register rbx = 0x555555554000;
	Register rax = 0x31337;
	Register rcx = 0x2;

	code.add(rax, rbx + rcx * 8);
	code.addv(rcx, 2);
	code.sub(rax, rbx + rcx * 8);
	code.inc(rax);
	std::cout << std::hex << rax;
}
#pragma once
#include "ana.h"


typedef enum type {
	TYPE_BIT16, TYPE_BIT32
};

struct op {
	type size = TYPE_BIT32;
	bool parall = false;
};
struct fphead {
	op op[13];
	uint32 begin;
	uint32 end;
};
void get_fphead(uint32 code, fphead* _fp,uint32 ip);

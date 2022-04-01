#include "ana.h"
#include "fetch_packet.h"
#include "ida/include/tms6.hpp"
#include <stdio.h>




type get_insntype(ea_t ip,fphead fp) {
	if (ip<fp.end && ip>fp.begin) {						
		return fp.op[(ip - fp.begin) / 2].size;
	}
	return TYPE_BIT32;
}

int idaapi ana(insn_t* _insn) {
	insn_t& insn = *_insn;
	fphead fp;
	if (insn.ip & 1) {									//16位操作数
		for (int i = 0; i < 8; i++) {
			//insn.get_next_word();
			uint32 code = get_dword(insn.ip + 4 * i);
			if ((code & 0xE0000000) == 0xE0000000) {	// fphead	
				get_fphead(code, &fp, insn.ip + 4 * i);					// 得到fphead影响的位数
				break;									
			}
		}
	}
	if (get_insntype(insn.ip, fp) == TYPE_BIT16) {
		


	}
}
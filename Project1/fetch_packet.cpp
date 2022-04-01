#include "fetch_packet.h"
#include "ida/include/tms6.hpp"

// ªÒ»°fphead
void get_fphead(uint32 code, fphead* _fp,uint32 ip) {
	fphead& fp = *_fp;
	for (int i = 0; i < 8; i++) {
		if ((code >> (20 + i)) & BIT0) {
			fp.op[2 * i].size = TYPE_BIT16;
			fp.op[2 * i - 1].size = TYPE_BIT16;
		}
	}
	for (int i = 0; i < 14; i++) {
		if ((code >> i) & BIT0) {
			fp.op[i].parall = true;
			if (fp.op[i].size != TYPE_BIT16) {
				fp.op[i].parall = false;
			}
		}
	}
	fp.end = ip;
	fp.begin = ip - 28;
}


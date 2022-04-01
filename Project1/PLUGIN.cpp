#include "PLUGIN.h"
#include "ana.h"
ssize_t idaapi hook(void* user_data, int notification_code, va_list va) {
	switch (notification_code) {
	case processor_t::ev_ana_insn: {
		insn_t* out = va_arg(va, insn_t*);
		ana(out);
		return 2;
		}
	}
	return 0;
}


plugmod_t* idaapi init() {
	if (ph.id != PLFM_TMSC6) return PLUGIN_SKIP;
	hook_to_notification_point(HT_IDP,hook, NULL);

	return PLUGIN_KEEP;
}


plugin_t PLUGIN = {
	IDP_INTERFACE_VERSION,
	PLUGIN_DRAW | PLUGIN_PROC | PLUGIN_MULTI,
	init,
	nullptr,
	nullptr,
	nullptr,
	"support to tmsc66x",
	"tmsc66x_plugin",
	nullptr
};
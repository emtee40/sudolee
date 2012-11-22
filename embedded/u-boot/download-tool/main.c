#include "clk_pwr.h"
#include "memory.h"
#include "debug.h"


#if 0
static init_func_t *init_tbl[] = {
//	led_init,
	cpm_init,
	mem_init,
	NULL
};
#endif

void c_start(void)
{
#if 0
	init_func_t **init_funcp;
	u32 i = 0;

	for(init_funcp = init_tbl; *init_funcp; ++init_funcp) {
		(*init_funcp)();
		led_run(i++);
	}
#else
	clk_pwr_init();
	led_run(0);
	memory_init();
	led_run(1);
#endif

	asm("b .");	/* hang there */
}
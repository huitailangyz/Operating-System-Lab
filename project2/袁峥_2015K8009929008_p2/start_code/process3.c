#include "common.h"
#include "syslib.h"
#include "util.h"

void _start(void)
{
	/* need student add */
	int i;
	for (i=0; i<100; i++)
		yield();
	exit();
}

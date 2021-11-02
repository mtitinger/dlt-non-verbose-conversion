/*
 *
 **/
#include <netdb.h>
#include <ctype.h>
#include <stdio.h>      /* for printf() and fprintf() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */

#include "dlt/dlt.h"
#include "dlt/dlt_common.h" /* for dlt_get_version() */
#include "dlt/dlt_common_api.h" /* for dlt_get_version() */

//#include "generated/dlt_id_APPT.h"

DLT_DECLARE_CONTEXT(mycontext1);
DLT_DECLARE_CONTEXT(mycontext2);
DLT_DECLARE_CONTEXT(mycontext3);

int main (char** argv, int argc)
{

	DLT_REGISTER_APP("APPT", "Test Application for Logging");
	DLT_REGISTER_CONTEXT(mycontext1, "BLAH", "Test Context for Logging");

	//dlt_nonverbose_mode();

	/* DLT messages to test Fibex non-verbose description: dlt-example-non-verbose.xml */
DLT_LOG(mycontext1, DLT_LOG_INFO, DLT_UINT16(1011));
DLT_LOG(mycontext1, DLT_LOG_INFO, DLT_UINT32(1012),DLT_UINT32(1013));
DLT_LOG(mycontext1, DLT_LOG_INFO, DLT_UINT8(123),DLT_FLOAT32(1.12));
DLT_LOG(mycontext1, DLT_LOG_INFO, DLT_STRING("DEAD BEEF"));

	sleep(1);

	DLT_UNREGISTER_CONTEXT(mycontext1);

	DLT_UNREGISTER_APP();

}

#include "event.h"

/* Server port number.*/
const u_short PORT = 10000;

int main (void) 
{
	
	/* Logging server port number.*/
	INET_Addr server_addr (PORT);
	
	/* Initialize logging server endpoint and register
	 * with the Initiation_Dispatcher.
	 */
	Logging_Acceptor la (server_addr);
	
	/* Main event loop that handles client
	 * logging records and connection requests.
	 */
	
	for (;;){		
		Initiation_Dispatcher::instance ()->handle_events ();
	}
	
	/* NOTREACHED */ 
	return 0;
}


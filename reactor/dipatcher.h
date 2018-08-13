#ifndef _DISPATCHER_H
#define _DISPATCHER_H

enum Event_Type {
	// Types of events handled by the
	// Initiation_Dispatcher. These values are powers of
	// two so their bits can be efficiently “or’d”
	// together to form composite values
	ACCEPT_EVENT = 01,
	READ_EVENT = 02,
	WRITE_EVENT = 04,
	TIMEOUT_EVENT = 010,
	SIGNAL_EVENT = 020,
	CLOSE_EVENT = 040
};


class Initiation_Dispatcher {
	// Demultiplex and dispatch Event_Handlers
	// in response to client requests.
	public:
	// Register an Event_Handler of a particular
	// Event_Type.
	int register_handler (Event_Handler *eh,
	Event_Type et);
	// Remove an Event_Handler of a particular
	// Event_Type.
	int remove_handler (Event_Handler *eh,
	Event_Type et);
	// Entry point into the reactive event loop.
	int handle_events (Time_Value *timeout = 0);
};

#endif

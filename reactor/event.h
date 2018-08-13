#ifndef _EVENT_H
#define _EVENT_H

class Event_Handler {
	// Abstract base class that serves as the
	// target of the Initiation_Dispatcher.
	public:
	// Hook method that is called back by the
	// Initiation_Dispatcher to handle events.
	virtual int handle_event (Event_Type et) = 0;
	// Hook method that returns the underlying
	// I/O Handle.
	virtual Handle get_handle (void) const = 0;
};


#endif

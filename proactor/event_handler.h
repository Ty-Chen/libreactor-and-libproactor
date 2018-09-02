class Completion_Handler {
public:
// Hook method that is called back by the
// Proactor to handle events of a particular type. The
// <Async_Result> parameter contains both the
// information about the completed asynchronous
// operation as well as the corresponding ACT.
virtual int handle_event
(Event_Type et,
 const Asynch_Stream::Asynch_Result &result) = 0;
// Hook method that returns the underlying I/O Handle.
virtual Handle get_handle (void) const = 0;
}; 

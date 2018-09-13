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


class Completion_Handler {
public:
// Hook methods that are called back by the Proactor
// to handle particular types of notifications.
// Sets proactor to <p>.
Completion_Handler (Proactor *p);
// Virtual destruction.
virtual ~Completion_Handler (void);
// This method will be called when an
// asynchronous read completes on a stream.
virtual void handle_read_stream
(const Asynch_Stream::Read_Result &result) = 0;
// This method will be called when an
// asynchronous write completes on a stream.
virtual void handle_write_stream
(const Asynch_Stream::Write_Result &result) = 0;
// This method will be called when an
// asynchronous accept completes.
virtual void handle_accept
(const Asynch_Stream::Accept_Result &result) = 0;
// This method will be called when an
// asynchronous transmit file completes.
virtual void handle_time_out
(const Time_Value &tv, const void *act) = 0;
// Hook method that returns the underlying I/O Handle.
virtual Handle get_handle (void) const = 0;
}; 

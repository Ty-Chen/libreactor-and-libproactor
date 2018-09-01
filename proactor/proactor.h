class Proactor {
public:
// Entry point into the proactive event loop.
int handle_events (Time_Value *wait_time = 0);
// Singleton access point.
static Proactor *instance (void);
private:
};

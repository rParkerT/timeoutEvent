#include "event.h"

namespace event {

Event::Event(EventId eventId, EventData &&eventData)
    : eventId(eventId), eventData(std::move(eventData)) {}

} // namespace event

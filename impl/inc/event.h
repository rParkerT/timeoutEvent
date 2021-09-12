#pragma once

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <variant>

namespace event {

/**
 * Implementation of Event class.
 *
 * Event class has two event types, 10s and 20s events, defined in EventId enum
 * class. Structure of these two events are defined in  Event10sData and
 * Event20sData. Each structure has info about event, as well as timeCreation,
 * time in which the event has been created. Event is constructed using EventId
 * and EventData, which is a variant of two event data, Event10sData and
 * Event20sData.
 *
 */
class Event {
public:
  /**
   * EventId enum class with two enums for 10s and 20s event.
   */
  enum class EventId { event10s, event20s };

  /**
   * Event10sData struct.
   *
   * @param info Event info
   * @param timeCreation time when Event was created
   */
  struct Event10sData {
    std::string info = "10 sec timeout event";
    time_t timeCreation;
  };

  /**
   * Event20sData struct.
   *
   * @param info Event info
   * @param timeCreation time when Event was created
   */
  struct Event20sData {
    std::string info = "20 sec timeout event";
    time_t timeCreation;
  };

  /**
   * Variant that takes data for 10s and 20s event.
   */
  using EventData = std::variant<Event10sData, Event20sData>;

  EventId eventId;
  EventData eventData;

  /**
   * Constructor of Event
   *
   * @param eventId EventId enum object
   * @param eventData EventData object, that can be of Event10sData and
   * Event20sData
   */
  Event(EventId eventId, EventData &&eventData);

  /**
   * Copy Constructor of Event
   *
   * Default implementation
   */
  Event(const Event &event) = default;

  /**
   * Copy Assignment Operator for Event
   *
   * Default implementation
   */
  Event &operator=(const Event &event) = default;

  /**
   * Move Constructor of Event
   *
   * Default implementation
   */
  Event(Event &&event) = default;

  /**
   * Move Assignment Operator for Event
   *
   * Default implementation
   */
  Event &operator=(Event &&event) = default;

  /**
   * Destructor of Event
   *
   * Default implementation
   */
  ~Event() = default;
};

} // namespace event

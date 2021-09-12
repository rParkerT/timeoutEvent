#pragma once

#include "event.h"
#include <thread>
#include <vector>

namespace event {

/**
 * Implementation of Dispatcher class.
 *
 * Dispatcher class handles subscription for two events, 10s and 20s event.
 * After receiving subscription request from EventHandler, two independent
 * threads are created, for each event. Thread that is created for 10s event
 * will sleep for 10s, then it will create 10s event, defining time of creation
 * of this event. Thread that is created for 20s event
 * will sleep for 20s, then it will create 20s event, defining time of creation
 * of this event. After creation of these events, EventHandler is informed that
 * these events were created and there will be consol output of events' data.
 *
 */
class Dispatcher {
private:
  /**
   * sendEvent10s function runs on thread that sleeps for 10s, then it fetches
   * time, creates 10s event and informs EventHandler that the event has been
   * created.
   *
   * @param eventId EventId
   * @param fnHandleEvent function pointer to EventHandler function, that
   * handles event
   */
  void sendEvent10s(
      Event::EventId eventId,
      std::function<void(const std::unique_ptr<Event> &)> fnHandleEvent);

  /**
   * sendEvent20s function runs on thread that sleeps for 20s, then it fetches
   * time, creates 20s event and informs EventHandler that the event has been
   * created.
   *
   * @param eventId EventId
   * @param fnHandleEvent function pointer to EventHandler function, that
   * handles event
   */
  void sendEvent20s(
      Event::EventId eventId,
      std::function<void(const std::unique_ptr<Event> &)> fnHandleEvent);

public:
  /**
   * Constructor of Dispatcher
   *
   * Default implementation
   */
  Dispatcher();

  /// Disabling construction of Dispatcher object using copy constructor
  Dispatcher(const Dispatcher &) = delete;

  /// Disabling construction of Dispatcher object using copy assignment
  Dispatcher &operator=(const Dispatcher &) = delete;

  /// Disabling construction of Dispatcher object using move constructor
  Dispatcher(Dispatcher &&) = delete;

  /// Disabling construction of Dispatcher object using move assignment
  Dispatcher &operator=(Dispatcher &&) = delete;

  /**
   * Destructor of Dispatcher
   *
   * Default implementation
   */
  ~Dispatcher();

  /**
   * subscribeToEvent is called from EventHandler, it receives eventIds of
   * subscribed events and function pointer on EventHandler function that
   * handles received events. It creates two threads, one for each event. Thread
   * created for 10s event calls sendEvent10s function, while thread created for
   * 20s event calls sendEvent20s function.
   *
   * @param eventId1 EventId of 10s event
   * @param eventId2 EventId of 20s event
   * @param fnHandleEvent function pointer to EventHandler function, that
   * handles event
   */
  void subscribeToEvent(
      Event::EventId eventId1, Event::EventId eventId2,
      std::function<void(const std::unique_ptr<Event> &)> fnHandleEvent);
};

} // namespace event

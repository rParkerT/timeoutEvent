#pragma once

#include "dispatcher.h"
#include <functional>
#include <memory>

namespace event {

/**
 * Implementation of EventHandler class.
 *
 * EventHandler class handles subscription for two events, 10s and 20s event,
 * and handles these events, when received. EventHandler sends subscription
 * request to dispatcher. When these events are produced, dispatcher informs
 * EventHanlder's handleEvent function, that outputs info about received events.
 *
 */
class EventHandler {
private:
  /**
   * Upon receiving event from dispatcher, this function prints received event
   * data, info and time of creation.
   *
   * @param event ptr to created event
   */
  void handleEvent(const std::unique_ptr<Event> &event);

public:
  /**
   * Dispatcher object that is being constructed upon EventHandler object
   * construction.
   */
  Dispatcher dispatcher;

  /**
   * Constructor of EventHandler
   *
   * Initializes also dispatcher object
   */
  EventHandler();

  /// Disabling construction of EventHandler object using copy constructor
  EventHandler(const EventHandler &) = delete;

  /// Disabling construction of EventHandler object using copy assignment
  EventHandler &operator=(const EventHandler &) = delete;

  /// Disabling construction of EventHandler object using move constructor
  EventHandler(EventHandler &&) = delete;

  /// Disabling construction of EventHandler object using move assignment
  EventHandler &operator=(EventHandler &&) = delete;

  /**
   * Destructor of EventHandler
   *
   * Default implementation
   */
  ~EventHandler() = default;

  /**
   * Sends eventIds for 10s and 20s event and function pointer on handleEvent
   * function to dispatcher. It also prints time when subscription started.
   */
  void startSubsription();
};

} // namespace event

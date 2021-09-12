#include "eventHandler.h"

namespace event {

EventHandler::EventHandler() : dispatcher() {}

void EventHandler::startSubsription() {
  time_t now =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::cout << "Subscription to TimeoutEvent started at: " << std::ctime(&now)
            << std::endl;
  dispatcher.subscribeToEvent(
      Event::EventId::event10s, Event::EventId::event20s,
      std::bind(&EventHandler::handleEvent, this, std::placeholders::_1));
}

void EventHandler::handleEvent(const std::unique_ptr<Event> &event) {
  if (event->eventId == Event::EventId::event10s) {
    const auto &eventData = std::get<Event::Event10sData>(event->eventData);
    const auto &time = eventData.timeCreation;
    const auto &info = eventData.info;
    std::cout << info << " " << std::ctime(&time) << std::endl;
  } else if (event->eventId == Event::EventId::event20s) {
    const auto &eventData = std::get<Event::Event20sData>(event->eventData);
    const auto &time = eventData.timeCreation;
    const auto &info = eventData.info;
    std::cout << info << " " << std::ctime(&time) << std::endl;
  }
}
} // namespace event

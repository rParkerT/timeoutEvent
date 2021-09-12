#include "dispatcher.h"
#include <algorithm>

namespace event {

Dispatcher::Dispatcher() {}

Dispatcher::~Dispatcher() {}

void Dispatcher::subscribeToEvent(
    Event::EventId eventId1, Event::EventId eventId2,
    std::function<void(const std::unique_ptr<Event> &)> fnHandleEvent) {
  std::thread thread1(&Dispatcher::sendEvent10s, this, eventId1, fnHandleEvent);
  std::thread thread2(&Dispatcher::sendEvent20s, this, eventId2, fnHandleEvent);
  thread1.join();
  thread2.join();
}

void Dispatcher::sendEvent10s(
    Event::EventId eventId,
    std::function<void(const std::unique_ptr<Event> &)> fnHandleEvent) {
  std::this_thread::sleep_for(std::chrono::seconds(10));
  Event::Event10sData event10sData;
  event10sData.timeCreation =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  Event::EventData eventData{event10sData};
  std::unique_ptr timeout10sEvent = std::make_unique<Event>(
      Event::EventId::event10s, std::forward<Event::EventData>(eventData));
  fnHandleEvent(std::move(timeout10sEvent));
}

void Dispatcher::sendEvent20s(
    Event::EventId eventId,
    std::function<void(const std::unique_ptr<Event> &)> fnHandleEvent) {
  std::this_thread::sleep_for(std::chrono::seconds(20));
  Event::Event20sData event20sData;
  event20sData.timeCreation =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  Event::EventData eventData{event20sData};
  std::unique_ptr timeout20sEvent = std::make_unique<Event>(
      Event::EventId::event20s, std::forward<Event::EventData>(eventData));
  fnHandleEvent(std::move(timeout20sEvent));
}
} // namespace event

#include "event.h"
#include "eventHandler.h"
#include <catch.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

// https://github.com/catchorg/Catch2/blob/devel/docs/matchers.md#using-matchers

TEST_CASE("Event test") {
  event::Event::Event10sData event10sData;
  event10sData.timeCreation =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  event::Event::EventData eventData{event10sData};
  event::Event timeout10sEvent{
      event::Event::EventId::event10s,
      std::forward<event::Event::EventData>(eventData)};

  const auto &eventData10s =
      std::get<event::Event::Event10sData>(timeout10sEvent.eventData);
  const auto &infoEvent = eventData10s.info;
  std::string info = "10 sec timeout event";
  CHECK(infoEvent == info);

  event::Event::Event20sData event20sData;
  event20sData.timeCreation =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  event::Event::EventData eventData1{event20sData};
  event::Event timeout20sEvent{
      event::Event::EventId::event20s,
      std::forward<event::Event::EventData>(eventData1)};

  const auto &eventData20s =
      std::get<event::Event::Event20sData>(timeout20sEvent.eventData);
  const auto &infoEvent1 = eventData20s.info;
  std::string info1 = "20 sec timeout event";
  CHECK(infoEvent1 == info1);
}

TEST_CASE("Event Check Copy and Move Constructors/Assignment "
          "operators") {
  event::Event::Event10sData event10sData;
  event10sData.timeCreation =
      std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  event::Event::EventData eventData{event10sData};
  event::Event timeout10sEvent{
      event::Event::EventId::event10s,
      std::forward<event::Event::EventData>(eventData)};

  event::Event event1{timeout10sEvent};
  const auto &eventData10s =
      std::get<event::Event::Event10sData>(timeout10sEvent.eventData);
  const auto &infoEvent = eventData10s.info;
  const auto &time = eventData10s.timeCreation;

  const auto &eventData1 =
      std::get<event::Event::Event10sData>(event1.eventData);
  const auto &infoEvent1 = eventData1.info;
  const auto &time1 = eventData1.timeCreation;
  CHECK(infoEvent == infoEvent1);
  CHECK(time == time1);

  event::Event event2 = event1;
  const auto &eventData2 =
      std::get<event::Event::Event10sData>(event2.eventData);
  const auto &infoEvent2 = eventData2.info;
  const auto &time2 = eventData2.timeCreation;
  CHECK(infoEvent1 == infoEvent2);
  CHECK(time1 == time2);

  event::Event event3{std::move(event2)};
  const auto &eventData3 =
      std::get<event::Event::Event10sData>(event3.eventData);
  const auto &infoEvent3 = eventData3.info;
  const auto &time3 = eventData3.timeCreation;
  CHECK(infoEvent3 == infoEvent2);
  CHECK(time3 == time2);

  event::Event event4 = std::move(event3);
  const auto &eventData4 =
      std::get<event::Event::Event10sData>(event4.eventData);
  const auto &infoEvent4 = eventData4.info;
  const auto &time4 = eventData4.timeCreation;
  CHECK(infoEvent4 == infoEvent3);
  CHECK(time4 == time3);
}

TEST_CASE("EventHandler test") {
  event::EventHandler eventHandler;
  using Catch::Matchers::Contains;
  REQUIRE_THAT(eventHandler.startSubsription(),
               Contains("Subscription to TimeoutEvent started at:"));
}

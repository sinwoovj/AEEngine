#pragma once

#include <string>

enum EventType
{

};
struct Event
{
	Event();
	virtual ~Event();;
	EventType m_type;
	
	std::string name;
};

class Entity
{
public:
	virtual void OnEvent(Event* ev) = 0;
};

struct LocalEvent : public Event
{
	Entity* owner;
};
#include <list>
#include <map>

class EventManager
{
	//Make a singleton
	EventManager();

	//Remove the compiler defined Copy Constructor and Asignment operator
	EventManager(const EventManager& other) = delete;

	const EventManager& operator= (const EventManager& other) = delete;
	//A container for all my events
	std::list<Event*> allEvents;
	//A container to have which entities are registered to which events
	//map of(event, container of entities*)
	std::map<std::string, std::list<Entity*>>registeredEntities;
	//Interface::
	//Add an event (evnet*) this are pointers to dynamic memory, called as the following : AddEvent(new Event)
	// 
	// templated fn:
	//	Register entities to a ceratin event TYPE--------`
	//	Unregister entities to a ceratin event TYPE
	//
	// DispatchAllEvents

	//delete undispatched events if any on destructor
};
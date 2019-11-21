#include "event_broker.h"
#include "listener.h"
#include "my_event.h"
#include <iostream>

namespace jellybean
{

struct listener::make_shared_enabler : public listener
{

template <typename... Args>
make_shared_enabler(Args &&... args) :
    listener(std::forward<Args>(args)...)
{
}

};


listener::listener()
{
}

listener::~listener()
{
    std::cout << "bye!\n";
}

std::shared_ptr<listener> listener::create()
{
    auto const object = std::make_shared<make_shared_enabler>();

    std::dynamic_pointer_cast<listener>(object)->register_handlers();

    return object;
}

void listener::register_handlers()
{
    using namespace events;

    event_broker::ref().register_callback_for_event <my_event> (
        get_shared(),
        std::bind(&listener::on_my_event, this, std::placeholders::_1)
    );
}

void listener::on_my_event(jellybean::events::base_event & e)
{
    using namespace events;

    my_event & event = dynamic_cast<my_event &>(e);

    std::cout
        << "Received event data: " << event.event_data() << "\n";
}

}

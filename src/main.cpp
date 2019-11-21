#include <iostream>
#include <string>
#include <memory>

#include "event.h"
#include "event_broker.h"
#include "my_event.h"
#include "listener.h"

void test_listen_for_events()
{
    using namespace jellybean::events;

    {
        auto const listnr =
            jellybean::listener::create();

        event_broker::ref().
            send(my_event::create(82));
    }

    event_broker::ref().
        send(my_event::create(42));
}

int main(int argc, char const *argv[])
{
    using namespace jellybean::events;

    event_broker::create_instance();

    test_listen_for_events();

    event_broker::destroy_instance();

    return 0;
}

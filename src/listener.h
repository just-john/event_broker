#ifndef JELLYBEAN_LISTENER_H
#define JELLYBEAN_LISTENER_H

#include "base_listener.h"

#include <memory>


namespace jellybean
{

class listener : public events::base_listener
{
    struct make_shared_enabler;

    listener();
    ~listener();

public:
    static std::shared_ptr<listener> create();

    void register_handlers();

    void on_my_event(jellybean::events::base_event & e);
};

}

#endif

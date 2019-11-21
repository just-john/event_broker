#ifndef JELLYBEAN_EVENTS_BASE_LISTENER_H
#define JELLYBEAN_EVENTS_BASE_LISTENER_H

#include <memory>


namespace jellybean::events
{

class base_listener : public std::enable_shared_from_this <base_listener>
{
public:
    virtual ~base_listener()
    {
    }

    virtual std::shared_ptr<base_listener> get_shared()
    {
        return shared_from_this();
    }
};

using listener_sptr = std::shared_ptr<base_listener>;
using listener_wptr = std::weak_ptr  <base_listener>;

}

#endif

#ifndef JELLYBEAN_EVENTS_EVENT_BROKER_H
#define JELLYBEAN_EVENTS_EVENT_BROKER_H

#include <functional>
#include <map>
#include <memory>
#include <queue>
#include <typeinfo>
#include <typeindex>
#include <utility>
#include <vector>

#include "singleton.h"
#include "event.h"
#include "base_listener.h"


namespace jellybean::events
{

using listener_callback_pair    = std::pair <listener_wptr, callback_fn>;
using callback_vector           = std::vector <listener_callback_pair>;


class event_broker : public singleton<event_broker>
{
    friend class singleton <event_broker>;

    std::map<std::type_index, callback_vector>       subscribers_;

    std::queue<std::unique_ptr<base_event>>          event_queue_;

    event_broker();

    ~event_broker();

public:
    template <typename EventT>
    void register_callback_for_event (
        listener_sptr const &   listener,
        callback_fn             callback)
    {
        // register a subscriber for a given event type

        auto const & itr = subscribers_.find(typeid(EventT));
        if (itr != subscribers_.end())
        {
            itr->second.emplace_back(listener, std::move(callback));
        }
        else
        {
            callback_vector v;
            v.emplace_back(listener, std::move(callback));

            subscribers_.emplace(typeid(EventT), std::move(v));
        }
    }

    void send(std::unique_ptr<base_event> e);

    void process_event_queue();

    void prune_subscribers();
};

}

#endif

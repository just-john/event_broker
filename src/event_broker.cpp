#include "event_broker.h"

namespace jellybean::events
{

event_broker::event_broker()
{
}

event_broker::~event_broker()
{
}

void event_broker::send(std::unique_ptr<base_event> e)
{
    event_queue_.emplace(std::move(e));

    process_event_queue();
    prune_subscribers();
}

void event_broker::process_event_queue()
{
    while (! event_queue_.empty())
    {
        auto e = std::move(event_queue_.front());

        auto itr = subscribers_.find(e->get_type_info());
        if (itr != subscribers_.end())
        {
            callback_vector & v = itr->second;

            std::for_each(
                v.begin(), v.end(),
                [& e](listener_callback_pair const & cb_pair)
                {
                    if (cb_pair.first.lock())
                    {
                        callback_fn const & fn = cb_pair.second;
                        fn(*e);
                    }
                }
            );
        }

        event_queue_.pop();
    }
}

void event_broker::prune_subscribers()
{
    // callback_vector is std::vector <std::pair <listener_wptr, callback_fn>>

    // prunes expired listeners from the callback_vector
    for (auto & e : subscribers_)
    {
        callback_vector & callbacks = e.second;

        if (! callbacks.empty())
        {
            callbacks.erase(

                remove_if(
                    callbacks.begin(), callbacks.end(),
                    [](std::pair <listener_wptr, callback_fn> p)
                    {
                        return p.first.expired();
                    }
                ),

                callbacks.end()
            );
        }
    }

    // if an event has no more subscribers, remove entry
    auto itr = subscribers_.begin();

    for (; itr != subscribers_.end();)
    {
        if (itr->second.empty())
        {
            subscribers_.erase(itr++);
        }
        else
        {
            ++itr;
        }

    }
}

}

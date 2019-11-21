#ifndef JELLYBEAN_EVENTS_MY_EVENT_H
#define JELLYBEAN_EVENTS_MY_EVENT_H

#include <memory>
#include <iostream>

namespace jellybean::events
{

class my_event : public events::event <my_event>
{
private:
    friend class std::unique_ptr<my_event>
        std::make_unique<my_event>(int &);

    int const    i_;

    explicit my_event(int i) :
        i_ (i)
    {
    }

public:
    static std::unique_ptr<base_event> create(int i)
    {
        return std::make_unique<my_event>(i);
    }

    ~my_event()
    {
        std::cout << "deleting my_event(" << i_ << ")\n";
    }

    int event_data() const
    {
        return i_;
    }
};

}

#endif

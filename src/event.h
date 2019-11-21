#ifndef JELLYBEAN_EVENTS_EVENT_H
#define JELLYBEAN_EVENTS_EVENT_H

#include <typeinfo>
#include <typeindex>
#include <functional>
#include <memory>


namespace jellybean::events
{

class base_event
{
public:
    virtual ~base_event()
    {
    }

    virtual size_t                  get_type_hash() const = 0;

    virtual std::string             get_type_name() const = 0;

    virtual std::type_info const &  get_type_info() const = 0;

};

using callback_fn = std::function <void(base_event &)>;


template <typename T>
class event : public base_event
{
private:
    size_t const hash_code_;

public:
    event () :
        hash_code_ (typeid(*this).hash_code())
    {
    }

    size_t get_type_hash() const
    {
        return hash_code_;
    }

    std::string get_type_name() const
    {
        return typeid(*this).name();
    }

    std::type_info const & get_type_info() const
    {
        return typeid(*this);
    }
};





}

#endif

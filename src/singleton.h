#ifndef _SingletonT_H
#define _SingletonT_H

namespace jellybean
{

template <typename T>
class singleton
{
private:
    static T * _pInstance;

public:
    virtual ~singleton(){}

    static T * create_instance()
    {
        if (! _pInstance)
            _pInstance = new T();

        return _pInstance;
    }

    static void destroy_instance()
    {
        if (_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

    inline static T &   ref();
    inline static T *   instance();
    inline static bool  incarnated();
};

template <typename T>
inline T & singleton<T>::ref()
{
    return (_pInstance) ? (*_pInstance) : (*create_instance());
}
template <typename T>
inline T * singleton<T>::instance()
{
    return (_pInstance) ? (_pInstance) : (create_instance());
}
template <typename T>
inline bool singleton<T>::incarnated()
{
    return (_pInstance != nullptr);
}

// initialize the static instance ptr to null
template <typename T>
T * singleton<T>::_pInstance = nullptr;

}

#endif

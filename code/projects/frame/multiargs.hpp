
#pragma once

template <typename... Args>
class MultiArgs;

template <>
class MultiArgs<>
{
};

template <typename Head, typename... Tail>
class MultiArgs<Head, Tail...> : private MultiArgs<Tail...>
{
public:
    using InheritedMultiArgs = MultiArgs<Tail...>;

    MultiArgs(Head _h, Tail... _t) : InheritedMultiArgs(_t...)
    {
        h = _h;
    }

    Head head()
    {
        return h;
    }

    InheritedMultiArgs& tail()
    {
        return *this;
    }

protected:
    Head h;
};

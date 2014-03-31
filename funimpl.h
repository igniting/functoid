/* Abstract letter class */

#ifndef FUNIMPL_H
#define FUNIMPL_H

template <class In, class Out> class FunImpl
{
  public:
    virtual ~FunImpl() {}
    virtual Out operator()(In arg) const = 0;
    virtual FunImpl<In, Out>* copy() const = 0;
};

#endif

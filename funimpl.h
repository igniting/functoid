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

template <class In1, class In2, class Out> class Fun2Impl
{
  public:
    virtual ~Fun2Impl() {}
    virtual Out operator()(In1 arg1, In2 arg2) const = 0;
    virtual Fun2Impl<In1, In2, Out>* copy() const = 0;
};

#endif

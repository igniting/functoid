#include "funimpl.h"
#include "fun.h"

#ifndef PARTIAL_H
#define PARTIAL_H

template <class In1, class In2, class Out> class Apply21 : public FunImpl<In2, Out>
{
  public:
    Apply21(const Fun2<In1, In2, Out> &fun, const In1 &arg1) : theFun(fun), theArg(arg1) {}
    virtual Out operator()(In2 arg2) const
    { return theFun(theArg, arg2); }
    virtual FunImpl<In2, Out>* copy() const
    { return new Apply21<In1, In2, Out>(theFun, theArg); }
  private:
    const Fun2<In1, In2, Out> theFun;
    const In1 theArg;
};

template <class In1, class In2, class Out> inline Fun<In2, Out> Fun2<In1, In2, Out>::operator()(In1 arg1) const
{
  return Fun<In2, Out>(new Apply21<In1, In2, Out>(*this, arg1));
}

#endif

#include "funimpl.h"

#ifndef GLOBAL_H
#define GLOBAL_H

/* Conversion from non-member function */

template <class In, class Out> class Global : public FunImpl<In,Out>
{
  public:
    typedef Out(* FunPtr )(In);
    Global(FunPtr f) : theFun(f) { }
    virtual Out operator()(In arg) const
    { return theFun(arg); }
    virtual FunImpl<In,Out>* copy() const
    { return new Global<In,Out>(theFun); }
  private:
    FunPtr theFun;
};

#endif

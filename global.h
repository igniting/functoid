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

template <class In1, class In2, class Out> class Global2 : public Fun2Impl<In1, In2, Out>
{
  public:
    typedef Out(* Fun2Ptr)(In1, In2);
    Global2(Fun2Ptr f) : theFun2(f) { }
    virtual Out operator()(In1 arg1, In2 arg2) const
    { return theFun2(arg1, arg2); }
    virtual Fun2Impl<In1, In2, Out>* copy() const
    { return new Global2<In1, In2, Out>(theFun2); }
  private:
    Fun2Ptr theFun2;
};

#endif

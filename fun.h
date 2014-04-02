#include "funimpl.h"
#include "global.h"

#ifndef FUN_H
#define FUN_H

template <class In, class Out> class Fun
{
  public:
    Fun(FunImpl<In, Out>* const f): impl(f) {}
    Fun(const Fun& fun): impl(fun.impl->copy()) {}
    Fun(Out(*f)(In)): impl(new Global<In,Out>(f)) {}
    ~Fun() {delete impl;}
    Out operator()(In arg) const
    { return (*impl)(arg); }
  private:
    FunImpl<In, Out>* const impl;
};

template <class In1, class In2, class Out> class Fun2
{
  public:
    typedef Out(*Fun2Ptr)(In1, In2);
    Fun2(Fun2Impl<In1, In2, Out>* const f): impl(f) {}
    Fun2(Fun2Ptr f): impl(new Global2<In1, In2, Out>(f)) {}
    Fun2(const Fun2<In1, In2, Out>& fun): impl(fun.impl->copy()) {}
    ~Fun2() {delete impl;}
    Out operator()(In1 arg1, In2 arg2) const
    { return (*impl)(arg1, arg2); }
    inline Fun<In2, Out> operator()(In1 arg1) const;
  private:
    Fun2Impl<In1, In2, Out>* const impl;
};

#endif

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

#endif

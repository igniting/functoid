#include "funimpl.h"
#include "fun.h"

#ifndef COMPOSE_H
#define COMPOSE_H

template <class In, class Med, class Out>
class Compose:public FunImpl<In, Out>
{
  public:
    Compose(const Fun<Med, Out>& f,
        const Fun<In, Med>& g): ffun(f), gfun(g) {}
    virtual Out operator()(In arg) const
    { return ffun(gfun(arg)); }
    virtual FunImpl<In, Out>* copy() const
    {
      return new Compose<In, Med, Out>(ffun, gfun);
    }
  private:
    const Fun<Med, Out> ffun;
    const Fun<In, Med> gfun;
};

template <class In, class Med, class Out>
Fun<In,Out> compose(const Fun<Med,Out>& f, const Fun<In,Med>& g)
{
  return Fun<In,Out>(new Compose<In,Med,Out>(f, g));
}

#endif

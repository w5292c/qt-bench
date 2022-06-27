#ifndef QT_BENCH_PLUGIN_INTERFACE_H
#define QT_BENCH_PLUGIN_INTERFACE_H

#ifdef __cplusplus

extern "C" typedef void *(*FactoryFunction)(void);

class MExampleFactory {
public:
  virtual ~MExampleFactory();

  virtual const char *getStringId(int id) const = 0;
};

static inline MExampleFactory *createFactory(FactoryFunction factory)
{
  return reinterpret_cast<MExampleFactory *>(factory());
}

#endif /* __cplusplus */

#endif /* QT_BENCH_PLUGIN_INTERFACE_H */

#include "plugin.h"
#include "plugin-strings.h"
#include "plugin-interface.h"

#include <string.h>
#include <stdlib.h>


class CExampleFactory : public  MExampleFactory {
public:
  const char *getStringId(int id) const override;
};


void *createFactory(void)
{
  return new CExampleFactory();
}

MExampleFactory::~MExampleFactory()
{
}

const char *CExampleFactory::getStringId(int id) const
{
  return examplePluginGetStringId(id);
}

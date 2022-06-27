#include "plugin-strings.h"

#include <stdio.h>

static const char *TheStrings[] = {
  //% "Test string in a plugin"
  QT_TRID_NOOP("id-plugin-string-id-1"),
  //% "And this is another string in a plugin"
  QT_TRID_NOOP("id-plugin-string-id-2"),
  //% "One more test string"
  QT_TRID_NOOP("id-plugin-string-id-3"),
  //% "And here is the last example string"
  QT_TRID_NOOP("id-plugin-string-id-4"),
};

//% "Undefined"
static const char *TheUndefinedString = QT_TRID_NOOP("id-plugin-string-undefined");

const char *examplePluginGetStringId(int id)
{
  const size_t n = sizeof (TheStrings)/sizeof (*TheStrings);
  if (id < n) {
    return TheStrings[id];
  } else {
    return TheUndefinedString;
  }
}

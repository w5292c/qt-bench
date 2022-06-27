add_library(example-plugin MODULE
  plugin.cpp
  plugin-strings.cpp
)

SET_TARGET_PROPERTIES(example-plugin
  PROPERTIES PREFIX ""
)

target_include_directories(example-plugin PRIVATE ../shared)

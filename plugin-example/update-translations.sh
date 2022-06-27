#!/bin/bash

#lupdate -recursive plugin/ -ts languages/example-plugin_en.ts languages/example-plugin_de.ts languages/example-plugin_ru.ts
lrelease -idbased languages/example-plugin_*.ts

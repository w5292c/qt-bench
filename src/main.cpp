/*
 * MIT License
 *
 * Copyright (c) 2022 Alexander Chumakov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <QDebug>
#include <QTranslator>
#include <QCoreApplication>

int main(int argc, char **argv)
{
  QCoreApplication app(argc, argv);

  QString locale("en");
  // If a single argument is passed, use it as a locale name
  if (argc == 2) {
    locale = argv[1];
  } else {
    // Get the system locale
    QString systemLocale = QLocale::system().name();
    systemLocale.truncate(systemLocale.lastIndexOf('_'));
    locale = systemLocale;
  }
  qDebug() << "Locale: " << locale;

  // Determine the localization file name
  QString path = QCoreApplication::applicationDirPath();
  path.append(QString("/../languages/TranslationExample_%1.qm").arg(locale));
  qDebug() << "Loading locale file: " << path;
  QTranslator translator;
  int res = translator.load(path);
  qDebug() << "Loaded the localization file, result: " << res;
  if (res) {
    app.installTranslator(&translator);
  }

  // Localization examples

  // 1. Simple example

  //: This is a localization example without parameters
  //% "Simple localization example without parameters"
  //~ Context Main function
  const QString &example1 = qtTrId("example-id-without-params");
  qDebug() << "Example 1, localized string: " << example1;

  // 2. Example with 1 argument

  //: Reports the number of files to the console
  //% "Number of files: %n"
  //~ Context main
  const QString &example21 = qtTrId("example-id-number-of-files", 0);
  const QString &example22 = qtTrId("example-id-number-of-files", 1);
  const QString &example23 = qtTrId("example-id-number-of-files", 42);
  qDebug() << "Example 2: localized string, with argument  '0': " << example21;
  qDebug() << "Example 2: localized string, with argument  '1': " << example22;
  qDebug() << "Example 2: localized string, with argument '42': " << example23;

  return 0;
}

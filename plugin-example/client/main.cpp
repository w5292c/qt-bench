#include "plugin-interface.h"

#include <QDebug>
#include <QLibrary>
#include <QTranslator>
#include <QCoreApplication>

int main(int argc, char **argv)
{
  QCoreApplication app(argc, argv);

  qDebug() << "Starting the application...";

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
  const char *const localizationFiles[] = {
    "/../../../plugin-example/languages/example-plugin_%1.qm",
    nullptr
  };

  bool res, res1;
  const QString &basePath = QCoreApplication::applicationDirPath();
  const char *const *ptr = localizationFiles;
  for (; *ptr; ++ptr) {
    QString path = basePath + QString(*ptr).arg(locale);
    QTranslator *translator = new QTranslator(&app);
    res = translator->load(path);
    Q_ASSERT(res);
    res1 = app.installTranslator(translator);
    Q_ASSERT(res1);
    qDebug() << "Loaded the localization file" << path << ", result: " << res << ", " << res1;
  }

  QLibrary plugin("plugin-example/plugin/example-plugin.so");
  res = plugin.load();
  Q_ASSERT(res);

  FactoryFunction factoryFunction = reinterpret_cast<FactoryFunction>(plugin.resolve("createFactory"));
  Q_ASSERT(factoryFunction);
  MExampleFactory *const factory = createFactory(factoryFunction);
  Q_ASSERT(factory);

  for (int id = -1; id < 5; ++id) {
    const char *const strId = factory->getStringId(id);
    const QString &translated = qtTrId(strId);
    qDebug() << "NumericStringID:" << id << ", string: ID" << strId << ", translated string: " << translated;
  }

  delete factory;
  qDebug() << "Finished the application.";
  return 0;
}

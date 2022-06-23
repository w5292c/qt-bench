# QT bench
A simple project for trying small things in QT.

# Playing with localization
First thing to try is localization support in QT.
Possible steps to build and try:
* git clone https://github.com/w5292c/qt-bench.git
* cd qt-bench
* ./update-translations.sh
* mkdir build && cd build
* qmake ..
* make
* # app is ready, try in Engish/German/Russian locales
* ./qt-bench en
* ./qt-bench de
* ./qt-bench ru

# Build dependencies (Debian 11):
* qtchooser
* qtbase5-dev
* qt5-qmake-bin
* qttools5-dev-tools

# Usefull links
* [Internationalization with Qt](https://doc.qt.io/qt-6/internationalization.html)
* [Translation Rules for Plurals](https://doc.qt.io/qt-6/i18n-plural-rules.html)
* [Qt Linguist Manual: TS File Format](https://doc.qt.io/qt-6/linguist-ts-file-format.html)
* [Qt Linguist Manual: Text ID Based Translations](https://doc.qt.io/qt-6/linguist-id-based-i18n.html)

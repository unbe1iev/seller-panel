<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
    </li>
    <li><a href="#usage">Usage</a></li>
  </ol>
</details>

## About The Project
[![Product Name Screen Shot][product-screenshot]](https://example.com)

https://imgur.com/a/Ak9Rnvv
This is a simple simple seller's order panel that can:
* Display his orders
* Add new randomized order to his panel
* Delete an order

### Built With
The project is based on the Qt/C ++ IDE with the help of UI[xml]+Console management in the order panel menu.
I used Desktop Qt 6.4.0 MinGW 64-bit build kit for setting up the project.


<!-- GETTING STARTED -->
## Getting Started
If you want to put a project in Qt you have to use specific settings of an automatically generated project file with the extension .pro. 

Here are my settings:
* Qt .pro file:
  ```
  QT       += core gui
  greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

  CONFIG += c++11

  # You can make your code fail to compile if it uses deprecated APIs.
  # In order to do so, uncomment the following line.
  #DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

  SOURCES += \
      customer.cpp \
      main.cpp \
      menu.cpp \
      order.cpp \
      product.cpp \
      seller.cpp

  HEADERS += \
      customer.h \
      delivery.h \
      menu.h \
      order.h \
      product.h \
      seller.h

  FORMS += \
      menu.ui

  # Default rules for deployment.
  qnx: target.path = /tmp/$${TARGET}/bin
  else: unix:!android: target.path = /opt/$${TARGET}/bin
  !isEmpty(target.path): INSTALLS += target
  ```

<p align="left"><<a href="#top">back to top</a>></p>

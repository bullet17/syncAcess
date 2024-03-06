QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    armazenamento.cpp \
    main.cpp \
    telacadastrocliente.cpp \
    telacadastrolivro.cpp \
    telacadastrouser.cpp \
    teladevolucao.cpp \
    telaemprestimo.cpp \
    telalistaclientes.cpp \
    telalistafuncionarios.cpp \
    telalistalivros.cpp \
    telalogin.cpp \
    telamainmenu.cpp \
    validacoes.cpp \
    variaveis.cpp

HEADERS += \
    armazenamento.h \
    telacadastrocliente.h \
    telacadastrolivro.h \
    telacadastrouser.h \
    teladevolucao.h \
    telaemprestimo.h \
    telalistaclientes.h \
    telalistafuncionarios.h \
    telalistalivros.h \
    telalogin.h \
    telamainmenu.h \
    validacoes.h \
    variaveis.h

FORMS += \
    telacadastrocliente.ui \
    telacadastrolivro.ui \
    telacadastrouser.ui \
    teladevolucao.ui \
    telaemprestimo.ui \
    telalistaclientes.ui \
    telalistafuncionarios.ui \
    telalistalivros.ui \
    telalogin.ui \
    telamainmenu.ui

TRANSLATIONS += \
    biblioteca_v01_pt_BR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    arquivos.qrc

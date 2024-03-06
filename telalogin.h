#ifndef TELALOGIN_H
#define TELALOGIN_H

#include <QMainWindow>
#include <QMessageBox>
#include <string>
#include <iostream>
#include <string>
#include <iostream>
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>
#include <QFile>
#include "telamainmenu.h"
#include "variaveis.h"


QT_BEGIN_NAMESPACE
namespace Ui { class telaLogin; }
QT_END_NAMESPACE

class telaLogin : public QMainWindow {
    Q_OBJECT

    public:
        telaLogin(QWidget *parent = nullptr);
        ~telaLogin();

    private slots:
        void on_entrar_clicked();

        void on_login_txt_editingFinished();

        void on_senha_txt_editingFinished();

    private:
        Ui::telaLogin *ui;
};

extern telaMainMenu *form;

int pegaUsuarios();

#endif // TELALOGIN_H

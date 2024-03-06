#ifndef TELACADASTROUSER_H
#define TELACADASTROUSER_H

#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>
#include <QWidget>
#include <QRegularExpression>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include "variaveis.h"
#include "validacoes.h"

namespace Ui {
class telaCadastroUser;
}

class telaCadastroUser : public QDialog
{
    Q_OBJECT

public:
    explicit telaCadastroUser(QWidget *parent = nullptr);
    ~telaCadastroUser();

private slots:
    void on_cadastrarFuncionario_btn_clicked();

    void on_pushButton_clicked();

    void on_nomeFuncionario_txt_editingFinished();

    void on_telefoneFuncionario_txt_editingFinished();

    void on_emailFuncionario_txt_editingFinished();

    void on_senhaFuncionario_txt_editingFinished();

    void on_senhaFuncionarioConfirma_txt_editingFinished();

private:
    Ui::telaCadastroUser *ui;
};


#endif // TELACADASTROUSER_H

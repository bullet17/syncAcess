#ifndef TELAEMPRESTIMO_H
#define TELAEMPRESTIMO_H

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

namespace Ui {
class telaEmprestimo;
}

class telaEmprestimo : public QDialog
{
    Q_OBJECT

public:
    explicit telaEmprestimo(QWidget *parent = nullptr);
    ~telaEmprestimo();

private slots:
    void on_pushButton_clicked();

    void on_regsEmprestimo_bt_clicked();

    void on_clientes_cbox_editTextChanged(const QString &arg1);

    void on_emprestimo_date_editingFinished();

private:
    Ui::telaEmprestimo *ui;
};

#endif // TELAEMPRESTIMO_H

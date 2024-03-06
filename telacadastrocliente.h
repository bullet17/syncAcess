#ifndef TELACADASTROCLIENTE_H
#define TELACADASTROCLIENTE_H

#include <QDialog>
#include <stdio.h>
#include <string>
#include <iostream>
#include <QRegularExpression>
#include <QPixmap>
#include "variaveis.h"
#include "validacoes.h"

namespace Ui {
class telaCadastroCliente;
}

class telaCadastroCliente : public QDialog
{
    Q_OBJECT

public:
    explicit telaCadastroCliente(QWidget *parent = nullptr);
    ~telaCadastroCliente();

private slots:
    void on_pushButton_clicked();

    void on_nomeCliente_txt_editingFinished();

    void on_idadeCliente_txt_editingFinished();

    void on_telefoneCliente_txt_editingFinished();

    void on_emailCliente_txt_editingFinished();

    void on_enderecoCliente_txt_editingFinished();

    void on_documentoCliente_txt_editingFinished();

    void on_cadastrarCliente_btn_clicked();

private:
    Ui::telaCadastroCliente *ui;
};

#endif // TELACADASTROCLIENTE_H

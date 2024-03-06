#ifndef TELALISTACLIENTES_H
#define TELALISTACLIENTES_H

#include <QDialog>
#include "variaveis.h"
#include "telacadastrocliente.h"

namespace Ui {
class telaListaClientes;
}

class telaListaClientes : public QDialog
{
    Q_OBJECT

public:
    explicit telaListaClientes(QWidget *parent = nullptr);
    ~telaListaClientes();
    telaCadastroCliente *form2;

private slots:
    void on_voltar_btn_clicked();

    void on_cadNovo_btn_clicked();

private:
    Ui::telaListaClientes *ui;
};

#endif // TELALISTACLIENTES_H

#ifndef TELALISTAFUNCIONARIOS_H
#define TELALISTAFUNCIONARIOS_H

#include <QDialog>
#include "variaveis.h"
#include "telacadastrouser.h"

namespace Ui {
class telaListaFuncionarios;
}

class telaListaFuncionarios : public QDialog
{
    Q_OBJECT

public:
    explicit telaListaFuncionarios(QWidget *parent = nullptr);
    ~telaListaFuncionarios();
    telaCadastroUser *form2;

private slots:
    void on_voltar_btn_clicked();

    void on_cadNovo_btn_clicked();

private:
    Ui::telaListaFuncionarios *ui;
};

#endif // TELALISTAFUNCIONARIOS_H

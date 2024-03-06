#ifndef TELALISTALIVROS_H
#define TELALISTALIVROS_H

#include <QDialog>
#include <QSqlQueryModel>
#include "telacadastrolivro.h"

namespace Ui {
class telaListaLivros;
}

class telaListaLivros : public QDialog
{
    Q_OBJECT

public:
    explicit telaListaLivros(QWidget *parent = nullptr);
    ~telaListaLivros();
    telaCadastroLivro *form4;

private slots:
    void on_voltar_btn_clicked();

    void on_cadNovo_btn_clicked();

private:
    Ui::telaListaLivros *ui;
};

#endif // TELALISTALIVROS_H

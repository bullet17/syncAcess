#ifndef TELAMAINMENU_H
#define TELAMAINMENU_H

#include <QDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>
#include <QMouseEvent>
#include <QEvent>
#include "telacadastrouser.h"
#include "telalistalivros.h"
#include "telaemprestimo.h"
#include "teladevolucao.h"
#include "telalistaclientes.h"
#include "telalistafuncionarios.h"


namespace Ui {
class telaMainMenu;
}

class telaMainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit telaMainMenu(QWidget *parent = nullptr);
    ~telaMainMenu();
    telaCadastroUser *form2;
    telaListaLivros *form5;
    telaEmprestimo *form6;
    telaDevolucao *form7;
    telaListaClientes *form8;
    telaListaFuncionarios *form9;


private slots:

    void on_livros_bt_clicked();
    void on_emprestimo_bt_clicked();
    void on_devolucao_bt_clicked();
    void on_clientes_bt_clicked();
    void on_funcionarios_bt_clicked();

private:
    Ui::telaMainMenu *ui;
};


#endif // TELAMAINMENU_H

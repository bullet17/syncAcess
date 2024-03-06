#include "telamainmenu.h"
#include "ui_telamainmenu.h"
#include "armazenamento.h"
#include "validacoes.h"

telaMainMenu::telaMainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telaMainMenu) {
    ui->setupUi(this);
    QString nomeUsuario = consultaNomeUsuario(idUserAtual);
    QString idUserStg = QString::number(idUserAtual);
    ui->nomeUsuario_lb->setText(nomeUsuario);
    ui->idUsuario_lb->setText(idUserStg);
}

void telaMainMenu::on_livros_bt_clicked() {
    form5 = new telaListaLivros();
    this->close();
    form5->show();
}

void telaMainMenu::on_emprestimo_bt_clicked() {
    form6 = new telaEmprestimo();
    this->close();
    form6->show();
}

void telaMainMenu::on_devolucao_bt_clicked() {
    form7 = new telaDevolucao();
    this->close();
    form7->show();
}

void telaMainMenu::on_clientes_bt_clicked() {
    form8 = new telaListaClientes();
    this->close();
    form8->show();
}

void telaMainMenu::on_funcionarios_bt_clicked(){
    form9 = new telaListaFuncionarios();
    this->close();
    form9->show();
}

telaMainMenu::~telaMainMenu() {
    delete ui;
}


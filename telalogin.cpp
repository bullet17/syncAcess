#include "telalogin.h"
#include "./ui_telalogin.h"
#include "armazenamento.h"
#include <QVBoxLayout>

using namespace std;

telaMainMenu *form;

telaLogin::telaLogin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::telaLogin)
{
    //help in the future
    criaListaLivros();
    criaListaClientes();
    ui->setupUi(this);

    ui->login_txt->setFocus();
}

void telaLogin::on_entrar_clicked() {
    QString idDigitado = ui->login_txt->text();
    QString senhaDigitada = ui->senha_txt->text();

    QString senhaUsuario = consultaSenhaUsuario(idDigitado);

    if (senhaDigitada != senhaUsuario) {
        QMessageBox::critical(this,"","USUÁRIO ou SENHA incorretos!");
        ui->senha_txt->clear();
        ui->senha_txt->setFocus();
    } else if (idDigitado == "") {
        QMessageBox::critical(this,"","USUÁRIO ou SENHA incorretos!");
        ui->login_txt->clear();
        ui->login_txt->setFocus();
    } else {
        idUserAtual = idDigitado.toInt();
        form = new telaMainMenu(this);
        this->close();
        form->show();
    }
}

void telaLogin::on_login_txt_editingFinished() {
    ui->senha_txt->setFocus();
}

void telaLogin::on_senha_txt_editingFinished() {
    ui->entrar->setFocus();
    ui->entrar->click();
}

telaLogin::~telaLogin() {
    delete ui;
}


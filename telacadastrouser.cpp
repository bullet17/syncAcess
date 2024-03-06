#include "telacadastrouser.h"
#include "./ui_telacadastrouser.h"
#include "telalogin.h"
#include "armazenamento.h"

telaListaFuncionarios *form7;
bool cadastroOK = false;

telaCadastroUser::telaCadastroUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telaCadastroUser)
{
    ui->setupUi(this);
    ui->telefoneFuncionario_txt->setInputMask("(00)00000-0000");
    ui->nomeFuncionario_txt->setFocus();
}

void telaCadastroUser::on_nomeFuncionario_txt_editingFinished() {
    QString nomeDigitado = ui->nomeFuncionario_txt->text();
    cadastroOK = true;

    if (nomeDigitado != "") {
        ui->telefoneFuncionario_txt->setFocus();
    } else {
        ui->nomeFuncionario_txt->setFocus();
        QMessageBox::warning(this,"NOME","Campo NOME obrigatório!");
        cadastroOK = false;
    }
}

void telaCadastroUser::on_telefoneFuncionario_txt_editingFinished() {
    QString telefoneDigitado = ui->telefoneFuncionario_txt->text();
    cadastroOK = true;

    if (telefoneDigitado != "") {
        ui->emailFuncionario_txt->setFocus();
    } else {
        ui->telefoneFuncionario_txt->setFocus();
        QMessageBox::warning(this,"TELEFONE","Campo TELEFONE obrigatório!");
        cadastroOK = false;
    }
}

void telaCadastroUser::on_emailFuncionario_txt_editingFinished() {
    QString emailDigitado = ui->emailFuncionario_txt->text();
    cadastroOK = true;
    bool emailValido = validaEmail(emailDigitado);

    if (emailValido != false){
        ui->senhaFuncionario_txt->setFocus();
    } else {
        ui->emailFuncionario_txt->setFocus();
        QMessageBox::warning(this,"EMAIL","Digite um EMAIL válido!");
        cadastroOK = false;
    }
}

void telaCadastroUser::on_senhaFuncionario_txt_editingFinished() {
    QString senhaDigitado = ui->senhaFuncionario_txt->text();
    cadastroOK = true;

    if (senhaDigitado != "") {
            ui->senhaFuncionarioConfirma_txt->setFocus();
    } else {
        ui->senhaFuncionario_txt->setFocus();
        QMessageBox::warning(this,"SENHA","Campo SENHA obrigatório!");
        cadastroOK = false;
    }
}

void telaCadastroUser::on_senhaFuncionarioConfirma_txt_editingFinished() {
    QString senhaDigitado = ui->senhaFuncionario_txt->text();
    QString senhaConfirmaDigitado = ui->senhaFuncionarioConfirma_txt->text();
    cadastroOK = true;

    if (senhaDigitado == senhaConfirmaDigitado) {
        ui->cadastrarFuncionario_btn->setFocus();
    } else {
        ui->senhaFuncionario_txt->setFocus();
        ui->senhaFuncionarioConfirma_txt->clear();
        QMessageBox::warning(this,"SENHA","As senhas não conferem!");
        cadastroOK = false;
    }
}

void telaCadastroUser::on_cadastrarFuncionario_btn_clicked()
{
    classUsuario usuarioCadastrado;
    QString nomeDigitado = ui->nomeFuncionario_txt->text();
    QString telefoneDigitado = ui->telefoneFuncionario_txt->text();
    QString emailDigitado = ui->emailFuncionario_txt->text();
    QString senhaDigitado = ui->senhaFuncionario_txt->text();
    QString senhaConfirmaDigitado = ui->senhaFuncionarioConfirma_txt->text();

    if (nomeDigitado == "" || telefoneDigitado == "" || emailDigitado == "" || senhaDigitado == "" || senhaConfirmaDigitado != senhaDigitado) {
        cadastroOK = false;
    }

    if (cadastroOK != true) {
        QMessageBox::warning(this,"CADASTRO", "NECESSÁRIO PREENCHER TODOS OS CAMPOS OBRIGATÓRIOS COM DADOS VÁLIDOS!");
    } else {
        usuarioCadastrado.nome = ui->nomeFuncionario_txt->text();
        usuarioCadastrado.telefone = ui->telefoneFuncionario_txt->text();
        usuarioCadastrado.email = ui->emailFuncionario_txt->text();
        usuarioCadastrado.senha = ui->senhaFuncionario_txt->text();
        usuarioCadastrado.id = criaIdUsuario();
        QString id_stg = QString::number(usuarioCadastrado.id);
        bool cadastrado = armazenaUsuario(usuarioCadastrado);
        if (cadastrado != true) {
            QMessageBox::about(this,"CADASTRO", "Houveram problemas no cadastro do funcionário :/\n Tente novamente por favor!)");
        } else {
            QMessageBox::about(this,"CADASTRO", "\nUsuário cadastrado com sucesso! :) \n O ID DO USUÁRIO É "+id_stg);
            form7 = new telaListaFuncionarios(this);
            this->close();
            form7->show();
        }
    }
}

void telaCadastroUser::on_pushButton_clicked() {
    form7 = new telaListaFuncionarios(this);
    this->close();
    form7->show();
}

telaCadastroUser::~telaCadastroUser()
{
    delete ui;
}












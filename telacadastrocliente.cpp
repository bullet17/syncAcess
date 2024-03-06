#include "telacadastrocliente.h"
#include "./ui_telacadastrocliente.h"
#include "armazenamento.h"

using namespace std;
telaListaClientes *form8;
bool okCadastro = false;

telaCadastroCliente::telaCadastroCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telaCadastroCliente)
{
    ui->setupUi(this);
    ui->telefoneCliente_txt->setInputMask("(00)00000-0000");
    ui->documentoCliente_txt->setInputMask("000.000.000-00");
}

void telaCadastroCliente::on_nomeCliente_txt_editingFinished() {
    QString nomeDigitado = ui->nomeCliente_txt->text();
    okCadastro = true;

    if (nomeDigitado != "") {
        ui->idadeCliente_txt->setFocus();
    } else {
        ui->nomeCliente_txt->setFocus();
        QMessageBox::warning(this,"NOME","Campo NOME obrigatório!");
        okCadastro = false;
    }
}

void telaCadastroCliente::on_idadeCliente_txt_editingFinished() {
    QString idadeDigitado = ui->idadeCliente_txt->text();
    okCadastro = true;

    if (idadeDigitado != "") {
        ui->telefoneCliente_txt->setFocus();
    } else {
        ui->idadeCliente_txt->setFocus();
        QMessageBox::warning(this,"IDADE","Campo IDADE obrigatório!");
        okCadastro = false;
    }
}

void telaCadastroCliente::on_telefoneCliente_txt_editingFinished() {
    QString telefoneDigitado = ui->telefoneCliente_txt->text();
    okCadastro = true;

    if (telefoneDigitado != "") {
        ui->emailCliente_txt->setFocus();
    } else {
        ui->telefoneCliente_txt->setFocus();
        QMessageBox::warning(this,"TELEFONE","Campo TELEFONE obrigatório!");
        okCadastro = false;
    }
}

void telaCadastroCliente::on_emailCliente_txt_editingFinished() {
    QString emailDigitado = ui->emailCliente_txt->text();
    okCadastro = true;

    bool emailValido = validaEmail(emailDigitado);

    if (emailValido != false){
        ui->enderecoCliente_txt->setFocus();
    } else {
        ui->emailCliente_txt->setFocus();
        QMessageBox::warning(this,"EMAIL","Digite um EMAIL válido!");
        okCadastro = false;
    }
}

void telaCadastroCliente::on_enderecoCliente_txt_editingFinished() {
    QString enderecoDigitado = ui->enderecoCliente_txt->text();
    okCadastro = true;

    if (enderecoDigitado != "") {
        ui->documentoCliente_txt->setFocus();
    } else {
        ui->enderecoCliente_txt->setFocus();
        QMessageBox::warning(this,"ENDEREÇO","Campo ENDEREÇO obrigatório!");
        okCadastro = false;
    }
}

void telaCadastroCliente::on_documentoCliente_txt_editingFinished() {
    QString documentoDigitado = ui->documentoCliente_txt->text();
    okCadastro = true;

    if (documentoDigitado != "") {
        ui->cadastrarCliente_btn->setFocus();
    } else {
        ui->documentoCliente_txt->setFocus();
        QMessageBox::warning(this,"DOCUMENTO","Campo DOCUMENTO obrigatório!");
        okCadastro = false;
    }
}

void telaCadastroCliente::on_cadastrarCliente_btn_clicked() {
    classCliente clienteCadastrado;
    QString nomeDigitado = ui->nomeCliente_txt->text();
    QString idadeDigitado = ui->idadeCliente_txt->text();
    QString telefoneDigitado = ui->telefoneCliente_txt->text();
    QString emailDigitado = ui->emailCliente_txt->text();
    QString enderecoDigitado = ui->enderecoCliente_txt->text();
    QString documentoDigitado = ui->documentoCliente_txt->text();

    if (nomeDigitado == "" || idadeDigitado == "" || telefoneDigitado == "" || emailDigitado == "" ||enderecoDigitado == "" || documentoDigitado == "") {
        okCadastro = false;
    }

    if (okCadastro != true) {
        QMessageBox::warning(this,"CADASTRO", "NECESSÁRIO PREENCHER TODOS OS CAMPOS OBRIGATÓRIOS COM DADOS VÁLIDOS!");
    } else {
        clienteCadastrado.nome = ui->nomeCliente_txt->text();
        clienteCadastrado.idade = ui->idadeCliente_txt->text();
        clienteCadastrado.telefone = ui->telefoneCliente_txt->text();
        clienteCadastrado.email = ui->emailCliente_txt->text();
        clienteCadastrado.endereco = ui->enderecoCliente_txt->text();
        clienteCadastrado.documento= ui->documentoCliente_txt->text();
        clienteCadastrado.id = criaIdCliente();
        QString idStg = QString::number(clienteCadastrado.id);
        bool cadastrado = armazenaCliente(clienteCadastrado);
        if (cadastrado != true) {
            QMessageBox::about(this,"CADASTRO", "Houveram problemas no cadastro do cliente :/\n Tente novamente por favor!)");
        } else {
            QMessageBox::about(this,"CADASTRO", "Cliente cadastrado com sucesso! :) \n N° REGISTRO CLIENTE: "+idStg);
            form8 = new telaListaClientes(this);
            this->close();
            form8->show();
        }
    }
}

void telaCadastroCliente::on_pushButton_clicked() {
    form8 = new telaListaClientes(this);
    this->close();
    form8->show();
}

telaCadastroCliente::~telaCadastroCliente() {
    delete ui;
}

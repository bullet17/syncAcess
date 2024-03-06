#include "telacadastrolivro.h"
#include "./ui_telacadastrolivro.h"
#include "telalogin.h"
#include "armazenamento.h"

telaListaLivros *form2;
bool cadastroOk = false;

telaCadastroLivro::telaCadastroLivro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telaCadastroLivro) {
    ui->setupUi(this);
}

void telaCadastroLivro::on_codLivro_txt_editingFinished() {
    QString codDigitado = ui->codLivro_txt->text();
    cadastroOk = true;

    if (codDigitado != "") {
        ui->tituloLivro_txt->setFocus();
    } else {
        ui->codLivro_txt->setFocus();
        QMessageBox::warning(this,"CÓDIGO","Campo CÓDIGO obrigatório!");
            cadastroOk = false;
    }
}

void telaCadastroLivro::on_tituloLivro_txt_editingFinished() {
    QString tituloDigitado = ui->tituloLivro_txt->text();
    cadastroOk = true;

    if (tituloDigitado != "") {
            ui->autorLivro_txt->setFocus();
    } else {
        ui->tituloLivro_txt->setFocus();
        QMessageBox::warning(this,"TÍTULO","Campo TÍTULO obrigatório!");
        cadastroOk = false;
    }
}

void telaCadastroLivro::on_autorLivro_txt_editingFinished() {
    QString autorDigitado = ui->autorLivro_txt->text();
    cadastroOk = true;

    if (autorDigitado != "") {
        ui->anoLivro_txt->setFocus();
    } else {
        ui->autorLivro_txt->setFocus();
        QMessageBox::warning(this,"AUTOR","Campo AUTOR obrigatório!");
        cadastroOk = false;
    }
}

void telaCadastroLivro::on_anoLivro_txt_editingFinished() {
    QString anoDigitado = ui->anoLivro_txt->text();
    cadastroOk = true;

    if (anoDigitado != "") {
        ui->editoraLivro_txt->setFocus();
    } else {
        ui->anoLivro_txt->setFocus();
        QMessageBox::warning(this,"ANO","Campo ANO obrigatório!");
        cadastroOk = false;
    }
}

void telaCadastroLivro::on_editoraLivro_txt_editingFinished() {
    QString editoraDigitado = ui->editoraLivro_txt->text();
    cadastroOk = true;

    if (editoraDigitado != "") {
            ui->quantLivro_txt->setFocus();
    } else {
            ui->editoraLivro_txt->setFocus();
            QMessageBox::warning(this,"EDITORA","Campo EDITORA obrigatório!");
            cadastroOk = false;
    }
}

void telaCadastroLivro::on_quantLivro_txt_editingFinished() {
    QString quantDigitado = ui->quantLivro_txt->text();
    cadastroOk = true;

    if (quantDigitado != "") {
            ui->cadastrarLivro_btn->setFocus();
    } else {
        ui->quantLivro_txt->setFocus();
        QMessageBox::warning(this,"QUANTIDADE","Campo QUANTIDADE obrigatório!");
        cadastroOk = false;
    }
}

void telaCadastroLivro::on_cadastrarLivro_btn_clicked() {
    classLivro livroCadastrado;
    QString codDigitado = ui->codLivro_txt->text();
    QString tituloDigitado = ui->tituloLivro_txt->text();
    QString autorDigitado = ui->autorLivro_txt->text();
    QString anoDigitado = ui->anoLivro_txt->text();
    QString editoraDigitada = ui->editoraLivro_txt->text();
    QString quantDigitada = ui->quantLivro_txt->text();

    if(codDigitado == "" || tituloDigitado == "" || autorDigitado == "" || anoDigitado == "" || editoraDigitada == "" || quantDigitada == "") {
        cadastroOk = false;
    }

    if (cadastroOk != true) {
        QMessageBox::warning(this,"CADASTRO", "NECESSÁRIO PREENCHER TODOS OS CAMPOS OBRIGATÓRIOS COM DADOS VÁLIDOS!");
    } else {
        livroCadastrado.id = ui->codLivro_txt->text();
        livroCadastrado.titulo = ui->tituloLivro_txt->text();
        livroCadastrado.autor = ui->autorLivro_txt->text();
        livroCadastrado.ano = ui->anoLivro_txt->text();
        livroCadastrado.editora = ui->editoraLivro_txt->text();
        livroCadastrado.quantTotal = ui->quantLivro_txt->text().toInt();
        livroCadastrado.quantDisp = ui->quantLivro_txt->text().toInt();
        bool cadastrado = armazenaLivro(livroCadastrado);
        if (cadastrado != true) {
            QMessageBox::about(this,"LIVRO", "Houveram problemas no cadastro do Livro :/\n Tente novamente por favor!)");
        } else {
            QMessageBox::about(this,"LIVRO", "Livro cadastrado com sucesso! :)");
            form2 = new telaListaLivros(this);
            this->close();
            form2->show();
        }
    }
}

void telaCadastroLivro::on_pushButton_clicked() {
    form2 = new telaListaLivros(this);
    this->close();
    form2->show();
}

telaCadastroLivro::~telaCadastroLivro() {
    delete ui;
}




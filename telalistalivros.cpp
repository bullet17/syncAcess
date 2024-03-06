#include "telalistalivros.h"
#include "./ui_telalistalivros.h"
#include "variaveis.h"
#include "armazenamento.h"
#include "telalogin.h"

telaListaLivros::telaListaLivros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telaListaLivros)
{
    ui->setupUi(this);

    QString caminhoDoBanco = "C:/banco/biblioteca.db";

    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("books_tbl");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("TITULO"));
    model->setHeaderData(2, Qt::Horizontal, tr("AUTOR"));
    model->setHeaderData(3, Qt::Horizontal, tr("ANO"));
    model->setHeaderData(4, Qt::Horizontal, tr("EDITORA"));
    model->setHeaderData(5, Qt::Horizontal, tr("DISPONIVEIS"));
    model->setHeaderData(6, Qt::Horizontal, tr("COPIAS"));
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    ui->livros_tbw->setModel(model);
}

void telaListaLivros::on_cadNovo_btn_clicked()
{
    form4 = new telaCadastroLivro();
    this->close();
    form4->show();
}

void telaListaLivros::on_voltar_btn_clicked()
{
    form = new telaMainMenu(this);
    this->close();
    form->show();
}

telaListaLivros::~telaListaLivros()
{
    delete ui;
}





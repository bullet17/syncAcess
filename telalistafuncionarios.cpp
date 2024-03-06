#include "telalistafuncionarios.h"
#include "ui_telalistafuncionarios.h"
#include "armazenamento.h"
#include "telalogin.h"

telaListaFuncionarios::telaListaFuncionarios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telaListaFuncionarios)
{
    ui->setupUi(this);

    QString caminhoDoBanco = "C:/banco/biblioteca.db";

    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("users_tbl");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("NOME"));
    model->setHeaderData(2, Qt::Horizontal, tr("TELEFONE"));
    model->setHeaderData(3, Qt::Horizontal, tr("SENHA"));
    model->setHeaderData(4, Qt::Horizontal, tr("EMAIL"));
    model->setHeaderData(5, Qt::Horizontal, tr("ENDEREÇO"));

    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    ui->funcionarios_tbw->setModel(model);

    ui->funcionarios_tbw->setColumnHidden(3, true);
}

telaListaFuncionarios::~telaListaFuncionarios()
{
    delete ui;
}

void telaListaFuncionarios::on_voltar_btn_clicked()
{
    form = new telaMainMenu();
    this->close();
    form->show();
}


void telaListaFuncionarios::on_cadNovo_btn_clicked()
{
    form2 = new telaCadastroUser();
    this->close();
    form2->show();
}


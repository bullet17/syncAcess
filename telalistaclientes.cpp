#include "telalistaclientes.h"
#include "ui_telalistaclientes.h"
#include "armazenamento.h"
#include "telalogin.h"

telaListaClientes::telaListaClientes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telaListaClientes)
{
    ui->setupUi(this);

    QString caminhoDoBanco = "C:/banco/biblioteca.db";
    banco.setDatabaseName(caminhoDoBanco);
    banco.open();
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("clients_tbl");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("NOME"));
    model->setHeaderData(2, Qt::Horizontal, tr("IDADE"));
    model->setHeaderData(3, Qt::Horizontal, tr("DOCUMENTO"));
    model->setHeaderData(4, Qt::Horizontal, tr("TELEFONE"));
    model->setHeaderData(5, Qt::Horizontal, tr("ENDEREÇO"));
    model->setHeaderData(6, Qt::Horizontal, tr("EMAIL"));
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    ui->clientes_tbw->setModel(model);
}

void telaListaClientes::on_voltar_btn_clicked() {
    form = new telaMainMenu(this);
    this->close();
    form->show();
}

void telaListaClientes::on_cadNovo_btn_clicked() {
    form2 = new telaCadastroCliente(this);
    this->close();
    form2->show();
}

telaListaClientes::~telaListaClientes() {
    delete ui;
}

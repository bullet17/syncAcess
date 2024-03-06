#include "teladevolucao.h"
#include "ui_teladevolucao.h"
#include "telalogin.h"
#include "armazenamento.h"

telaDevolucao::telaDevolucao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telaDevolucao) {
    ui->setupUi(this);

    ui->clientes_cbox->addItem("Selecione o cliente...");
    ui->clientes_cbox->setItemData(0,Qt::ItemIsEnabled, Qt::UserRole - 1);

    QString caminhoDoBanco = "C:/banco/biblioteca.db";
    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QSqlQuery selectClientes;

    selectClientes.prepare("SELECT NOME_CLIENTE FROM clients_tbl");
    if(!selectClientes.exec()){
        qDebug() << "Error executing queryInsert:" << selectClientes.lastError().text();
    } else{
        while(selectClientes.next()){
            ui->clientes_cbox->addItem(selectClientes.value(0).toString());
        }
    }
    banco.close();
    ui->clienteEmp_tbw->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
}

void telaDevolucao::on_listar_bt_clicked() {
    QString nomeCliente = ui->clientes_cbox->currentText();
    QString idCliente = consultaIdClientePeloNome(nomeCliente);
    QVector<classEmprestimo> emprestimos = criaListaEmprestimosCliente(idCliente);
    int i = 0, cont = 0, tam = emprestimos.size();

    ui->clienteEmp_tbw->setRowCount(0);

    for(i=0; i<tam; i++) {
        bool devolvido = consultaSeDevolvido(emprestimos[i].IDemp);
        if (devolvido == false) {
        ui->clienteEmp_tbw->setRowCount(cont+1);
            QString ttl = emprestimos[i].tituloLivro;
            QString id = emprestimos[i].IDemp;
            QString dataEmp = emprestimos[i].dataEmp;
            QString dataLim = emprestimos[i].dataLim;
            ui->clienteEmp_tbw->setItem(cont,0,new QTableWidgetItem(ttl));
            ui->clienteEmp_tbw->setItem(cont,1,new QTableWidgetItem(id));
            ui->clienteEmp_tbw->setItem(cont,2,new QTableWidgetItem(dataEmp));
            ui->clienteEmp_tbw->setItem(cont,3,new QTableWidgetItem(dataLim));
            cont++;
        }
    }
    if (cont <= 0) {
        QMessageBox::about(this,"","Cliente não possui empréstimos ativos!");
    }
}

float calculaMulta (QDate dataLim) {
    QDate hoje(QDate::currentDate());

    float multa = (dataLim.daysTo(hoje)) * 0.50;

    return multa;
}

void telaDevolucao::on_devolverLivro_bt_clicked() {
   int row = ui->clienteEmp_tbw->currentRow();
   QString codEmp = ui->clienteEmp_tbw->item(row,1)->text();

   QString StgdataLim = consultaDataLimite(codEmp);
   QDate dataLim = QDate::fromString(StgdataLim,"dd.MM.yyyy");

   if (dataLim < QDate::currentDate()){
        float multa = calculaMulta(dataLim);
        QString stgmulta = QString::number(multa);
        QMessageBox::warning(this,"ATRASO","Devido ao atraso na devoluçao será cobrada uma multa de 50 centavos por dia de atraso. \n Sua multa totalizou R$"+stgmulta);
        QMessageBox::about(this,"DEVOLVIDO","Livro devolvido com sucesso! :)");
        armazenaDevolucao(codEmp);
   } else {
        QMessageBox::about(this,"DEVOLVIDO","Livro devolvido com sucesso! :)");
        armazenaDevolucao(codEmp);
   }

   QString nomeCliente = ui->clientes_cbox->currentText();
   QString idCliente = consultaIdClientePeloNome(nomeCliente);
   QVector<classEmprestimo> emprestimos = criaListaEmprestimosCliente(idCliente);
   int i = 0, cont = 0, tam = emprestimos.size();

   ui->clienteEmp_tbw->setRowCount(0);

   for(i=0; i<tam; i++) {
        bool devolvido = consultaSeDevolvido(emprestimos[i].IDemp);
        if (devolvido == false) {
            ui->clienteEmp_tbw->setRowCount(cont+1);
            QString ttl = emprestimos[i].tituloLivro;
            QString id = emprestimos[i].IDemp;
            QString dataEmp = emprestimos[i].dataEmp;
            QString dataLim = emprestimos[i].dataLim;
            ui->clienteEmp_tbw->setItem(cont,0,new QTableWidgetItem(ttl));
            ui->clienteEmp_tbw->setItem(cont,1,new QTableWidgetItem(id));
            ui->clienteEmp_tbw->setItem(cont,2,new QTableWidgetItem(dataEmp));
            ui->clienteEmp_tbw->setItem(cont,3,new QTableWidgetItem(dataLim));
            cont++;
        }
   }
}

void telaDevolucao::on_pushButton_clicked() {
    form = new telaMainMenu(this);
    this->close();
    form->show();
}

telaDevolucao::~telaDevolucao() {
    delete ui;
}




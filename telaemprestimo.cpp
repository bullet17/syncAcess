#include "telaemprestimo.h"
#include "ui_telaemprestimo.h"
#include "telalogin.h"
#include "armazenamento.h"
#include <QComboBox>
#include <QVBoxLayout>



telaEmprestimo::telaEmprestimo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telaEmprestimo)
{
    ui->setupUi(this);

    ui->livros_cbox->clear();
    ui->clientes_cbox->clear();

    ui->clientes_cbox->setFocus();
    QDate date = QDate::currentDate();
    ui->livros_cbox->addItem("Selecione o livro...");
    ui->livros_cbox->setItemData(0, Qt::ItemIsEnabled, Qt::UserRole - 1);
    ui->clientes_cbox->addItem("Selecione o cliente...");
    ui->clientes_cbox->setItemData(0,Qt::ItemIsEnabled, Qt::UserRole - 1);
    ui->emprestimo_date->setDate(date);

    QString caminhoDoBanco = "C:/banco/biblioteca.db";
    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QSqlQuery selectLivros;
    QSqlQuery selectClientes;

    selectLivros.prepare("SELECT TITULO_LIVRO FROM books_tbl");
    if(!selectLivros.exec()){
        qDebug() << "Error executing queryInsert:" << selectLivros.lastError().text();
    } else{
        while(selectLivros.next()){
            ui->livros_cbox->addItem(selectLivros.value(0).toString());
        }
    }
    selectClientes.prepare("SELECT NOME_CLIENTE FROM clients_tbl");
    if(!selectClientes.exec()){
        qDebug() << "Error executing queryInsert:" << selectClientes.lastError().text();
    } else{
        while(selectClientes.next()){
            ui->clientes_cbox->addItem(selectClientes.value(0).toString());
        }
    }
}

void telaEmprestimo::on_clientes_cbox_editTextChanged(const QString &arg1) {
    ui->livros_cbox->setFocus();
}

void telaEmprestimo::on_emprestimo_date_editingFinished() {
    ui->regsEmprestimo_bt->click();
}

void telaEmprestimo::on_regsEmprestimo_bt_clicked() {
    QString livroSelecionado = ui->livros_cbox->currentText();
    QString clienteSelecionado = ui->clientes_cbox->currentText();
    QDate dataEmp = ui->emprestimo_date->date();

    QString idCliente = consultaIdClientePeloNome(clienteSelecionado);
    QString idLivro = consultaIdLivroPeloTitulo(livroSelecionado);
    int quantDisponivel = consultaQuantDisponivel(idLivro);
    bool emprestimoDuplicado = consultaEmprestimoDuplo(idCliente, idLivro);
    bool emprestimoAtrasado = consultaLivroAtrasadoCliente(idCliente);

    if (emprestimoAtrasado == true){
        QMessageBox::warning(nullptr, "INDISPONÍVEL", "Usuário possui emprestimos em atraso! \nFavor resolver pendência antes de realizar outro emprestimo.");
    } else if (emprestimoDuplicado == true) {
        QMessageBox::warning(nullptr, "INDISPONÍVEL", "Usuário possui emprestimos ativos desse livro\nPermitido emprestimo apenas de uma cópia do mesmo livro por pessoa!");
    } else if (quantDisponivel <= 0) {
        QMessageBox::warning(this,"INDISPONÍVEL", "Infelizmente esse livro está indisponível no momento :/");
    } else {
        QString dataLim = armazenaEmprestimo(idLivro, idCliente, dataEmp);
        QMessageBox::about(this,"EMPRESTIMO", "Emprestimo realizado com sucesso!\nA data limite para devolução é "+dataLim);
        ui->clientes_cbox->setFocus();
        ui->clientes_cbox->setCurrentIndex(0);
        ui->livros_cbox->setCurrentIndex(0);
    }
}

void telaEmprestimo::on_pushButton_clicked() {
    form = new telaMainMenu(this);
    this->close();
    form->show();
}

telaEmprestimo::~telaEmprestimo() {
    delete ui;
}

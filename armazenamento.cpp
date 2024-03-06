#include "armazenamento.h"
#include <QMessageBox>

QString caminhoDoBanco = "C:/banco/biblioteca.db";

//FUNCTIONS TO STORE IN SQL DATABASE
//-----------------------------------------------------------------------------------------------//
//--------------------------------------- TABLE USERS_TBL ---------------------------------------//
QVector<classUsuario> criaListaUsuarios() {

    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QVector<classUsuario> usuariosCadastrados;
    classUsuario usuario;
    QSqlQuery queryCreate;
    QSqlQuery querySelect;

    int cont = 0;

    querySelect.prepare ("SELECT * FROM users_tbl");
    if (!banco.isOpen()) {
        QMessageBox::critical(nullptr,"","Erro ao abrir arquivo");
    } else {
        queryCreate.exec("CREATE TABLE IF NOT EXISTS users_tbl (ID_USUARIO TEXT PRIMARY KEY,NOME_USUARIO TEXT (50), TEL_USUARIO TEXT (20),SENHA_USUARIO TEXT (50),EMAIL_USUARIO TEXT);");
        if (querySelect.exec()) {
            while (querySelect.next()){
                usuario.id = querySelect.value(0).toInt();
                usuario.nome = querySelect.value(1).toString();
                usuario.telefone = querySelect.value(2).toString();
                usuario.senha = querySelect.value(3).toString();
                usuario.email = querySelect.value(4).toString();
                usuariosCadastrados.push_back(usuario);
                cont++;
            }
        } else {
            QMessageBox::critical(nullptr,"","Erro ao executar comando!");
        } banco.close();
    }
    return usuariosCadastrados;
}

bool armazenaUsuario(classUsuario usuarioCadastrado) {

    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QString idUserStg = QString::number(usuarioCadastrado.id);
    QSqlQuery queryCreate;
    QSqlQuery queryInsert;

    queryCreate.prepare("CREATE TABLE IF NOT EXISTS users_tbl (ID_USUARIO TEXT PRIMARY KEY,NOME_USUARIO TEXT (50), TEL_USUARIO TEXT (20),SENHA_USUARIO TEXT (50),EMAIL_USUARIO TEXT);");
    queryInsert.prepare("INSERT INTO users_tbl values('"+idUserStg+"','"+usuarioCadastrado.nome+"','"+usuarioCadastrado.telefone+"','"
                          +usuarioCadastrado.senha+"','"+usuarioCadastrado.email+"')");

    if (!queryCreate.exec()) {
        qDebug() << "Error executing query:" << queryCreate.lastError().text();
    }
    if (!queryInsert.exec()) {
        qDebug() << "Error executing query:" << queryInsert.lastError().text();
        return false;
    } else {
        return true;
    }
    banco.close();
}

QString consultaSenhaUsuario (QString idDigitado) {
    QString senhaUsuario;
    banco.setDatabaseName(caminhoDoBanco);
    banco.open();
    QSqlQuery queryCreate;
    QSqlQuery querySelect;
    queryCreate.prepare("CREATE TABLE IF NOT EXISTS users_tbl (ID_USUARIO TEXT PRIMARY KEY,NOME_USUARIO TEXT (50), TEL_USUARIO TEXT (20),SENHA_USUARIO TEXT (50),EMAIL_USUARIO TEXT);");
    querySelect.prepare("SELECT SENHA_USUARIO FROM users_tbl WHERE ID_USUARIO = '"+idDigitado+"'");

    if (!queryCreate.exec()) {
        qDebug() << "Error executing query:" << queryCreate.lastError().text();
    }
    if (!querySelect.exec()) {
        qDebug() << "Error executing query:" << querySelect.lastError().text();
    } else {
        querySelect.next();
        senhaUsuario = querySelect.value(0).toString();
    }
    return senhaUsuario;
}

QString consultaNomeUsuario (int idUsuario) {
    QString nomeUsuario;
    QString idStg = QString::number(idUsuario);
    banco.setDatabaseName(caminhoDoBanco);
    banco.open();
    QSqlQuery queryCreate;
    QSqlQuery querySelect;
    queryCreate.exec("CREATE TABLE IF NOT EXISTS users_tbl (ID_USUARIO TEXT PRIMARY KEY,NOME_USUARIO TEXT (50), TEL_USUARIO TEXT (20),SENHA_USUARIO TEXT (50),EMAIL_USUARIO TEXT);");
    querySelect.exec("SELECT NOME_USUARIO FROM users_tbl WHERE ID_USUARIO = '"+idStg+"'");

    if (!queryCreate.exec()) {
        qDebug() << "Error executing query:" << queryCreate.lastError().text();
    }
    if (!querySelect.exec()) {
        qDebug() << "Error executing query:" << querySelect.lastError().text();
    } else {
        querySelect.next();
        nomeUsuario = querySelect.value(0).toString();
    }
    return nomeUsuario;
}

int criaIdUsuario() {
    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QSqlQuery querySelect;
    querySelect.prepare("SELECT MAX(ID_USUARIO) FROM users_tbl");
    querySelect.next();
    int ultimoId = querySelect.value(0).toInt();
    int idGerado = ultimoId + 1;
    banco.close();
    return idGerado;
}

//-----------------------------------------------------------------------------------------------//
//--------------------------------------- TABLE BOOKS_TBL ---------------------------------------//

QVector<classLivro> criaListaLivros() {

    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QVector<classLivro> livrosCadastrados;
    classLivro livro;
    QSqlQuery queryCreate;
    QSqlQuery querySelect;

    int cont = 0;

    querySelect.prepare ("SELECT * FROM books_tbl");
    queryCreate.exec("CREATE TABLE IF NOT EXISTS books_tbl (ID_LIVRO TEXT(20) PRIMARY KEY,TITULO_LIVRO TEXT, AUTOR_LIVRO TEXT,ANO_LIVRO TEXT, EDIT_LIVRO TEXT, DISPONIVEL INTEGER, QUANT_TOTAL INTEGER);");
    if (querySelect.exec()) {
        while (querySelect.next()){
            livro.id = querySelect.value(0).toString();
            livro.titulo = querySelect.value(1).toString();
            livro.autor = querySelect.value(2).toString();
            livro.ano = querySelect.value(3).toString();
            livro.editora = querySelect.value(4).toString();
            livro.quantDisp = querySelect.value(5).toInt();
            livro.quantTotal = querySelect.value(5).toInt();
            livrosCadastrados.push_back(livro);
            cont++;
            }
        } else {
            QMessageBox::critical(nullptr,"","Erro ao executar comando!");
        }
    banco.close();
    return livrosCadastrados;
}

bool armazenaLivro(classLivro livroCadastrado) {
    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QString stgDispo = QString::number(livroCadastrado.quantDisp);
    QString stgTotal = QString::number(livroCadastrado.quantTotal);
    QSqlQuery queryCreate;
    QSqlQuery queryInsert;

    queryCreate.prepare("CREATE TABLE IF NOT EXISTS books_tbl (ID_LIVRO TEXT(20) PRIMARY KEY,TITULO_LIVRO TEXT, AUTOR_LIVRO TEXT,ANO_LIVRO TEXT, EDIT_LIVRO TEXT, DISPONIVEL INTEGER, QUANT_TOTAL INTEGER);");
    queryInsert.prepare("INSERT INTO books_tbl values('"+livroCadastrado.id+"','"+livroCadastrado.titulo+"','"+livroCadastrado.autor+"','"
                        +livroCadastrado.ano+"','"+livroCadastrado.editora+"',"+stgDispo+","+stgTotal+")");

    if (!queryCreate.exec()) {
        qDebug() << "Error executing query:" << queryCreate.lastError().text();
    }

    if (!queryInsert.exec()) {
        qDebug() << "Error executing query:" << queryInsert.lastError().text();
        return false;
    } else {
        return true;
    }
    banco.close();
}

QString consultaIdLivroPeloTitulo(QString tituloLivro){
    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QString idLivro;
    QSqlQuery querySelect;

    querySelect.prepare("SELECT ID_LIVRO FROM books_tbl where TITULO_LIVRO = '"+tituloLivro+"'");

    if(!querySelect.exec()){
        qDebug() << "Error executing querySelect:" << querySelect.lastError().text();
    } else {
        querySelect.next();
        idLivro = querySelect.value(0).toString();
    }

    banco.close();
    return idLivro;
}

//-----------------------------------------------------------------------------------------------//
//--------------------------------------- TABLE CLIENTS_TBL ---------------------------------------//

QVector<classCliente> criaListaClientes() {

    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QVector<classCliente> clientesCadastrados;
    classCliente cliente;
    QSqlQuery queryCreate;
    QSqlQuery querySelect;

    int cont = 0;

    querySelect.prepare ("SELECT * FROM clients_tbl");

    queryCreate.exec("CREATE TABLE IF NOT EXISTS clients_tbl(ID_CLIENTE TEXT PRIMARY KEY, NOME_CLIENTE TEXT(50), IDADE_CLIENTE TEXT(4), DOC_CLIENTE TEXT(20), TEL_CLIENTE TEXT(20), ENDERECO_USER TEXT, EMAIL_USER TEXT);");
    if (querySelect.exec()) {
        while (querySelect.next()){
            cliente.id = querySelect.value(0).toInt();
            cliente.nome = querySelect.value(1).toString();
            cliente.idade = querySelect.value(2).toString();
            cliente.documento = querySelect.value(3).toString();
            cliente.telefone = querySelect.value(4).toString();
            cliente.endereco = querySelect.value(5).toString();
            cliente.email = querySelect.value(6).toString();
            clientesCadastrados.push_back(cliente);
            cont++;
        }
    } else {
        QMessageBox::critical(nullptr,"","Erro ao executar comando!");
    }
    banco.close();
    return clientesCadastrados;
}

bool armazenaCliente(classCliente clienteCadastrado) {
    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QString idStg = QString::number(clienteCadastrado.id);
    QSqlQuery queryCreate;
    QSqlQuery queryInsert;

    queryCreate.prepare("CREATE TABLE IF NOT EXISTS clients_tbl(ID_CLIENTE TEXT PRIMARY KEY, NOME_CLIENTE TEXT(50), IDADE_CLIENTE TEXT(4), DOC_CLIENTE TEXT(20), TEL_CLIENTE TEXT(20), ENDERECO_USER TEXT, EMAIL_USER TEXT);");
    queryInsert.prepare("INSERT INTO clients_tbl values('"+idStg+"','"+clienteCadastrado.nome+"','"+clienteCadastrado.idade+"','"
                        +clienteCadastrado.documento+"','"+clienteCadastrado.telefone+"','"+clienteCadastrado.endereco+"','"+clienteCadastrado.email+"')");

    if (!queryCreate.exec()) {
        qDebug() << "Error executing queryCreate:" << queryCreate.lastError().text();
    }

    if (!queryInsert.exec()) {
        qDebug() << "Error executing queryInsert:" << queryInsert.lastError().text();
        return false;
    } else {
        return true;
    }
    banco.close();
}

int criaIdCliente() {
    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QSqlQuery querySelect;
    querySelect.prepare("SELECT MAX(ID_CLIENTE) FROM clients_tbl");
    querySelect.next();
    int ultimoId = querySelect.value(0).toInt();
    int idGerado = ultimoId + 1;
    banco.close();
    return idGerado;
}

QString consultaIdClientePeloNome(QString nomeCliente) {
    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QString idCliente;
    QSqlQuery querySelect;

    querySelect.prepare("SELECT ID_CLIENTE FROM clients_tbl where NOME_CLIENTE = '"+nomeCliente+"'");

    if(!querySelect.exec()){
        qDebug() << "Error executing querySelect:" << querySelect.lastError().text();
    } else {
        querySelect.next();
        idCliente = querySelect.value(0).toString();
    }

    banco.close();
    return idCliente;
}

//-----------------------------------------------------------------------------------------------//
//--------------------------------------- TABLE LEND_TBL ---------------------------------------//

QString armazenaEmprestimo(QString idLivro, QString idCliente, QDate dataEmp) {

    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QDate dataLim = dataEmp.addDays(15);
    QString dataEmp_stg = dataEmp.toString("dd.MM.yyyy");
    QString dataLim_stg = dataLim.toString("dd.MM.yyyy");
    QSqlQuery queryCreate;
    QSqlQuery queryInsert;
    QSqlQuery queryTiraCopia;

    queryCreate.exec("CREATE TABLE IF NOT EXISTS lend_tbl (ID_EMPRESTIMO INTEGER PRIMARY KEY AUTOINCREMENT, ID_LIVRO TEXT, ID_CLIENTE TEXT, DATA_EMPRESTIMO TEXT, DATA_LIMITE TEXT,DEVOLVIDO TEXT(1), DATA_DEVOLUCAO TEXT);");
    queryInsert.exec("INSERT INTO lend_tbl (ID_LIVRO, ID_CLIENTE, DATA_EMPRESTIMO, DATA_LIMITE, DEVOLVIDO) values('"+idLivro+"','"+idCliente+"','"+dataEmp_stg+"','"+dataLim_stg+"','N');");
    queryTiraCopia.exec("UPDATE books_tbl SET DISPONIVEL = (DISPONIVEL - 1) where ID_LIVRO = '"+idLivro+"'");

    banco.close();
    return dataLim_stg;
}

QVector<classEmprestimo> criaListaEmprestimosCliente(QString idCliente) {

    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QVector<classEmprestimo> emprestimos;
    classEmprestimo emprestimo;

    QVector<QString> empIdLivro;
    QVector<QString> empId;
    QVector<QString> empDataEmp;
    QVector<QString> empDataLim;
    QSqlQuery querySelectCliente;
    QSqlQuery querySelectLivroEmpID;
    QSqlQuery querySelectLivroEmpTitulo;
    QString IDcliente;

    int cont = 0, i = 0;

    querySelectLivroEmpID.exec("SELECT ID_LIVRO, ID_EMPRESTIMO, DATA_EMPRESTIMO, DATA_LIMITE FROM lend_tbl where ID_CLIENTE = '"+idCliente+"'");
    while (querySelectLivroEmpID.next()){
        QString id = querySelectLivroEmpID.value(0).toString();
        QString idEmp = querySelectLivroEmpID.value(1).toString();
        QString dataEmp = querySelectLivroEmpID.value(2).toString();
        QString dataLim = querySelectLivroEmpID.value(3).toString();
        empIdLivro.push_back(id);
        empId.push_back(idEmp);
        empDataEmp.push_back(dataEmp);
        empDataLim.push_back(dataLim);
        cont++;
    }

    for (i=0; i<cont; i++){
        querySelectLivroEmpTitulo.exec("SELECT TITULO_LIVRO from books_tbl where ID_LIVRO = '"+empIdLivro[i]+"'");
        querySelectLivroEmpTitulo.next();
        emprestimo.tituloLivro = querySelectLivroEmpTitulo.value(0).toString();
        emprestimo.IDemp = empId[i];
        emprestimo.dataEmp = empDataEmp[i];
        emprestimo.dataLim = empDataLim[i];
        emprestimos.push_back(emprestimo);
    }
    banco.close();
    return emprestimos;
}

bool consultaSeDevolvido(QString idEmp) {

    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QSqlQuery querySelectDevolvido;
    QString devolvido;
    bool retorno;

    querySelectDevolvido.exec("SELECT DEVOLVIDO FROM lend_tbl where ID_EMPRESTIMO = '"+idEmp+"'");
    querySelectDevolvido.next();
    devolvido = querySelectDevolvido.value(0).toString();

    if (devolvido == "N") {
        retorno = false;
    } else if (devolvido == "S") {
        retorno = true;
    } else {
        QMessageBox::critical(nullptr,"","Invalid content found in column on table lend_tbl!");
    }
    banco.close();
    return retorno;
}

QString consultaDataDevolucao(QString idEmp) {

    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QSqlQuery querySelectDevolucao;
    QString dataDevolucao;

    querySelectDevolucao.exec("SELECT DATA_DEVOLUCAO FROM lend_tbl where ID_EMPRESTIMO = '"+idEmp+"'");
    querySelectDevolucao.next();
    dataDevolucao = querySelectDevolucao.value(0).toString();

    banco.close();
    return dataDevolucao;
}

QString consultaDataLimite (QString idEmp) {

    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QSqlQuery querySelectDevolvido;
    QString dataLimite;

    querySelectDevolvido.exec("SELECT DATA_LIMITE FROM lend_tbl where ID_EMPRESTIMO = '"+idEmp+"'");
    querySelectDevolvido.next();
    dataLimite = querySelectDevolvido.value(0).toString();

    banco.close();
    return dataLimite;
}

int consultaQuantDisponivel(QString idLivro) {

    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QSqlQuery querySelect;
    int disponivel;

    querySelect.exec("SELECT DISPONIVEL FROM books_tbl WHERE ID_LIVRO = '"+idLivro+"'");
    querySelect.next();
    disponivel = querySelect.value(0).toInt();

    banco.close();
    return disponivel;
}

void armazenaDevolucao(QString idEmp) {

    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QSqlQuery queryRegDevolucao;
    QSqlQuery queryVoltaCopia;
    QSqlQuery querySelectLivro;
    QString IDlivro;
    QString dataDevolucao = QDate::currentDate().toString("dd.MM.yyyy");

    queryRegDevolucao.exec("UPDATE lend_tbl SET DEVOLVIDO = 'S', DATA_DEVOLUCAO = '"+dataDevolucao+"' WHERE ID_EMPRESTIMO = '"+idEmp+"';");
    querySelectLivro.exec ("SELECT ID_LIVRO FROM lend_tbl WHERE ID_EMPRESTIMO = '"+idEmp+"';");
    querySelectLivro.next();
    IDlivro = querySelectLivro.value(0).toString();
    queryVoltaCopia.prepare("UPDATE books_tbl SET DISPONIVEL = (DISPONIVEL + 1) WHERE ID_LIVRO = '"+IDlivro+"'");
    queryVoltaCopia.exec();

    banco.close();
}

bool consultaEmprestimoDuplo(QString idCliente, QString idLivro) {

    banco.setDatabaseName(caminhoDoBanco);
    banco.open();
    QSqlQuery queryPesquisaEmp;
    int emp;

    queryPesquisaEmp.exec("SELECT COUNT(*) FROM lend_tbl WHERE ID_LIVRO = '"+idLivro+"' and ID_CLIENTE = '"+idCliente+"' and DEVOLVIDO = 'N';");
    queryPesquisaEmp.next();
    emp = queryPesquisaEmp.value(0).toInt();

    if (emp <=0) {
        return false;
    } else {
        return true;
    }
    banco.close();
}

bool consultaLivroAtrasadoCliente(QString idCliente){

    banco.setDatabaseName(caminhoDoBanco);
    banco.open();

    QSqlQuery selectDataLimite;
    QSqlQuery selectQntEmpAberto;
    QString dataLimite;
    int contAux = 0;
    QDate hoje = QDate::currentDate();
    QDate dataLim;

    selectQntEmpAberto.exec("SELECT COUNT(*) FROM lend_tbl WHERE ID_CLIENTE ='"+idCliente+"' and DEVOLVIDO = 'N'");
    selectQntEmpAberto.next();
    int qnt = selectQntEmpAberto.value(0).toInt();

    int i;

    for (i=0;i<qnt;i++){
        selectDataLimite.exec("SELECT DATA_LIMITE FROM lend_tbl where ID_CLIENTE = '"+idCliente+"' and DEVOLVIDO = 'N'");
        selectDataLimite.next();
        dataLimite = selectDataLimite.value(0).toString();
        dataLim = QDate::fromString(dataLimite,"dd.MM.yyyy");

        if (dataLim < hoje) {
            contAux ++;
        }
    }
    if (contAux <= 0){
        return false;
    } else {
        return true;
    }
}

//functions to store in txt files

/*USED ON TELALOGIN.CPP
int pegaUsuarios() {

    int num_usuarios = 0;

    QFile arquivoUsuarios(":/files/files/usuarios.txt");

    arquivoUsuarios.open(QIODevice::ReadOnly | QIODevice::Text);

    if (!arquivoUsuarios.isOpen()) {
        QMessageBox::critical(nullptr,"","Erro ao abrir arquivo");
    } else {
        QString line;
        QTextStream in(&arquivoUsuarios);
        do {
            line = in.readLine();
            QStringList value = line.split(";");

            if (value.size() >= 5) {
                usuario.nome = value[0];
                usuario.id = value[1].toInt();
                usuario.senha = value[2];
                usuario.telefone = value[3];
                usuario.email = value[4];
                cadastrados.push_back(usuario);
            } else {
                break;
            }
            num_usuarios ++;
        } while(!in.atEnd());
    }

    arquivoUsuarios.close();
    return num_usuarios;
}

//USED ON TELACADASTROCLIENTE.CPP
void armazenamentoCliente() {

    QFile arquivoClientes(":/files/files/clientes.txt");

    arquivoClientes.open(QIODevice::WriteOnly);

    int i, tam = clientesLista.size();

    for (i=0; i<tam; i++) {
        if (arquivoClientes.isOpen()) {
            QTextStream in(&arquivoClientes);
            in << clientesLista[i].registro << ";" << clientesLista[i].nome << ";" << clientesLista[i].idade << ";" << clientesLista[i].telefone << ";"
               << clientesLista[i].email << ";" << clientesLista[i].endereco << clientesLista[i].documento << ";" << "\n";
        } else {
            QMessageBox::critical(nullptr,"File", "Erro ao abrir arquivo");
        }
    }
    arquivoClientes.close();
}

//USED ON TELACADASTROUSUARIO.CPP
void armazenamentoFunc() {

    QFile arquivoUsuarios(":/files/files/usuarios.txt");

    arquivoUsuarios.open(QIODevice::WriteOnly);

    int i;

    for (i=0; i<cadastrados.size(); i++) {
        if (arquivoUsuarios.isOpen()) {
            QTextStream in(&arquivoUsuarios);
            in << cadastrados[i].nome << ";" << cadastrados[i].id << ";" << cadastrados[i].senha << ";" << cadastrados[i].telefone << ";" << cadastrados[i].email << ";" << "\n";
        } else {
            QMessageBox::critical(nullptr,"File", "Erro ao abrir arquivo");
        }
    }
    arquivoUsuarios.close();
}

void armazenamentoLivro() {
    QFile arquivoLivros(":/files/files/livros.txt");

    arquivoLivros.open(QIODevice::WriteOnly);

    int i;

    for (i=0; i<prateleira.size(); i++) {
        if (arquivoLivros.isOpen()) {
            QTextStream in(&arquivoLivros);
            in << prateleira[i].cod << ";" << prateleira[i].titulo << ";" << prateleira[i].autor << ";" << prateleira[i].ano << ";" << prateleira[i].editora << ";"
               << prateleira[i].clas << ";" << prateleira[i].obs << ";" << "\n";
        } else {
            QMessageBox::critical(nullptr,"File", "Erro ao abrir arquivo");
        }
    }
    arquivoLivros.close();
}

int pegaLivros() {
    int num_livros = 0;

    QFile arquivoLivros(":/files/files/livros.txt");

    arquivoLivros.open(QIODevice::ReadOnly | QIODevice::Text);

    if (!arquivoLivros.isOpen()) {
        QMessageBox::critical(nullptr,"","Erro ao abrir arquivo");
    } else {
        QString line;
        QTextStream in(&arquivoLivros);
        do {
            line = in.readLine();
            QStringList value = line.split(";");

            if (value.size() >= 7) {
                livro.cod = value[0];
                livro.titulo = value[1];
                livro.autor = value[2];
                livro.ano = value[3];
                livro.editora = value[4];
                livro.clas = value[5];
                livro.obs = value[6];
                prateleira.push_back(livro);
            } else {
                break;
            }
            num_livros ++;
        } while(!in.atEnd());
    }

    arquivoLivros.close();
    return num_livros;
}*/

